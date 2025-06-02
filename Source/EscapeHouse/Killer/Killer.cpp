// Fill out your copyright notice in the Description page of Project Settings.


#include "Killer.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "KillerAiController.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AKiller::AKiller()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SightSource = CreateDefaultSubobject<USceneComponent>(TEXT("Sight Source"));
	SightSource->SetupAttachment(RootComponent);

	//AIControllerClass = AKillerAiController::StaticClass();

}

// Called when the game starts or when spawned
void AKiller::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKiller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	LookAtActor(PlayerCharacter);

}

// Called to bind functionality to input
void AKiller::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



void AKiller::LookAtActor(const AActor* TargetActor)
{
	if (TargetActor == nullptr) return;

	if (CanSeeActor(TargetActor))
	{
		FVector Start = GetActorLocation();
		FVector End = TargetActor->GetActorLocation();
		// Calculate the necessary rotation for the Start point to face the End point
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);

		//Set the enemy's rotation to that rotation
		SetActorRotation(LookAtRotation);
	}
}

bool AKiller::CanSeeActor(const AActor* TargetActor) const
{
	if (TargetActor == nullptr) return false;

	// Store the results of the Line Trace
	FHitResult Hit;

	// Where the Line Trace starts and ends
	FVector Start = SightSource->GetComponentLocation();
	FVector End = TargetActor->GetActorLocation();

	// The trace channel we want to compare against
	ECollisionChannel Channel = ECollisionChannel::ECC_GameTraceChannel1;

	FCollisionQueryParams QueryParams;
	// Ignore the actor that's executing this Line Trace
	QueryParams.AddIgnoredActor(this);
	// Ignore the target we're checking for
	QueryParams.AddIgnoredActor(TargetActor);

	// Execute the Line Trace
	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);

	// Show the Line Trace inside the game
	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	return !Hit.bBlockingHit;
}
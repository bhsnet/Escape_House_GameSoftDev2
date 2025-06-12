// Fill out your copyright notice in the Description page of Project Settings.


#include "Killer.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "KillerAiController.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

AKiller::AKiller()
{
 	// �� ������ Tick �Լ� ȣ�� ���. ���� ���Ͻ� ����
	//PrimaryActorTick.bCanEverTick = true;

	// �÷��̾� �ٶ󺸱⸦ ���� ������Ʈ (���� 5��
	SightSource = CreateDefaultSubobject<USceneComponent>(TEXT("Sight Source"));
	SightSource->SetupAttachment(RootComponent);

	//AIControllerClass = AKillerAiController::StaticClass();

}

void AKiller::BeginPlay()
{
	Super::BeginPlay();
	
}

void AKiller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//�÷��̾� ĳ���� �ٶ󺸱�
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	LookAtActor(PlayerCharacter);

}

void AKiller::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



void AKiller::LookAtActor(const AActor* TargetActor)
{
	if (TargetActor == nullptr) return;

	//CanSeeActor �Լ� ȣ��
	if (CanSeeActor(TargetActor))
	{
		FVector Start = GetActorLocation();
		FVector End = TargetActor->GetActorLocation();
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);

		//���� �����̼� ����
		SetActorRotation(LookAtRotation);
	}
}

bool AKiller::CanSeeActor(const AActor* TargetActor) const
{
	if (TargetActor == nullptr) return false;

	// ����Ʈ���̽� ����
	FHitResult Hit;

	// ����Ʈ���̽� ���۰� ��
	FVector Start = SightSource->GetComponentLocation();
	FVector End = TargetActor->GetActorLocation();

	// ä�� ����
	ECollisionChannel Channel = ECollisionChannel::ECC_GameTraceChannel1;

	FCollisionQueryParams QueryParams;

	// ����Ʈ���̽��� ���� ����
	QueryParams.AddIgnoredActor(this);
	QueryParams.AddIgnoredActor(TargetActor);

	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);

	// ����׿� �� ǥ��
	//DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	return !Hit.bBlockingHit;
}
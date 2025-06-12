// Fill out your copyright notice in the Description page of Project Settings.


#include "Killer.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "KillerAiController.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

AKiller::AKiller()
{
 	// 매 프레임 Tick 함수 호출 기능. 성능 저하시 끄기
	//PrimaryActorTick.bCanEverTick = true;

	// 플레이어 바라보기를 위한 컴포넌트 (교재 5장
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
	
	//플레이어 캐릭터 바라보기
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

	//CanSeeActor 함수 호출
	if (CanSeeActor(TargetActor))
	{
		FVector Start = GetActorLocation();
		FVector End = TargetActor->GetActorLocation();
		FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(Start, End);

		//액터 로테이션 설정
		SetActorRotation(LookAtRotation);
	}
}

bool AKiller::CanSeeActor(const AActor* TargetActor) const
{
	if (TargetActor == nullptr) return false;

	// 라인트레이스 변수
	FHitResult Hit;

	// 라인트레이스 시작과 끝
	FVector Start = SightSource->GetComponentLocation();
	FVector End = TargetActor->GetActorLocation();

	// 채널 설정
	ECollisionChannel Channel = ECollisionChannel::ECC_GameTraceChannel1;

	FCollisionQueryParams QueryParams;

	// 라인트레이스시 액터 무시
	QueryParams.AddIgnoredActor(this);
	QueryParams.AddIgnoredActor(TargetActor);

	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, Channel, QueryParams);

	// 디버그용 선 표시
	//DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	return !Hit.bBlockingHit;
}
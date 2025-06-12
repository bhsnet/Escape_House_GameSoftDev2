// Fill out your copyright notice in the Description page of Project Settings.


#include "KillerAiController.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "EscapeHouseCharacter.generated.h"

AKillerAiController::AKillerAiController()
{
	//PrimaryActorTick.bCanEverTick = true;
}

void AKillerAiController::BeginPlay()
{
    Super::BeginPlay();

	GetWorldTimerManager().SetTimer(MoveTimerHandle, this, &AKillerAiController::myMoveToActor, 0.5f, true);
}

void AKillerAiController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

void AKillerAiController::myMoveToActor()
{
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	MoveToActor(PlayerPawn, moveSpeed);
}
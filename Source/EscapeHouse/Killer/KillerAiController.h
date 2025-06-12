// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TimerManager.h"

#include "KillerAiController.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEHOUSE_API AKillerAiController : public AAIController
{
	GENERATED_BODY()
	

public:
	AKillerAiController();

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

	//이동속도 아님. AcceptanceRadius임.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	float	moveSpeed = 5.f;

	FTimerHandle MoveTimerHandle;

	void myMoveToActor();

};

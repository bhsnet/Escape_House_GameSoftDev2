// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	float	moveSpeed = 50.f;

//protected:
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
//	UBehaviorTree* mAITree;
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
//	UBlackboardData* mAIBlackboard;
//
//	virtual void OnPossess(APawn* aPawn) override;
//	virtual void OnUnPossess() override;
//
//public:
//	void SetBehaviorTree(const FString& Path);
//	void SetBlackboard(const FString& Path);


};

// Fill out your copyright notice in the Description page of Project Settings.


#include "KillerAiController.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "EscapeHouseCharacter.generated.h"

AKillerAiController::AKillerAiController()
{
	PrimaryActorTick.bCanEverTick = true;
}

//void AKillerAiController::OnPossess(APawn* aPawn)
//{
//	Super::OnPossess(aPawn);
//
//	if ((mAITree != nullptr) && (mAIBlackboard != nullptr))
//	{
//		UBlackboardComponent* BlackboardRef = Blackboard;
//		if (UseBlackboard(mAIBlackboard, BlackboardRef))
//		{
//			RunBehaviorTree(mAITree);
//		}
//	}
//}
//
//void AKillerAiController::OnUnPossess()
//{
//	Super::OnUnPossess();
//}
//
//void AKillerAiController::SetBehaviorTree(const FString& Path)
//{
//	mAITree = LoadObject<UBehaviorTree>(nullptr, *Path);
//}
//
//void AKillerAiController::SetBlackboard(const FString& Path)
//{
//	mAIBlackboard = LoadObject<UBlackboardData>(nullptr, *Path);
//}

void AKillerAiController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(this, 0);
	MoveToActor(PlayerPawn, moveSpeed);

}

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Killer.generated.h"

UCLASS()
class ESCAPEHOUSE_API AKiller : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = LookAt, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* SightSource;

public:
	AKiller();

protected:
	virtual void BeginPlay() override;

	// 플레이어 바라보기 (교재 5장
	void LookAtActor(const AActor* TargetActor);
	bool CanSeeActor(const AActor* TargetActor) const;

public:	

	//ACharacter 상속
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

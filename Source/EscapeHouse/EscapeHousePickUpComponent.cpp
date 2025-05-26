// Copyright Epic Games, Inc. All Rights Reserved.

#include "EscapeHousePickUpComponent.h"

UEscapeHousePickUpComponent::UEscapeHousePickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UEscapeHousePickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UEscapeHousePickUpComponent::OnSphereBeginOverlap);
}

void UEscapeHousePickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AEscapeHouseCharacter* Character = Cast<AEscapeHouseCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}

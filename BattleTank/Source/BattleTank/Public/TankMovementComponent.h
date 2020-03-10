// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrackMeshComponent;

/**
 * Moves Tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		void Initialise(UTankTrackMeshComponent* LeftTrackToSet, UTankTrackMeshComponent* RightTrackToSet);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void IntendMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = "Setup")
		void IntendTurnRight(float Throw);

private:
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;
	UTankTrackMeshComponent* LeftTrack;
	UTankTrackMeshComponent* RightTrack;
};

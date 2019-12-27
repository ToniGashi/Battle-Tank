// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATPlayerController : public APlayerController
{
	GENERATED_BODY()
private:
	ATank* GetControlledTank() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& a) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	UPROPERTY(EditAnywhere)
		double CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		double CrossHairYLocation = 0.333333; 
};

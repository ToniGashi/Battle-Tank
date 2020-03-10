// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"
#include "TPlayerController.generated.h"

class ATank;
class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank* GetControlledTank() const;
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimComp);

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& a);
	bool GetLookVectorHitLocation(FVector a, FVector& HitLocation);
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection);
	UPROPERTY(EditDefaultsOnly)
		double CrossHairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
		double CrossHairYLocation = 0.333333; 
	UPROPERTY(EditDefaultsOnly)
	int32 LineTraceRange = 1000000; // since unreal unit is in CM and we need it as 10km
};

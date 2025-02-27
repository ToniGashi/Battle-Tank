// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/World.h"
#include "TPlayerController.h"
#include "BattleTank.h"
#include "Blueprint/UserWidget.h"
#include "TankAimingComponent.h"
#include "Tank.h"

void ATPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if (AimingComponent)
		FoundAimingComponent(AimingComponent);
	else
		UE_LOG(LogTemp, Warning, TEXT("No Aiming Component found."));


}
void ATPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATPlayerController::GetControlledTank() const
{
	return (Cast<ATank>(GetPawn()));
}

void ATPlayerController::AimTowardsCrosshair()
{
	if (!ensure(GetControlledTank())) { return; }
	FVector HitLocation; //out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATPlayerController::GetSightRayHitLocation(FVector& HitLocation)
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenSize(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	FVector LookDirection;
	if(GetLookDirection(ScreenSize,LookDirection))
	{
		GetLookVectorHitLocation(LookDirection,HitLocation);
	}
	return true;
}

bool ATPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection)
{
	FVector CameraWorldLocation; // To be discarded
	return  DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}

bool ATPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation)
{
	FVector Start = PlayerCameraManager->GetCameraLocation();
	FVector End = Start+LookDirection* LineTraceRange;
	FHitResult HitResult;
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_Camera))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}



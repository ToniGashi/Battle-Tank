// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TPlayerController.h"

void ATPlayerController::BeginPlay()
{
	Super::BeginPlay();
	ATank* t1 = GetControlledTank();
	if (!t1)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Controlled tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("this is %s"), *(t1->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("Player Controller Here."));
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
	if (!GetControlledTank()) { return; }
	FVector HitLocation; //out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		/*UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());*/
	}
}

bool ATPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenSize(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	FVector LookDirection;
	if(GetLookDirection(ScreenSize,LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());
	}
	return true;
}

bool ATPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation;
	FVector WorldDirection;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, WorldDirection);
	LookDirection = WorldLocation;
	return true;
}

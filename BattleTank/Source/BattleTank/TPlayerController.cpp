// Fill out your copyright notice in the Description page of Project Settings.

#include "TPlayerController.h"
#include "BattleTank.h"
#include "Tank.h"

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
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}



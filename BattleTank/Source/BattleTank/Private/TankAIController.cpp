// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* t1 = GetPlayerTank();
	if (!t1)
	{
		UE_LOG(LogTemp, Warning, TEXT("No PlayerTank Found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found the player tank %s"), *(t1->GetName()));
	}
	UE_LOG(LogTemp, Warning, TEXT("Tank AI Controller here"));
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
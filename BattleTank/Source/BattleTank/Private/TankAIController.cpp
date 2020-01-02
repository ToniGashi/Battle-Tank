// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		auto AITank = GetControlledTank();
		AITank->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* t1 = GetControlledTank();
	if (!t1)
	{
		UE_LOG(LogTemp, Warning, TEXT("No AI Tank Found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found the AI tank %s"), *(t1->GetName()));
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
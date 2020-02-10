// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Tank.h"


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn()); // get player tank
	auto AIControlledTank = Cast<ATank>(GetPawn()); //gets controlled tank
	if (!(PlayerTank && AIControlledTank)) 
		{ return; }

	MoveToActor(PlayerTank, AcceptanceRadius);
	AIControlledTank->AimAt(PlayerTank->GetActorLocation());
	AIControlledTank->Fire();//not every fram
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}
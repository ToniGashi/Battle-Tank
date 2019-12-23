// Fill out your copyright notice in the Description page of Project Settings.


#include "TPlayerController.h"


ATank* ATPlayerController::GetControllerTank() const
{
	return (Cast<ATank>(GetPawn()));
}

// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "TankAIController.h"

void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"))


	auto ControlledTank = GetControlledTank(); // Creating a variable and inserting the currently controlled tank there

	if (!ControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayController not possessing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName())) // ControlledTank variable doesn't include the name, so you need to get it
	}
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}


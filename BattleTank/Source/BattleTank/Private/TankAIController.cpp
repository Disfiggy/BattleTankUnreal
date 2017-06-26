// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"))

		auto AIControlledTank = GetControlledTank(); // Creating a variable and inserting the currently controlled tank there

	if (!AIControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(AIControlledTank->GetName())) // ControlledTank variable doesn't include the name, so you need to get it
	}

	auto PlayerControlledTank = GetPlayerTank();

	if (!PlayerControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank %s"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: %s"), *(PlayerControlledTank->GetName()))
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}



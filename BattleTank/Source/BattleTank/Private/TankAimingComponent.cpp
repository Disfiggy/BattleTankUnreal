// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) 
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// Calculate the OutLaunchVelocity
	if (UGameplayStatics::SuggestProjectileVelocity
		(
			this,
			OutLaunchVelocity,
			StartLocation,
			HitLocation,
			LaunchSpeed,
			ESuggestProjVelocityTraceOption::DoNotTrace
			//FCollisionResponseParams::DefaultResponseParam,	// These three lines are for debugging to see the projectile trace
			//TArray<AActor *>(),
			//true
			)
		)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		// Move the barrel on the Y axis with the FRotator based on the crosshair
		// Whenever the aiming Y axis changes, move the barrel in the Y axis
		// Barrel should have some limits how much it can rotate

		// if the aiming position in Y changes
			//move the barrel in the Y axis along the aim position

		auto TankName = GetOwner()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *TankName, *AimDirection.ToString())
	}
	// if no solution found, do nothing
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) 
{
	// Work-out difference between current barrel rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	

	Barrel->Elevate(5); // TODO remove magic number
}

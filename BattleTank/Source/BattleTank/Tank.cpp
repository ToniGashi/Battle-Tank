#include "Tank.h"
#include "BattleTank.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s - Donkey: Tank C++ Construct"), *Name);
}

void ATank::BeginPlay()
{
	Super::BeginPlay();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s - Donkey: Tank C++ BeginPlay"), *Name);
	TankAimingComponent = FindComponentByClass<UTankAimingComponent>();
}
 
void ATank::Fire()
{
	bool isReloaded = ((FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds);
	if (isReloaded && LocalBarrel)
	{
		FVector NewProjectileLocation = LocalBarrel->GetSocketLocation("Projectile");
		FRotator NewProjectileRotation = LocalBarrel->GetSocketRotation("Projectile");
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBP, NewProjectileLocation, NewProjectileRotation);
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
}

void ATank::AimAt(FVector HitLocation)
{
	if (!ensure(TankAimingComponent)) return;
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}
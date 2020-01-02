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

	// No need to protect points as added at construction
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	LocalBarrel = BarrelToSet;
}

void ATank::SetTurretReferentce(UTankTurret* TankTurret)
{
	TankAimingComponent->SetTurretReference(TankTurret);
}

void ATank::Fire() const
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: FIRING!!!"), Time);
	if (!LocalBarrel) { return; }
	FVector NewProjectileLocation = LocalBarrel->GetSocketLocation("Projectile");
	FRotator NewProjectileRotation = LocalBarrel->GetSocketRotation("Projectile");
	GetWorld()->SpawnActor<AProjectile>(ProjectileBP, NewProjectileLocation, NewProjectileRotation);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}
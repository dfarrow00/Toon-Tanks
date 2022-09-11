// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySplashTank.h"
#include "SplashProjectile.h"

void AEnemySplashTank::Fire()
{
	ASplashProjectile* Projectile = GetWorld()->SpawnActor<ASplashProjectile>(ProjectileClass, ProjectileSpawnPoint->GetComponentLocation(), ProjectileSpawnPoint->GetComponentRotation());
	Projectile->SetOwner(this);
}
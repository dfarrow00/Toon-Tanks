// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyTank.h"
#include "EnemySplashTank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AEnemySplashTank : public AEnemyTank
{
	GENERATED_BODY()
	
private:
	//Fire class from BasePawn is overridden to allow for splash projectile to be spawned.
	void Fire() override;
};

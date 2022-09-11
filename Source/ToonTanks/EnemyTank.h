// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tower.h"
#include "EnemyTank.generated.h"

/**
 TODO: Make new child class that overrides Fire() to spawn splash projectile
 **/
UCLASS()
class TOONTANKS_API AEnemyTank : public ATower
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	bool InDetectionRange();
	void MoveToPlayer();

	UPROPERTY(EditDefaultsOnly)
	float DetectionRange = 400.0f;

	//The distance from the player tank where the enemy tank will stop getting closer.
	UPROPERTY(EditDefaultsOnly)
	float DistanceLimit = 50.0f;

	UPROPERTY(EditDefaultsOnly)
	float Speed = 75.0f;
};

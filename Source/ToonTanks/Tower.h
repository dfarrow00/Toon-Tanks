// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tower.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATower : public ABasePawn
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

	void HandleDestruction();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class ATank* Tank;//Refernce to player pawn

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRate = 2.0f;//Delay in seconds between each shot fired.

private:
	UPROPERTY(EditAnywhere, Category = "Combat")
	float FireRange = 300.0f;//Range in which the player tank must be in for the tower to shoot.

	FTimerHandle FireRateTimerHandle;

	void CheckFireCondition();
	bool InFireRange();
};

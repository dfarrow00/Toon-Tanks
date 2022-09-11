// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "SplashProjectile.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ASplashProjectile : public AProjectile
{
	GENERATED_BODY()

public:
	ASplashProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

	UPROPERTY(EditAnywhere)
	class UCapsuleComponent* HitRadius;
};

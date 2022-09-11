// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyTank.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void AEnemyTank::BeginPlay()
{
	Super::BeginPlay();

}

void AEnemyTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (InDetectionRange())
	{
		MoveToPlayer();
	}
}

//Checks if the player tank is in range to be moved to.
bool AEnemyTank::InDetectionRange()
{
	if (Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
		if (Distance <= DetectionRange && Distance >= DistanceLimit)
		{
			return true;
		}
	}
	return false;
}

void AEnemyTank::MoveToPlayer()
{
	//Moves tank forward.
	FVector DeltaLocation(0.0f);
	DeltaLocation.X = UGameplayStatics::GetWorldDeltaSeconds(this) * Speed;
	AddActorLocalOffset(DeltaLocation, true);

	//Rotates tank towards the player.
	FVector ToTarget = Tank->GetActorLocation() - GetActorLocation();//Destination - Start point = Vector from start to destination
	FRotator LookAtRotation = FRotator(0.0f, ToTarget.Rotation().Yaw, 0.0f);//Rotation of the vector only on Yaw.
	SetActorRotation(
		FMath::RInterpTo(
			GetActorRotation(),
			LookAtRotation,
			UGameplayStatics::GetWorldDeltaSeconds(this),
			1.0f));
}
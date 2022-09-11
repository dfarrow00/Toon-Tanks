// Fill out your copyright notice in the Description page of Project Settings.


#include "SplashProjectile.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

ASplashProjectile::ASplashProjectile()
{
	PrimaryActorTick.bCanEverTick = false;
	HitRadius = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Hit Radius"));
	HitRadius->SetupAttachment(ProjectileMesh);
}

void ASplashProjectile::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMesh->OnComponentHit.AddDynamic(this, &ASplashProjectile::OnHit);//Add SplashProjectile OnHit callback function to be called when projectile hits something.
}

void ASplashProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AActor* MyOwner = GetOwner();
	if (MyOwner == nullptr)
	{
		Destroy();
		return;
	}

	//Apply damage to all actors overlapping with the blast radius collision sphere.
	TArray<AActor*> HitActors;
	HitRadius->GetOverlappingActors(HitActors);
	for (AActor* HitActor : HitActors)
	{
		if (HitActor != this && HitActor != MyOwner)
		{
			UGameplayStatics::ApplyDamage(HitActor, Damage, MyOwner->GetInstigatorController(), this, UDamageType::StaticClass());//Appies damage to hit Actor.
		}
	}

	if (HitParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, HitParticles, GetActorLocation(), GetActorRotation());
	}
	if (HitSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
	}
	if (HitCameraShakeClass)
	{
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(HitCameraShakeClass);
	}

	Destroy();
}
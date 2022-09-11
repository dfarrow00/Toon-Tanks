// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanksGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API AToonTanksGameMode : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	void ActorDied(AActor* DeadActor);

	UFUNCTION(BlueprintCallable)
	int32 GetPlayerScore() const { return PlayerScore; };

	UFUNCTION(BlueprintCallable)
	int32 GetCurrentLevelMaxScore() const { return CurrentLevelMaxScore; };

	UFUNCTION(BlueprintCallable)
	void ResetPlayerScore();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void GameOver(bool bWonGame);

protected:
	virtual void BeginPlay() override;

	//Blueprint events cannot be private. Do not need a c++ function body, but can be called from c++.
	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

private:
	class ATank* Tank;
	class AToonTanksPlayerController* ToonTanksPlayerController;

	float StartDelay = 3.0f;//Delay before the game starts

	void HandleGameStart();

	int32 PlayerScore;//Stores the players current score.

	int32 CurrentLevelMaxScore;//Stores the maximum score possible for the current level.
};

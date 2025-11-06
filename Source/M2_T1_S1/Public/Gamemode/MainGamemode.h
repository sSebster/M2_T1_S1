// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Actors/BaseEntityPawn.h"
#include "MainGamemode.generated.h"

/**
 * 
 */
class FTimerManager;

UCLASS()
class M2_T1_S1_API AMainGamemode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Teams")
	TArray<ABaseEntityPawn*> Team1Entity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Teams")
	TArray<ABaseEntityPawn*> Team2Entity;

	

	int money=0;
	int LevelAdversary=1;
	int LevelPlayerATK=1;
	int LevelPlayerPV=1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	TMap<FName,int> AbilityMap;
	

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category="Spawn")
	float SpawnDelay;
	UPROPERTY()
	TArray<AActor*> spawnPoints;
	UPROPERTY(EditAnywhere, Category="Spawn")
	FName TagSpawnPoint;
	FTimerHandle SpawnTimer;
	void SpawnEntity();
	UPROPERTY(EditAnywhere, Category = "Spawn")
	TArray<TSubclassOf<ABaseEntityPawn>> EntitiesToSpawn;
	int index;
	UPROPERTY(EditAnywhere, Category = "SpawnPlayer")
	TArray<AActor*> spawnPointsPlayer;
	UPROPERTY(EditAnywhere, Category="SpawnPlayer")
	FName TagSpawnPointPlayer;
public:
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void upgradeAbility(FName AbilityName,int levelToAdd);
	UFUNCTION(BlueprintCallable, Category = "SpawnPlayer")
	void SpawnPlayerEntity(TSubclassOf<ABaseEntityPawn> entityToSpawn);
};

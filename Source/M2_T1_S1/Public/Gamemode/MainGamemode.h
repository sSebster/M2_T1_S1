// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Actors/BaseEntityPawn.h"
#include "MainGamemode.generated.h"

/**
 * 
 */
UCLASS()
class M2_T1_S1_API AMainGamemode : public AGameModeBase
{
	GENERATED_BODY()

	public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Teams")
	TArray<ABaseEntityPawn*> Team1Entity;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Teams")
	TArray<ABaseEntityPawn*> Team2Entity;

	int money;
	int LevelAdversary;
	int LevelPlayerATK;
	int LevelPlayerPV;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Abilities")
	UDataTable* DataTable;
};

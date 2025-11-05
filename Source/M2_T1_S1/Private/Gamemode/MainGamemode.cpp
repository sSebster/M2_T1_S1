// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemode/MainGamemode.h"

#include "Actors/SpawnPoint.h"
#include "Kismet/GameplayStatics.h"

void AMainGamemode::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(),ASpawnPoint::StaticClass(),TagSpawnPoint,spawnPoints);
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(),ASpawnPoint::StaticClass(),TagSpawnPointPlayer,spawnPointsPlayer);
	index=0;
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(
	SpawnTimer,
	this,
	&AMainGamemode::SpawnEntity,
	SpawnDelay,
	true
	);
	
}

void AMainGamemode::SpawnEntity()
{
	if (spawnPoints.IsEmpty()) return;
	if (spawnPoints.Num() > 1)
	{
		int32 IndexSpawnPoint = FMath::RandRange(0, spawnPoints.Num() - 1);
		AActor* ChosenPoint = spawnPoints[IndexSpawnPoint];
		FVector Location = ChosenPoint->GetActorLocation();
		FRotator Rotation = ChosenPoint->GetActorRotation();
		GetWorld()->SpawnActor<ABaseEntityPawn>(EntitiesToSpawn[index], Location, Rotation);
	}else
	{
		AActor* ChosenPoint = spawnPoints[0];
		FVector Location = ChosenPoint->GetActorLocation();
		FRotator Rotation = ChosenPoint->GetActorRotation();
		GetWorld()->SpawnActor<ABaseEntityPawn>(EntitiesToSpawn[index], Location, Rotation);
	}

	
	index++;
}

void AMainGamemode::SpawnPlayerEntity(TSubclassOf<ABaseEntityPawn> entityToSpawn)
{
	if (spawnPointsPlayer.IsEmpty()) return;
	if (spawnPointsPlayer.Num() > 1)
	{
		int32 IndexSpawnPoint = FMath::RandRange(0, spawnPointsPlayer.Num() - 1);
		AActor* ChosenPoint = spawnPointsPlayer[IndexSpawnPoint];
		FVector Location = ChosenPoint->GetActorLocation();
		FRotator Rotation = ChosenPoint->GetActorRotation();
		GetWorld()->SpawnActor<ABaseEntityPawn>(entityToSpawn, Location, Rotation);
	}else
	{
		AActor* ChosenPoint = spawnPointsPlayer[0];
		FVector Location = ChosenPoint->GetActorLocation();
		FRotator Rotation = ChosenPoint->GetActorRotation();
		GetWorld()->SpawnActor<ABaseEntityPawn>(entityToSpawn, Location, Rotation);
	}
}

void AMainGamemode::upgradeAbility(FName AbilityName, int levelToAdd)
{
	AbilityMap[AbilityName] += levelToAdd;
}

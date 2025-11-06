// Fill out your copyright notice in the Description page of Project Settings.


#include "Gamemode/MainGamemode.h"

#include "AIController.h"
#include "TimerManager.h"
#include "Actors/SpawnPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void AMainGamemode::BeginPlay()
{
	Super::BeginPlay();
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(),ASpawnPoint::StaticClass(),TagSpawnPoint,spawnPoints);
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(),ASpawnPoint::StaticClass(),TagSpawnPointPlayer,spawnPointsPlayer);
	index=0;
	GetWorld()->GetTimerManager().SetTimer(
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
		ABaseEntityPawn* EntitySpawned=GetWorld()->SpawnActor<ABaseEntityPawn>(EntitiesToSpawn[index], Location, Rotation);
		Team2Entity.Add(EntitySpawned);
		AAIController* AIController = Cast<AAIController>(EntitySpawned->GetController());
		UBlackboardComponent* blackbord=AIController->GetBlackboardComponent();
		blackbord->SetValueAsInt("Team",2);
	}else
	{
		AActor* ChosenPoint = spawnPoints[0];
		FVector Location = ChosenPoint->GetActorLocation();
		FRotator Rotation = ChosenPoint->GetActorRotation();
		ABaseEntityPawn* EntitySpawned=GetWorld()->SpawnActor<ABaseEntityPawn>(EntitiesToSpawn[index], Location, Rotation);
		Team2Entity.Add(EntitySpawned);
		AAIController* AIController = Cast<AAIController>(EntitySpawned->GetController());
		UBlackboardComponent* blackbord=AIController->GetBlackboardComponent();
		blackbord->SetValueAsInt("Team",2);
	}

	if(index >= EntitiesToSpawn.Num())
	{
		GetWorld()->GetTimerManager().ClearTimer(SpawnTimer);
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
		ABaseEntityPawn* EntitySpawned=GetWorld()->SpawnActor<ABaseEntityPawn>(entityToSpawn, Location, Rotation);
		Team1Entity.Add(EntitySpawned);
		AAIController* AIController = Cast<AAIController>(EntitySpawned->GetController());
		UBlackboardComponent* blackbord=AIController->GetBlackboardComponent();
		blackbord->SetValueAsInt("Team",1);
		
	}else
	{
		AActor* ChosenPoint = spawnPointsPlayer[0];
		FVector Location = ChosenPoint->GetActorLocation();
		FRotator Rotation = ChosenPoint->GetActorRotation();
		ABaseEntityPawn* EntitySpawned=GetWorld()->SpawnActor<ABaseEntityPawn>(entityToSpawn, Location, Rotation);
		Team1Entity.Add(EntitySpawned);
		AAIController* AIController = Cast<AAIController>(EntitySpawned->GetController());
		UBlackboardComponent* blackbord=AIController->GetBlackboardComponent();
		blackbord->SetValueAsInt("Team",1);
	}
}

void AMainGamemode::upgradeAbility(FName AbilityName, int levelToAdd)
{
	AbilityMap[AbilityName] += levelToAdd;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SpawnProjectilTask.h"

USpawnProjectilTask::USpawnProjectilTask()
{
	NodeName = TEXT("Spawn projectile");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type USpawnProjectilTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}


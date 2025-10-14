// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SpawnAOETask.h"

USpawnAOETask::USpawnAOETask()
{
	NodeName = TEXT("Spawn AOE");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type USpawnAOETask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

EBTNodeResult::Type USpawnAOETask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

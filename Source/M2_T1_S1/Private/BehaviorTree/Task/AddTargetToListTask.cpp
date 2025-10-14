// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/AddTargetToListTask.h"

UAddTargetToListTask::UAddTargetToListTask()
{
	NodeName = TEXT("Add target to list");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type UAddTargetToListTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

EBTNodeResult::Type UAddTargetToListTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

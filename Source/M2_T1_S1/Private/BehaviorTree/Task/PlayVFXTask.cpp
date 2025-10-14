// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/PlayVFXTask.h"

UPlayVFXTask::UPlayVFXTask()
{
	NodeName = TEXT("Play VFX");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type UPlayVFXTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

EBTNodeResult::Type UPlayVFXTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

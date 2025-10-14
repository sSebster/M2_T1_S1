// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/StartAbilityCDTask.h"

UStartAbilityCDTask::UStartAbilityCDTask()
{
	NodeName = TEXT("Start ability CD");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type UStartAbilityCDTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

EBTNodeResult::Type UStartAbilityCDTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}

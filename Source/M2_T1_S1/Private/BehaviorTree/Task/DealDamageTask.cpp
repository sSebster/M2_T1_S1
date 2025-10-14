// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/DealDamageTask.h"

UDealDamageTask::UDealDamageTask()
{
	NodeName = TEXT("Deal damage");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type UDealDamageTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}


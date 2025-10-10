// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SetATKTask.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type USetATKTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();

	BlackboardComp->SetValueAsFloat(FName("ATK"),AtkValue);
	return EBTNodeResult::Succeeded;
}

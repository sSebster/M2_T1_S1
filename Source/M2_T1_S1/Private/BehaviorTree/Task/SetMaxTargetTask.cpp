// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SetMaxTargetTask.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type USetMaxTargetTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;
	BlackboardComp->SetValueAsInt("MaxTarget", numberOfTarget);
	return EBTNodeResult::Succeeded;
}

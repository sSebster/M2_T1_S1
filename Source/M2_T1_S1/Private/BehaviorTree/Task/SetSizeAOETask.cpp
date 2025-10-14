// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SetSizeAOETask.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type USetSizeAOETask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;
	BlackboardComp->SetValueAsFloat("SizeAOE", sizeAOE);
	return EBTNodeResult::Succeeded;
}

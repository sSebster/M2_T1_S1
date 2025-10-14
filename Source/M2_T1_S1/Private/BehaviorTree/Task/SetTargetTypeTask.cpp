// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SetTargetTypeTask.h"

#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type USetTargetTypeTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;
	BlackboardComp->SetValueAsEnum("MaxTarget", static_cast<uint8>(TargetTypeToSet));
	return EBTNodeResult::Succeeded;
}

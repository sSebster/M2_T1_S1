// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/setRangeTask.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UsetRangeTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load blackboard"))
		return EBTNodeResult::Failed;
	}
	BlackboardComp->SetValueAsFloat("Range",Value);
	return EBTNodeResult::Succeeded;
}

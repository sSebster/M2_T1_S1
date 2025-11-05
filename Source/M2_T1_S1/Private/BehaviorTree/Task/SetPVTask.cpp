// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SetPVTask.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type USetPVTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load blackboard"))
		return EBTNodeResult::Failed;
	}
	BlackboardComp->SetValueAsFloat("PV",Value);
	return EBTNodeResult::Succeeded;
}

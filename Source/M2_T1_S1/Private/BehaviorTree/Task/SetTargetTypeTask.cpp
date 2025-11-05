// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SetTargetTypeTask.h"

#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type USetTargetTypeTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load blackboard"))
		return EBTNodeResult::Failed;
	}
	BlackboardComp->SetValueAsEnum("TargetType", static_cast<uint8>(TargetTypeToSet));
	return EBTNodeResult::Succeeded;
}

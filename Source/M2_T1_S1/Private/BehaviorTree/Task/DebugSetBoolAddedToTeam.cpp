// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/DebugSetBoolAddedToTeam.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UDebugSetBoolAddedToTeam::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load blackboard"))
		return EBTNodeResult::Failed;
	}
	BlackboardComp->SetValueAsBool("IsAddedToTeam",value);
	return EBTNodeResult::Succeeded;
}

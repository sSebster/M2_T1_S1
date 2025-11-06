// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/CheckTargetValidityTask.h"

#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UCheckTargetValidityTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp)
	{
		UE_LOG(LogTemp, Error, TEXT("CheckTargetValidityTask: Blackboard not found"));
		return EBTNodeResult::Failed;
	}

	AActor* CurrentTarget = Cast<AActor>(BlackboardComp->GetValueAsObject("CurrentTarget"));

	// Si le target est nullptr ou pending kill, il a été détruit
	if (!CurrentTarget || !IsValid(CurrentTarget))
	{
		BlackboardComp->SetValueAsBool("HasTarget", false);
		BlackboardComp->ClearValue("CurrentTarget");
		UE_LOG(LogTemp, Warning, TEXT("CheckTargetValidityTask: Target destroyed -> HasTarget set to false"));
		return EBTNodeResult::Succeeded;
	}

	// Sinon, la target est toujours valide
	BlackboardComp->SetValueAsBool("HasTarget", true);
	return EBTNodeResult::Succeeded;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/DealAOEDamageTask.h"
#include "Actors/BaseEntityPawn.h"
#include "AIControllers/BaseEntityAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UDealAOEDamageTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;
	ABaseEntityPawn* selfActor= Cast<ABaseEntityPawn>(BlackboardComp->GetValueAsObject("SelfActor"));
	if (selfActor == nullptr) return EBTNodeResult::Failed;
	ABaseEntityAIController* AIController=Cast<ABaseEntityAIController>(selfActor->GetController());
	if (AIController == nullptr) return EBTNodeResult::Failed;
	if (AIController->getTargets().IsEmpty()) return EBTNodeResult::Failed;
	for (ABaseEntityPawn* target : AIController->getTargets())
	{
		ABaseEntityAIController* AIControllerTarget= Cast<ABaseEntityAIController>(target->GetController());
		UBlackboardComponent* BlackboardComponentTarget = AIControllerTarget->GetBlackboardComponent();
		BlackboardComponentTarget->SetValueAsFloat("PV",BlackboardComponentTarget->GetValueAsFloat("PV") - Value);
	}
	
	return EBTNodeResult::Succeeded;
}

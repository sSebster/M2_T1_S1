// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/DealDamageTask.h"

#include "GameTargetType.h"
#include "Actors/BaseEntityPawn.h"
#include "AIControllers/BaseEntityAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UDealDamageTask::UDealDamageTask()
{
	NodeName = TEXT("Deal damage");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type UDealDamageTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load blackboard"))
		return EBTNodeResult::Failed;
	}
	ABaseEntityPawn* target = Cast<ABaseEntityPawn>(BlackboardComp->GetValueAsObject("CurrentTarget"));
	if (target == nullptr) return EBTNodeResult::Failed;
	ABaseEntityAIController* AIController = Cast<ABaseEntityAIController>(target->GetController());
	if (AIController == nullptr) return EBTNodeResult::Failed;
	UBlackboardComponent* targetBlackboard= AIController->GetBlackboardComponent();
	if (targetBlackboard == nullptr) return EBTNodeResult::Failed;
	targetBlackboard->SetValueAsFloat("PV",targetBlackboard->GetValueAsFloat("PV") - Value);
	return EBTNodeResult::Succeeded;
}


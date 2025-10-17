// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/StartAbilityCDTask.h"

#include "BehaviorTree/BlackboardComponent.h"

UStartAbilityCDTask::UStartAbilityCDTask()
{
	NodeName = TEXT("Start ability CD");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type UStartAbilityCDTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	TimerManager.SetTimer(
		timerCD,
		this,
		&UStartAbilityCDTask::onTimerFinished,
		duration
	);
	BlackboardComp->SetValueAsBool(FName("Ability"+FString::FromInt(AbilityAffectedByTimer)+"CD"),true);
	return EBTNodeResult::Succeeded;
}

void UStartAbilityCDTask::onTimerFinished()
{
	BlackboardComp->SetValueAsBool(FName("Ability"+FString::FromInt(AbilityAffectedByTimer)+"CD"),false);
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/StartAbilityCDTask.h"

#include "Actors/BaseEntityPawn.h"
#include "BehaviorTree/BlackboardComponent.h"

UStartAbilityCDTask::UStartAbilityCDTask()
{
	NodeName = TEXT("Start ability CD");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type UStartAbilityCDTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load blackboard"))
		return EBTNodeResult::Failed;
	}
	ABaseEntityPawn* selfActor= Cast<ABaseEntityPawn>(BlackboardComp->GetValueAsObject("SelfActor"));
	if (selfActor == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load actor"))
		return EBTNodeResult::Failed;
	}
	int localAbilityAffectedByTimer=AbilityAffectedByTimer;
	FTimerManager& TimerManager = GetWorld()->GetTimerManager();
	FTimerDelegate TimerDel;
	TimerDel.BindLambda([BlackboardComp, localAbilityAffectedByTimer]()
	{
		if (!BlackboardComp) return;

		BlackboardComp->SetValueAsBool(
			FName("Ability" + FString::FromInt(localAbilityAffectedByTimer) + "CD"),
			false
		);

		UE_LOG(LogTemp, Warning, TEXT("Cooldown ability %d terminé."), localAbilityAffectedByTimer);
	});
	TimerManager.SetTimer(
	selfActor->AbilitiesTimers[localAbilityAffectedByTimer - 1],
	TimerDel,
	duration,
	false // non looping
	);
	BlackboardComp->SetValueAsBool(FName("Ability"+FString::FromInt(AbilityAffectedByTimer)+"CD"),true);
	return EBTNodeResult::Succeeded;
}



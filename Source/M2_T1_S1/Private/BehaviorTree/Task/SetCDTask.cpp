// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SetCDTask.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "GameFramework/Actor.h"
#include "Engine/Engine.h"
#include "BehaviorTree/BehaviorTree.h"


USetCDTask::USetCDTask()
{
	NodeName = TEXT("Set Cooldown");
	// Task instantanée : pas de Tick
	bNotifyTick = false;
}

EBTNodeResult::Type USetCDTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AAIController* AICon = OwnerComp.GetAIOwner();
	APawn* AIPawn = AICon ? AICon->GetPawn() : nullptr;

	// Output Log
	UE_LOG(LogTemp, Log, TEXT("[USetCDTask] ExecuteTask - Controller:%s Pawn:%s BT:%s"),
		*GetNameSafe(AICon),
		*GetNameSafe(AIPawn),
		*GetNameSafe(OwnerComp.GetCurrentTree()));

	// Message écran (optionnel)
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1, 1.5f, FColor::Green,
			FString::Printf(TEXT("USetCDTask executed on %s"), *GetNameSafe(AIPawn))
		);
	}

	// Ici on ne fait rien d’autre : tâche terminée immédiatement
	return EBTNodeResult::Succeeded;
}
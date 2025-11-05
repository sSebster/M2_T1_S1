// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SetATKTask.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Gamemode/MainGamemode.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type USetATKTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load blackboard"))
		return EBTNodeResult::Failed;
	}
	BlackboardComp->SetValueAsFloat("ATK",Value);
	return EBTNodeResult::Succeeded;
}

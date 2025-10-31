// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SetMaxPV.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Gamemode/MainGamemode.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type USetMaxPV::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;
	BlackboardComp->SetValueAsFloat("MaxPV",Value);
	return EBTNodeResult::Succeeded;
}

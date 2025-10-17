// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AddTargetToListTask.generated.h"

/**
 * 
 */
class ABaseEntityPawn;
class AMainGamemode;

UCLASS()
class M2_T1_S1_API UAddTargetToListTask : public UBTTaskNode
{
	GENERATED_BODY()

	UAddTargetToListTask();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	TArray<ABaseEntityPawn*> getEnemyTeam(int myTeam,AMainGamemode* MainGamemode);
	
};

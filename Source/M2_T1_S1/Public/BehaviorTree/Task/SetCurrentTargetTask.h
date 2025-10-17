// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetCurrentTargetTask.generated.h"

class ABaseEntityPawn;
class AMainGamemode;
/**
 * 
 */
UCLASS()
class M2_T1_S1_API USetCurrentTargetTask : public UBTTaskNode
{
	GENERATED_BODY()
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	TArray<ABaseEntityPawn*> getEnemyTeam(int myTeam,AMainGamemode* MainGamemode);
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SpawnAOETask.generated.h"

/**
 * 
 */
UCLASS()
class M2_T1_S1_API USpawnAOETask : public UBTTaskNode
{
	GENERATED_BODY()

	USpawnAOETask();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};

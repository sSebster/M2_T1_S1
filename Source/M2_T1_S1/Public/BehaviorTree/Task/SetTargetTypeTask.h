// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "GameTargetType.h"
#include "SetTargetTypeTask.generated.h"

/**
 * 
 */
UCLASS()
class M2_T1_S1_API USetTargetTypeTask : public UBTTaskNode
{
	GENERATED_BODY()
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
public:
	UPROPERTY(EditAnywhere, Category = "Task")
	GameTargetType sizeAOE;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetCDTask.generated.h"

/**
 * 
 */
UCLASS()
class M2_T1_S1_API USetCDTask : public UBTTaskNode
{
	GENERATED_BODY()

public:
	USetCDTask();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category = "Config")
	float Cooldown = 2.0f;

	UPROPERTY(EditAnywhere, Category = "Config")
	FBlackboardKeySelector TargetKey;
	
};

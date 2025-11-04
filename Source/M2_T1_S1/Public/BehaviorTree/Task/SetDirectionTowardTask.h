// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetDirectionTowardTask.generated.h"

/**
 * 
 */
UCLASS()
class M2_T1_S1_API USetDirectionTowardTask : public UBTTaskNode
{
	GENERATED_BODY()
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector2f Direction= FVector2f(1,0);
};

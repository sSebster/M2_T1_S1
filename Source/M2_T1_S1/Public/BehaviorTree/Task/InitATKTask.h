// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "InitATKTask.generated.h"

/**
 * 
 */
UCLASS()
class M2_T1_S1_API UInitATKTask : public UBTTaskNode
{
	GENERATED_BODY()
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	bool AdversaryEntity=false;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "PlayAnimTask.generated.h"

/**
 * 
 */

class ABaseEntityPawn;

UCLASS()
class M2_T1_S1_API UPlayAnimTask : public UBTTaskNode
{
	GENERATED_BODY()

	UPlayAnimTask();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	UBlackboardComponent* BlackboardComp;
	UAnimInstance* AnimInstance;
	USkeletalMeshComponent* meshToAnimate;
	ABaseEntityPawn* targetActor;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* AnimationToPlay;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	FBlackboardKeySelector TargetKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	bool bWaitForCompletion = true;
	
};

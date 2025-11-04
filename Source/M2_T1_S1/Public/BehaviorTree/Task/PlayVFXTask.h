// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "PlayVFXTask.generated.h"

/**
 * 
 */
UCLASS()
class M2_T1_S1_API UPlayVFXTask : public UBTTaskNode
{
	GENERATED_BODY()

	UPlayVFXTask();
private:
	FVector VFXLocation = FVector::ZeroVector;
protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
	UParticleSystem* VFXToPlay;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
	FVector Scale = FVector(1.f);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
	FBlackboardKeySelector TargetKey;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
	FVector OffsetVF=FVector::ZeroVector;
};

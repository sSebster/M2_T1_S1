#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SetDirectionTowardTask.generated.h"

UCLASS()
class M2_T1_S1_API USetDirectionTowardTask : public UBTTaskNode
{
	GENERATED_BODY()

public:
	USetDirectionTowardTask();

protected:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	virtual void OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTNodeResult::Type TaskResult) override;

public:
	// Direction relative au Pawn (X = forward, Y = right)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector2f Direction = FVector2f(1, 0);

	// Vitesse de déplacement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Speed = 300.f; // unités par seconde
};

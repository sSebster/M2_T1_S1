// SpawnProjectilTask.h
#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SpawnProjectilTask.generated.h"

class ABaseProjectile;

UCLASS()
class M2_T1_S1_API USpawnProjectilTask : public UBTTaskNode
{
	GENERATED_BODY()
    
public:
	USpawnProjectilTask();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	UPROPERTY(EditAnywhere, Category="Projectile")
	TSubclassOf<ABaseProjectile> Projectile;

	UPROPERTY(EditAnywhere, Category="Projectile")
	UCurveFloat* DamageCurve;
	
	UPROPERTY(EditAnywhere, Category="Projectile")
	bool bOrientToTarget = false;
};

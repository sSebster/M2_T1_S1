// SpawnProjectilTask.cpp
#include "BehaviorTree/Task/SpawnProjectilTask.h"
#include "Actors/BaseEntityPawn.h"
#include "Actors/BaseProjectile.h"
#include "Kismet/KismetMathLibrary.h"
#include "BehaviorTree/BlackboardComponent.h"

USpawnProjectilTask::USpawnProjectilTask()
{
	NodeName = TEXT("Spawn projectile");
}

EBTNodeResult::Type USpawnProjectilTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComp)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load blackboard"));
		return EBTNodeResult::Failed;
	}

	ABaseEntityPawn* SelfActor = Cast<ABaseEntityPawn>(BlackboardComp->GetValueAsObject("SelfActor"));
	if (!SelfActor) return EBTNodeResult::Failed;

	FVector SpawnLocation = SelfActor->GetActorLocation() + SelfActor->ProjectileSpawnLocationOffset;
	FRotator SpawnRotation = SelfActor->GetActorRotation() + SelfActor->ProjectileSpawnRotationOffset;

	if (bOrientToTarget)
	{
		AActor* TargetActor = Cast<AActor>(BlackboardComp->GetValueAsObject("CurrentTarget"));
		if (TargetActor)
		{
			SpawnRotation = SpawnRotation = UKismetMathLibrary::FindLookAtRotation(SpawnLocation, TargetActor->GetActorLocation());
		}
	}

	ABaseProjectile* ProjectileSpawned = GetWorld()->SpawnActor<ABaseProjectile>(Projectile, SpawnLocation, SpawnRotation);
	if (!ProjectileSpawned) return EBTNodeResult::Failed;

	ProjectileSpawned->Damages = DamageCurve->GetFloatValue(BlackboardComp->GetValueAsFloat("ATK"));
	ProjectileSpawned->ownerProjectile = SelfActor;
	ProjectileSpawned->team = BlackboardComp->GetValueAsInt("Team");

	return EBTNodeResult::Succeeded;
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/SpawnProjectilTask.h"

#include "Actors/BaseEntityPawn.h"
#include "Actors/BaseProjectile.h"
#include "BehaviorTree/BlackboardComponent.h"

USpawnProjectilTask::USpawnProjectilTask()
{
	NodeName = TEXT("Spawn projectile");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type USpawnProjectilTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load blackboard"))
		return EBTNodeResult::Failed;
	}
	ABaseEntityPawn* selfActor=Cast<ABaseEntityPawn>(BlackboardComp->GetValueAsObject("SelfActor"));
	FVector Location = selfActor->GetActorLocation()+selfActor->ProjectileSpawnLocationOffset;
	FRotator Rotation = selfActor->GetActorRotation()+selfActor->ProjectileSpawnRotationOffset;
	ABaseProjectile* ProjectileSpawned=GetWorld()->SpawnActor<ABaseProjectile>(Projectile, Location, Rotation);
	if (ProjectileSpawned == nullptr) return EBTNodeResult::Failed;
	ProjectileSpawned->Damages = DamageCurve->GetFloatValue(BlackboardComp->GetValueAsFloat("ATK"));
	return EBTNodeResult::Succeeded;
}


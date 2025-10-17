// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/AddTargetToListTask.h"

#include "Actors/BaseEntityPawn.h"
#include "AIControllers/BaseEntityAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Gamemode/MainGamemode.h"
#include "Kismet/GameplayStatics.h"


UAddTargetToListTask::UAddTargetToListTask()
{
	NodeName = TEXT("Add target to list");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}

EBTNodeResult::Type UAddTargetToListTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr) return EBTNodeResult::Failed;

	ABaseEntityPawn* currentTarget = Cast<ABaseEntityPawn>(BlackboardComp->GetValueAsObject("CurrentTarget"));
	if (currentTarget == nullptr) return EBTNodeResult::Failed;
	
	ABaseEntityPawn* Entity = Cast<ABaseEntityPawn>(BlackboardComp->GetValueAsObject(FName("SelfActor")));
	if (Entity == nullptr) return EBTNodeResult::Failed;
	ABaseEntityAIController* AIController = Cast<ABaseEntityAIController>(Entity->GetController());
	if (AIController == nullptr) return EBTNodeResult::Failed;
	UWorld* World = OwnerComp.GetWorld();
	if (World == nullptr) return EBTNodeResult::Failed;
	AMainGamemode* MainGamemode = Cast<AMainGamemode>(UGameplayStatics::GetGameMode(World));
	if (MainGamemode == nullptr) return EBTNodeResult::Failed;
	int currentTeam= BlackboardComp->GetValueAsInt(FName("Team"));
	float SizeAOE = BlackboardComp->GetValueAsFloat(FName("SizeAOE"));
	
	for (ABaseEntityPawn* Element : getEnemyTeam(currentTeam, MainGamemode))
	{
		float distance = Element->GetDistanceTo(currentTarget);
		if (distance< SizeAOE)
		{
			AIController->AddTargetToList(Element);
		}
	}
	
	
	return EBTNodeResult::Succeeded;
}

TArray<ABaseEntityPawn*> UAddTargetToListTask::getEnemyTeam(int myTeam, AMainGamemode* MainGamemode)
{
	if (myTeam == 1)
	{
		return MainGamemode->Team2Entity;
	}
	return MainGamemode->Team1Entity; 
}

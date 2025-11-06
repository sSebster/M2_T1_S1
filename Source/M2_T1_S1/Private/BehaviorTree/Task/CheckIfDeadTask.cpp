// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/CheckIfDeadTask.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Gamemode/MainGamemode.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type UCheckIfDeadTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load blackboard"))
		return EBTNodeResult::Failed;
	}
	UWorld* World = GetWorld();
	if (World == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load world"))
	}
	AMainGamemode* MainGamemode = Cast<AMainGamemode>(UGameplayStatics::GetGameMode(World));
	if (MainGamemode == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load gamemode"))
	}
	
	
	float pv= BlackboardComp->GetValueAsFloat("PV");
	if (pv <= 0)
	{
		if (BlackboardComp->GetValueAsInt("Team") == 1)
		{
			MainGamemode->Team1Entity.Remove(Cast<ABaseEntityPawn>(BlackboardComp->GetValueAsObject("SelfActor")));
		}else
		{
			MainGamemode->Team2Entity.Remove(Cast<ABaseEntityPawn>(BlackboardComp->GetValueAsObject("SelfActor")));
		}
		Cast<ABaseEntityPawn>(BlackboardComp->GetValueAsObject("SelfActor"))->Destroy();
	}
	return EBTNodeResult::Succeeded;
}

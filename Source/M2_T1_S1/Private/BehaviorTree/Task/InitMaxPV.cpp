// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/InitMaxPV.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Gamemode/MainGamemode.h"
#include "Kismet/GameplayStatics.h"

EBTNodeResult::Type UInitMaxPV::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	if (BlackboardComp == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load blackboard"))
		return EBTNodeResult::Failed;
	}
	UCurveFloat* PvCurve = Cast<UCurveFloat>(BlackboardComp->GetValueAsObject(FName("CurvePV"))) ;
	if (PvCurve == nullptr) return EBTNodeResult::Failed;
	UWorld* World = OwnerComp.GetWorld();
	if (World == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load world"))
		return EBTNodeResult::Failed;
	}
	AMainGamemode* MainGamemode = Cast<AMainGamemode>(UGameplayStatics::GetGameMode(World));
	if (MainGamemode == nullptr)
	{
		UE_LOG(LogTemp,Error,TEXT("failed to load gamemode"))
		return EBTNodeResult::Failed;
	}
	if (AdversaryEntity)
	{
		BlackboardComp->SetValueAsFloat(FName("MaxPV"),PvCurve->GetFloatValue(MainGamemode->LevelAdversary));
	}else
	{
		BlackboardComp->SetValueAsFloat(FName("MaxPV"),PvCurve->GetFloatValue(MainGamemode->LevelPlayerPV));
	}
	
	return EBTNodeResult::Succeeded;
}

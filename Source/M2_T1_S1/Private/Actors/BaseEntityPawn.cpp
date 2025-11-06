// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseEntityPawn.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Gamemode/MainGamemode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseEntityPawn::ABaseEntityPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Visual = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Visuel"));
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("pawnFloatingMovement"));
	
}


void ABaseEntityPawn::InitAbilityTimers()
{
	AbilitiesTimers.Empty();
	AbilitiesTimers.SetNum(numbersOfAbilities);
}

// Called when the game starts or when spawned
void ABaseEntityPawn::BeginPlay()
{
	Super::BeginPlay();
	InitAbilityTimers();
	FTimerHandle DeathCheckTimer;
	GetWorldTimerManager().SetTimer(DeathCheckTimer, this, &ABaseEntityPawn::enableDeath, 0.5f, false);
	
}

// Called every frame
void ABaseEntityPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (canDie)
	{
		const float PV = BlackboardComp->GetValueAsFloat("PV");
		if (PV <= 0.f)
		{
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
			if (BlackboardComp->GetValueAsInt("GetValueAsFloat") == 1)
			{
				MainGamemode->Team1Entity.Remove(this);
			}else
			{
				MainGamemode->Team2Entity.Remove(this);
			}
			Destroy();
		}
	}
	
	
}

// Called to bind functionality to input
void ABaseEntityPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseEntityPawn::enableDeath()
{
	canDie=true;
	AAIController* AIController = Cast<AAIController>(GetController());
	if (!AIController) return;
	BlackboardComp = AIController->GetBlackboardComponent();
	if (!BlackboardComp) return;
}




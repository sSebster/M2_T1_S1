// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseEntityPawn.h"

// Sets default values
ABaseEntityPawn::ABaseEntityPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Visual = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Visuel"));
	
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
	
}

// Called every frame
void ABaseEntityPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseEntityPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}




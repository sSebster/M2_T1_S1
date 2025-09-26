// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/BaseAOEPawn.h"

// Sets default values
ABaseAOEPawn::ABaseAOEPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseAOEPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseAOEPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseAOEPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


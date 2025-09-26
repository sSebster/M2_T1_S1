// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/AdversaryPawn.h"

// Sets default values
AAdversaryPawn::AAdversaryPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAdversaryPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAdversaryPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAdversaryPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


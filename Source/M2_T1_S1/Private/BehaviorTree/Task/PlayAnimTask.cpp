// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/PlayAnimTask.h"

UPlayAnimTask::UPlayAnimTask()
{
	NodeName = TEXT("Play animation");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTree/Task/AddTargetToListTask.h"

UAddTargetToListTask::UAddTargetToListTask()
{
	NodeName = TEXT("Add target to list");
	// Task instantanée : pas de Tick ?
	//bNotifyTick = false;
}
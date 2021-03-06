// Fill out your copyright notice in the Description page of Project Settings.

#include "StateBase.h"
#include "CustomComponents/IState.h"
#include "ParkourCharacter.h"

// Sets default values for this component's properties
UStateBase::UStateBase()
{
	// Do not want state to be ticking from the get go - only when needed
	PrimaryComponentTick.bCanEverTick = false;

	Owner = Cast<AParkourCharacter>(GetOwner());
}

void UStateBase::OnEnter()
{
}

void UStateBase::OnExit()
{
}

void UStateBase::Update(float DeltaTime)
{
}


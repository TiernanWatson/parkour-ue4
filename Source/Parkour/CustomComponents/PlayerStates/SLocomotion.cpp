// Fill out your copyright notice in the Description page of Project Settings.

#include "SLocomotion.h"
#include "ParkourCharacter.h"

// Sets default values for this component's properties
USLocomotion::USLocomotion()
{
}

void USLocomotion::OnEnter()
{
	Owner->bAllowCrouch = true;
}

void USLocomotion::OnExit()
{
	Owner->bAllowCrouch = false;
}

void USLocomotion::Update(float DeltaTime)
{
	
}

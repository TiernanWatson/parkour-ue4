// Copyright Tiernan Watson 2019.  All Rights Reserved.

#include "LedgeClimbing.h"
#include "ParkourCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void ULedgeClimbing::OnEnter()
{
	Super::OnEnter();

	Owner->bCanMove = false;
	Owner->bIsHanging = true;

	// Stops player falling under the effects of gravity
	Owner->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);
	Owner->GetCharacterMovement()->StopMovementImmediately();
}

void ULedgeClimbing::OnExit()
{
	Super::OnExit();

	Owner->bCanMove = true;
	Owner->bIsHanging = false;
}

void ULedgeClimbing::Update(float DeltaTime)
{
	Super::Update(DeltaTime);


}

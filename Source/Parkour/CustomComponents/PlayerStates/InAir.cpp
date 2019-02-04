// Copyright Tiernan Watson 2019.  All Rights Reserved.

#include "InAir.h"
#include "ParkourCharacter.h"
#include "Engine/World.h"
#include "CustomComponents/StateMachine.h"
#include "Components/CapsuleComponent.h"

void UInAir::OnEnter()
{
	Super::OnEnter();
}

void UInAir::OnExit()
{
	Super::OnExit();
}

void UInAir::Update(float DeltaTime)
{
	Super::Update(DeltaTime);

	if (Owner->IsGrounded())
	{
		Owner->StateMachine->GoToState(FName("Locomotion"));
		return;
	}

	FindLedges();
}

void UInAir::FindLedges()
{
	FHitResult HHit, VHit;
	FVector Start = Owner->GetActorLocation();
	FVector End = Start + Owner->GetActorForwardVector() * 150.f;

	FCollisionShape shape;
	shape.SetSphere(100.f);

	// Check for ledges
	if (GetWorld()->SweepSingleByChannel(HHit, Start, End, FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel1, shape))
	{
		UE_LOG(LogTemp, Warning, TEXT("Found a ledge :)"));

		End = Owner->GetActorLocation() 
			+ Owner->GetActorForwardVector() * 100.f;

		Start = End + Owner->GetActorUpVector() * Owner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();

		if (GetWorld()->SweepSingleByChannel(VHit, Start, End, FQuat::Identity, ECollisionChannel::ECC_GameTraceChannel1, shape)) 
		{
			FVector NewLocation(HHit.ImpactPoint.X, HHit.ImpactPoint.Y, VHit.ImpactPoint.Z);
			FRotator Rotation = (-HHit.Normal).Rotation();

			UE_LOG(LogTemp, Warning, TEXT("Found a ledge 2! at %s"), *FString(NewLocation.ToString()));

			Owner->SetActorLocationAndRotation(NewLocation, Rotation.Quaternion());
			Owner->StateMachine->GoToState(FName("LedgeClimbing"));
		}
	}
}

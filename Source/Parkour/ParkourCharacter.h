// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
// Extended by Tiernan Watson 2019

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ParkourCharacter.generated.h"

UCLASS(config=Game)
class AParkourCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AParkourCharacter();

	/** State machine controlling player's abilities **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StateControl, meta = (AllowPrivateAccess = "true"))
	class UStateMachine* StateMachine;

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/** If false, player cannot move with move forward/right input **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bCanMove;

	/** If true, the character has the ability to crouch **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	bool bAllowCrouch;

	/** If true, character is hanging on a ledge **/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	bool bIsHanging;

protected:
	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** Wrapper to allow character to crouch with input **/
	void TryCrouch();

	/** Uncrouches the character if crouching **/
	void TryUnCrouch();

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void SetGravityScale(float Value);

	bool IsGrounded();

	virtual bool CanCrouch() override;

};

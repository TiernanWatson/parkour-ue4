// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IState.generated.h"

/**
 * Abstract class used to implement states for state machine
 */
UINTERFACE(BlueprintType)
class PARKOUR_API UState : public UInterface
{
	GENERATED_BODY()
};

class PARKOUR_API IState
{
	GENERATED_BODY()

public:
	virtual void OnEnter() = 0;

	virtual void OnExit() = 0;

	virtual void Update(float DeltaTime) = 0;
};

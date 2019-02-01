// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomComponents/StateBase.h"
#include "SLocomotion.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PARKOUR_API USLocomotion : public UStateBase
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USLocomotion();

	virtual void OnEnter() override;

	virtual void OnExit() override;

	virtual void Update(float DeltaTime) override;
		
};

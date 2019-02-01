// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CustomComponents/IState.h"
#include "StateBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PARKOUR_API UStateBase : public UActorComponent, public IState
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStateBase();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	class AParkourCharacter* Owner;

public:	
	// Called once when state machine switches to this state
	virtual void OnEnter() override;

	// Called once when state machine leaves this state
	virtual void OnExit() override;

	// Called once every frame if state machine is ticking
	virtual void Update(float DeltaTime) override;
		
};

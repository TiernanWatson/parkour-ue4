// Fill out your copyright notice in the Description page of Project Settings.

#include "StateMachine.h"
#include "CustomComponents/IState.h"

// Sets default values for this component's properties
UStateMachine::UStateMachine()
{
	// We want the state machine to tick naturally but this can be turned off
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UStateMachine::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UStateMachine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (State)
		State->Update(DeltaTime);
	else
		UE_LOG(LogTemp, Warning, TEXT("No state currently active in State Machine"));
}

void UStateMachine::GoToState(IState* State)
{
	UStateMachine::State = State;
}


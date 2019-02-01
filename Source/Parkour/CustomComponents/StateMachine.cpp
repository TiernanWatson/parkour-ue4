// Fill out your copyright notice in the Description page of Project Settings.

#include "StateMachine.h"
#include "CustomComponents/IState.h"
#include "Containers/Map.h"

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

void UStateMachine::GoToState(FName Name)
{
	if (State)
		State->OnExit();

	State = *AllStates.Find(Name);

	if (State == nullptr) 
	{
		UE_LOG(LogTemp, Error, TEXT("State not found. Returning."));
		return;
	}

	State->OnEnter();
}

void UStateMachine::AddState(FName Name, IState * State)
{
	AllStates.Add(Name, State);
}


// Copyright Tiernan Watson 2019.  All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CustomComponents/StateBase.h"
#include "InAir.generated.h"

/**
 * 
 */
UCLASS()
class PARKOUR_API UInAir : public UStateBase
{
	GENERATED_BODY()
	
	virtual void OnEnter() override;

	virtual void OnExit() override;

	virtual void Update(float DeltaTime) override;

	void FindLedges();

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ShootableTarget.generated.h"

class APlayerController;
// This class does not need to be modified.
UINTERFACE(MinimalAPI, Blueprintable)
class UShootableTarget : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class CONDITIONALTARGETS_API IShootableTarget
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual bool TestIfCanBeShot(APlayerController* ShooterController) = 0;
};

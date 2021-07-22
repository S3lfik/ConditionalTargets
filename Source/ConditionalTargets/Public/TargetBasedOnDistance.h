// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TargetBase.h"
#include "TargetBasedOnDistance.generated.h"

class APlayerController;
/**
 * 
 */
UCLASS()
class CONDITIONALTARGETS_API ATargetBasedOnDistance : public ATargetBase
{
	GENERATED_BODY()
	
public:
	bool TestIfCanBeShot(APlayerController* ShooterController) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Target Condition")
	float MaxDistance = 500.f;
};

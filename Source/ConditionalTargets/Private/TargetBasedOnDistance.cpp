// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetBasedOnDistance.h"
#include "GameFramework/PlayerController.h"

bool ATargetBasedOnDistance::TestIfCanBeShot(APlayerController* ShooterController)
{
	if (ShooterController)
	{
		const auto Pawn = ShooterController->GetPawn();
		return FVector::Distance(GetActorLocation(), Pawn->GetActorLocation()) < MaxDistance;
	}
	return false;
}
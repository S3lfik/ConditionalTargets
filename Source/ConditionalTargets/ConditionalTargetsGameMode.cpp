// Copyright Epic Games, Inc. All Rights Reserved.

#include "ConditionalTargetsGameMode.h"
#include "ConditionalTargetsHUD.h"
#include "ConditionalTargetsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AConditionalTargetsGameMode::AConditionalTargetsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AConditionalTargetsHUD::StaticClass();
}

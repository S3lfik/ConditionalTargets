// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetBasedOnScreenCenter.h"
#include "GameFramework/PlayerController.h"
#include <Components/StaticMeshComponent.h>
#include "DrawDebugHelpers.h"

// Sets default values
ATargetBasedOnScreenCenter::ATargetBasedOnScreenCenter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void ATargetBasedOnScreenCenter::BeginPlay()
{
	Super::BeginPlay();
}


bool ATargetBasedOnScreenCenter::TestIfCanBeShot(APlayerController* ShooterController)
{
	if (ShooterController)
	{
		FVector DeprojectLocation, DeprojectDirection;

		int32 viewportW, viewportH;
		FVector2D ScreenHitLocation;
		ShooterController->GetViewportSize(viewportW, viewportH);

		ShooterController->DeprojectScreenPositionToWorld(viewportW * .5f, viewportH * .5f, DeprojectLocation, DeprojectDirection);
		
		FHitResult HitResult;
		GetWorld()->LineTraceSingleByChannel(HitResult, DeprojectLocation, DeprojectLocation + DeprojectDirection * 1000, ECC_Visibility);
		if (HitResult.GetActor() == this)
		{
			if (ShooterController->ProjectWorldLocationToScreen(GetActorLocation(), ScreenHitLocation))
			{
				UE_LOG(LogTemp, Warning, TEXT("%s Screen Hit"), *ScreenHitLocation.ToString());
				UE_LOG(LogTemp, Warning, TEXT("%s Screen Center"), *FVector2D{ static_cast<float>(viewportW * .5f), static_cast<float>(viewportH * .5f) }.ToString());
				UE_LOG(LogTemp, Warning, TEXT("%f Distance"), FVector2D::Distance({ static_cast<float>(viewportW * .5f), static_cast<float>(viewportH * .5f) }, ScreenHitLocation));
				return FVector2D::Distance({ static_cast<float>(viewportW * .5f), static_cast<float>(viewportH * .5f) }, ScreenHitLocation) <= MaxRadius;
			}
		}
	}
	return false;
}
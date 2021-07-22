// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetBase.h"
#include <Components/StaticMeshComponent.h>
#include "GameFramework/PlayerController.h"

// Sets default values
ATargetBase::ATargetBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void ATargetBase::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ATargetBase::TestIfCanBeShot_Implementation(APlayerController* ShooterController)
{
	return false;
}

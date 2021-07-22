// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/ShootableTarget.h"
#include "TargetBase.generated.h"

class UStaticMeshComponent;
class APlayerController;
UCLASS()
class CONDITIONALTARGETS_API ATargetBase : public AActor, public IShootableTarget
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	UStaticMeshComponent* MeshComp;

public:	
	// Sets default values for this actor's properties
	ATargetBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Shootable Target")
	bool TestIfCanBeShot(APlayerController* ShooterController) override;

};

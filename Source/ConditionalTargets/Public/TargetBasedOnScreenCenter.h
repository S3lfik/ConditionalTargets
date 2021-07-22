// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/ShootableTarget.h"
#include "TargetBasedOnScreenCenter.generated.h"

class APlayerController;
class UStaticMeshComponent;

UCLASS()
class CONDITIONALTARGETS_API ATargetBasedOnScreenCenter : public AActor, public IShootableTarget
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATargetBasedOnScreenCenter();

	UFUNCTION(BlueprintCallable, Category = "Shootable Target")
	bool TestIfCanBeShot(APlayerController* ShooterController) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Target Condition")
	float MaxRadius = 500.f;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	UStaticMeshComponent* MeshComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};

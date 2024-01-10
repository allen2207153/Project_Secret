// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class PROJECT_SECRET_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:

	UPROPERTY(EditAnywhere)
	FVector OriginalLocation;
	FVector CurrentLocation;
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector PlatformVelocity = FVector(0,0,100);
	UPROPERTY(EditAnywhere, Category = "Rotate Platform")
	FRotator RotationVelocity;
	UPROPERTY(VisibleAnywhere)
	float MovedDistance;
	UPROPERTY(EditAnywhere)
	float MaxDistance = 500;

	void MovePlatform(float DTime);
	void RotatePlatform(float DTime);
	bool ShouldPlatformReturn();

};

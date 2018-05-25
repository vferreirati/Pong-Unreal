// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerBox.h"
#include "Ball.generated.h"

UCLASS()
class PONG_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool IsActorDestroyed() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	UPROPERTY(EditAnywhere)
	float Speed = 15;

	UPROPERTY(EditAnywhere)
	ATriggerBox* PlayerGoal = nullptr;

	UPROPERTY(EditAnywhere)
	ATriggerBox* EnemyGoal = nullptr;

	bool bIsActorDestroyed = false;
	
};

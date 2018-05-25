// Fill out your copyright notice in the Description page of Project Settings.

#include "Ball.h"


// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
	if(!PlayerGoal) {
		UE_LOG(LogTemp, Error, TEXT("Ball is missing reference to PlayerGoalTrigger"));
	}

	if(!EnemyGoal) {
		UE_LOG(LogTemp, Error, TEXT("Ball is missing reference to EnemyGoalTrigger"));
	}
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Right now doesn't matter who wins, the outcome is the same
	if(IsOverlappingActor(PlayerGoal) || IsOverlappingActor(EnemyGoal)) {
		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("Game is finished!"));
	}
}


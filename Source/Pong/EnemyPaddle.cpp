// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyPaddle.h"


// Sets default values
AEnemyPaddle::AEnemyPaddle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyPaddle::BeginPlay()
{
	Super::BeginPlay();
	if(!Ball) {
		UE_LOG(LogTemp, Warning, TEXT("EnemyPaddle is missing reference to the ball"));
	}
}

// Called every frame
void AEnemyPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(Ball) {
		FVector CurrentLocation = GetActorLocation();
		FVector CurrentBallLocation = Ball->GetActorLocation();

		float Intensity;

		if(CurrentBallLocation.Y > CurrentLocation.Y) {
			Intensity = 1;
		} else if(CurrentBallLocation.Y < CurrentLocation.Y) {
			Intensity = -1;
		}

		Move(Intensity);
	}
}

void AEnemyPaddle::Move(float Direction) {
	FVector CurrentLocation = GetActorLocation();

	CurrentLocation.Y += Speed * Direction;

	SetActorLocation(CurrentLocation);
}


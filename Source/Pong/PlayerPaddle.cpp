// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPaddle.h"
#include "Components/InputComponent.h"


// Sets default values
APlayerPaddle::APlayerPaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveUp", this, &APlayerPaddle::Move);

}

void APlayerPaddle::Move(float Amount) {

	if(Amount != 0) {
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation.Y += Amount * Speed;

		SetActorLocation(CurrentLocation);
	}

}


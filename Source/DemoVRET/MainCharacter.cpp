// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoVRET.h"
#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "Hand.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(GetRootComponent());

	//LeftController = new Hand(TEXT("LeftHand"));
	//LeftController->SetupAttachment(GetRootComponent());
	//LeftController->Hand = EControllerHand::Left;

	//RightController = new Hand(TEXT("RightHand"));
	//RightController->SetupAttachment(GetRootComponent());
	//RightController->Hand = EControllerHand::Right;
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AMainCharacter::MoveRight);
}


void AMainCharacter::MoveForward(float throttle) {
	AddMovementInput(throttle*camera->GetForwardVector());
}

void AMainCharacter::MoveRight(float throttle) {
	AddMovementInput(throttle*camera->GetRightVector());
}
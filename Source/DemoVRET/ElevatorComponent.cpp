// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoVRET.h"
#include "ElevatorComponent.h"


// Sets default values for this component's properties
UElevatorComponent::UElevatorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UElevatorComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UElevatorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveUp(DeltaTime);
	// ...
}

void UElevatorComponent::MoveUp(float deltaTime) {
	FVector pos = GetOwner()->GetActorLocation();
	GetOwner()->SetActorLocation(pos + FVector(0, 0, 20)*deltaTime);
}
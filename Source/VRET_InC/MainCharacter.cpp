// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Runtime/HeadMountedDisplay/Public/MotionControllerComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	VRroot = CreateDefaultSubobject<USceneComponent>(TEXT("VRroot"));
	VRroot->SetupAttachment(GetRootComponent());
	camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	camera->SetupAttachment(VRroot);

	CreateHands();
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
	FVector newCameraOffset = camera->GetComponentLocation() - GetActorLocation();
	newCameraOffset.Z = 0.0f;
	AddActorWorldOffset(newCameraOffset);
	VRroot->AddWorldOffset(-newCameraOffset);

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMainCharacter::CreateHands() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/VREditor/Devices/Vive/ViveControllerMesh.ViveControllerMesh'"));
	leftHandMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LeftHandMesh"));
	rightHandMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RightHandMesh"));
	
	UStaticMesh* Asset = MeshAsset.Object;
	leftHandMesh->SetStaticMesh(Asset);
	rightHandMesh->SetStaticMesh(Asset);


	left = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftController"));
	left->SetupAttachment(VRroot);
	left->SetTrackingSource(EControllerHand::Left);
	leftHandMesh->SetupAttachment(left);
	
	right = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightController"));
	right->SetupAttachment(VRroot);
	right->SetTrackingSource(EControllerHand::Right);
	rightHandMesh->SetupAttachment(right);
}

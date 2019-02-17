// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoVRET.h"
#include "Hand.h"
#include <string>
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"

Hand::Hand(const FName& name)
{
	UMotionControllerComponent();
	handMesh = CreateDefaultSubobject<UStaticMeshComponent>(name);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MeshAsset(TEXT("StaticMesh'/Engine/VREditor/Devices/Vive/VivePreControllerMesh.VivePreControllerMesh'"));
	UStaticMesh* Asset = MeshAsset.Object;
	//handMesh->SetStaticMesh(Asset);
}

Hand::~Hand()
{
}

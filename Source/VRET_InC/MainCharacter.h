// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class VRET_INC_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void CreateHands();

public:	
	UPROPERTY(VisibleAnyWhere)
	class UCameraComponent * camera;
	
	UPROPERTY(VisibleAnyWhere)
	class UMotionControllerComponent * left;

	UPROPERTY(VisibleAnyWhere)
	UMotionControllerComponent * right;

	UPROPERTY(VisibleAnyWhere)
	class UStaticMeshComponent * leftHandMesh;

	UPROPERTY(VisibleAnyWhere)
	UStaticMeshComponent * rightHandMesh;

	class USceneComponent * VRroot;



	

};

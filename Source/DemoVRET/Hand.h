// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MotionControllerComponent.h"
/**
 * 
 */
class DEMOVRET_API Hand:public UMotionControllerComponent
{
public:
	Hand(const FName& name);
	~Hand();
public:
	class UStaticMeshComponent* handMesh;
};

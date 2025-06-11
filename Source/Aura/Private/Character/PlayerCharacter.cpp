// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
	
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->bOrientRotationToMovement = true; // 角色朝向移动方向
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f); // 角色转向速度
	GetCharacterMovement()->bConstrainToPlane = true; // 限制角色在平面内移动
	GetCharacterMovement()->bSnapToPlaneAtStart= true; // 开始时将角色对齐到平面

	bUseControllerRotationPitch= false; // 禁用控制器旋转俯仰
	bUseControllerRotationRoll= false; // 禁用控制器旋转翻滚
	bUseControllerRotationYaw= false; // 禁用控制器旋转偏航
}


void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}



﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerControllerBase.h"

#include "InputState.h"

APlayerControllerBase::APlayerControllerBase()
{
	bReplicates = true; 
}

void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	//增强输入子系统
	check(CharacterContext);
	UEnhancedInputLocalPlayerSubsystem*Subsystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(CharacterContext,0);

	//鼠标
	bShowMouseCursor = true; 
	DefaultMouseCursor = EMouseCursor::Default;
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void APlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	//获取组件绑定移动函数
	UEnhancedInputComponent*EnhancedInputComponent=Cast<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&APlayerControllerBase::Move);
}

void APlayerControllerBase::Move(const struct FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector=InputActionValue.Get<FVector2D>();
	const FRotator InputRotation=GetControlRotation();
	const FRotator InputAxis(0.f,InputRotation.Yaw,0.f);
	
	const FVector ForwardVector=FRotationMatrix(InputAxis).GetUnitAxis(EAxis::X);
	const FVector RightVector=FRotationMatrix(InputAxis).GetUnitAxis(EAxis::Y);

	if(APawn*ControllerPawn=GetPawn<APawn>())
	{
		ControllerPawn->AddMovementInput(ForwardVector,InputAxisVector.Y);
		ControllerPawn->AddMovementInput(RightVector,InputAxisVector.X);
	}
}


void APlayerControllerBase::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}

void APlayerControllerBase::CursorTrace()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility,false,HitResult);
	if (!HitResult.bBlockingHit) return;//没有命中或者被阻挡返回

	LastActor=CurrentActor;
	CurrentActor= Cast<IEnemyInterFace>(HitResult.GetActor());

	if(LastActor==nullptr)
	{
		if (CurrentActor!=nullptr)
		{
			CurrentActor->HighLightActor();
		}
	}

	else
	{
		if(CurrentActor==nullptr)
		{
			LastActor->UnHighLightActor();
		}

		else
		{
			if(LastActor != CurrentActor)
			{
			
				LastActor->UnHighLightActor();
				CurrentActor->HighLightActor();
			} 
		}
	}

}

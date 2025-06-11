// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"       
#include "EnhancedInputComponent.h"          
#include "EnhancedInputSubsystems.h"      
#include "InputAction.h"                 
#include "InputMappingContext.h"            
#include "Tools/EnemyInterFace.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:

	APlayerControllerBase();

	virtual void PlayerTick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override; 

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> CharacterContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const struct FInputActionValue& InputActionValue);

	void CursorTrace();//鼠标追踪获取
	IEnemyInterFace*LastActor;//有接口的上一个物体
	IEnemyInterFace*CurrentActor;//有接口的当前物体

};

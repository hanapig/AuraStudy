// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/InputComponent.h"       
#include "EnhancedInputComponent.h"          
#include "EnhancedInputSubsystems.h"      
#include "InputAction.h"                 
#include "InputMappingContext.h"            
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
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override; 

private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> CharacterContext;

	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	void Move(const struct FInputActionValue& InputActionValue);

};

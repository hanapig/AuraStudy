// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gas/AttributeSetBase.h"
#include "UI/WidgetController.h"
#include "OverlayWidgetController.generated.h"

struct FOnAttributeChangeData;
/**
 * 
 */
UCLASS(BlueprintType,Blueprintable)
class AURA_API UOverlayWidgetController : public UWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadCastInitValue() override;

	virtual void BindCallValueBack() override;

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMaxOnHealthChangedSignature, float, NewMaxHealth);

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FMaxOnHealthChangedSignature MaxOnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealthChangedSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnHealthChangedSignature MaxOnManaChanged;
	
protected:
	void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;
	void ManaChanged(const FOnAttributeChangeData& Data) const;
	void MaxManaChanged(const FOnAttributeChangeData& Data) const;


	
};

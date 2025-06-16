// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class UWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject>WidgetController;

	UFUNCTION(BlueprintCallable) //蓝图可调用
	void SetWidgetController(UObject* InWidgetController);//设置WidgetController

protected:
	UFUNCTION(BlueprintImplementableEvent) //蓝图可实现事件
	void WidgetControllerSet();//设置WidgetController后回调



};

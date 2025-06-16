// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUDBase.h"
#include  "UI/OverlayWidgetController.h"

UOverlayWidgetController* AHUDBase::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if(OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
	}
	return OverlayWidgetController;
}

void AHUDBase::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	
	checkf(OverlayWidgetClass, TEXT("OverlayWidgetClass 未设置，请在HUD上面设置"));
	checkf(OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass 未设置，请在HUD上面设置"));
	
	UWidgetBase* Widget = CreateWidget<UWidgetBase>(GetWorld(), OverlayWidgetClass); //创建Overlay用户控件
	OverlayWidget = Cast<UWidgetBase>(Widget);

	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS); 
	OverlayWidgetController = GetOverlayWidgetController(WidgetControllerParams); 

	OverlayWidget->SetWidgetController(OverlayWidgetController); //设置用户控件的控制器层
	
	Widget->AddToViewport(); 

}



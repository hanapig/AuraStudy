// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/PlayerCharacter.h"
#include "EditorFontGlyphs.h"
#include "Player/PlayerControllerBase.h"
#include "Player/PlayerStateBase.h"
#include "UI/HUDBase.h"


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


UAbilitySystemComponent* APlayerCharacter::GetAbilitySystemComponent() const
{
	APlayerStateBase*PlayerStateBase = GetPlayerState<APlayerStateBase>();
	return PlayerStateBase->GetAbilitySystemComponent();
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbility();
	SetOwner(NewController);
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbility();
}


void APlayerCharacter::InitAbility()
{
	
		APlayerStateBase* PlayerStateBase = GetPlayerState<APlayerStateBase>();
		check(PlayerStateBase); 
		//从playerState获取ASC和AS
		AbilitySystemComponent = PlayerStateBase->GetAbilitySystemComponent();
		AttributeSet = PlayerStateBase->GetAttributeSet();
		//初始化ASC
		AbilitySystemComponent->InitAbilityActorInfo(PlayerStateBase, this);

		//获取PC
		if(APlayerControllerBase* PlayerControllerBase = Cast<APlayerControllerBase>(GetController()))
		{
			if(AHUDBase* HUD = Cast<AHUDBase>(PlayerControllerBase->GetHUD()))
			{
				HUD->InitOverlay(PlayerControllerBase, PlayerStateBase, AbilitySystemComponent, AttributeSet);
			}
		}
	
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}




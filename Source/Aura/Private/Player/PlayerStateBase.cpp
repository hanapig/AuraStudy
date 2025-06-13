// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/PlayerStateBase.h"
#include "Gas/AbilitySystemComponentBase.h"
#include "Gas/AttributeSetBase.h"


APlayerStateBase::APlayerStateBase()
{

	NetUpdateFrequency=100.f;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponentBase>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true); //设置组件用于在网络上复制
	AttributeSet = CreateDefaultSubobject<UAttributeSetBase>("AttributeSet");

	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}

UAbilitySystemComponent* APlayerStateBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

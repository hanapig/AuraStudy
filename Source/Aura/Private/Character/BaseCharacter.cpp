// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/BaseCharacter.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	Weapon=CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),"WeaponHandSocket");
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}


void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

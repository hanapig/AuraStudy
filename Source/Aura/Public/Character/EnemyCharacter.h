// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Tools/EnemyInterFace.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class AURA_API AEnemyCharacter : public ABaseCharacter,public IEnemyInterFace
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual  void HighLightActor() override;
	virtual void UnHighLightActor() override;

	UPROPERTY(BlueprintReadOnly) //蓝图可读
	bool bHighlighted = false; //是否高亮
	
};

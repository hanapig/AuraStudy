
#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "BaseCharacter.h"
#include "GameFramework/Character.h"
#include  "GameFramework/CharacterMovementComponent.h"
#include "PlayerCharacter.generated.h"


UCLASS()
class AURA_API APlayerCharacter : public ABaseCharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override; //覆盖虚函数获取asc
	UAttributeSet* GetAttributeSet() const { return AttributeSet; } //获取as

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	void InitAbility();
	
protected:

	virtual void BeginPlay() override;


public:
	
};

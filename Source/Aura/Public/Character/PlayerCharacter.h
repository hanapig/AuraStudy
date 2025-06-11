
#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "GameFramework/Character.h"
#include  "GameFramework/CharacterMovementComponent.h"
#include "PlayerCharacter.generated.h"


UCLASS()
class AURA_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:

	virtual void BeginPlay() override;


public:
	
};

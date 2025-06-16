// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ActorBase.h"

#include "AbilitySystemInterface.h"
#include "Components/SphereComponent.h"
#include "Gas/AttributeSetBase.h"

// Sets default values
AActorBase::AActorBase()
{

	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());

}

void AActorBase::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(IAbilitySystemInterface* AbilitySystemInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		
		const UAttributeSetBase* AttributeSet = Cast<UAttributeSetBase>(AbilitySystemInterface->GetAbilitySystemComponent()->GetAttributeSet(UAttributeSetBase::StaticClass()));
		UAttributeSetBase* MutableAttributeSet = const_cast<UAttributeSetBase*>(AttributeSet); //将常量转为变量
		MutableAttributeSet->SetHealth(AttributeSet->GetHealth() + 25.f);
		Destroy();
	}

}

void AActorBase::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

// Called when the game starts or when spawned
void AActorBase::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AActorBase::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &AActorBase::EndOverlap);

}


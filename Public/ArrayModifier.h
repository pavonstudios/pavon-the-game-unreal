// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "Pavon/DuplicateInstance.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrayModifier.generated.h"

UCLASS()
class SURVIVALGAME_API AArrayModifier : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArrayModifier();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere)
    int count = 1;
    
    UPROPERTY(EditAnywhere)
    int offsetX = 200;
     UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=StaticMeshAssets)
	class UStaticMesh* mesh_to_duplicate;
	
	
};

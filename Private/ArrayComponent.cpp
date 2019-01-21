// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "SurvivalGame.h"
#include "ArrayComponent.h"


UArrayComponent::UArrayComponent(){
    MovementRadius = 2;
    UE_LOG(LogTemp, Warning, TEXT("Test")); 
    if(GEngine){
        GEngine->AddOnScreenDebugMessage(-1,4.f,FColor::Red,TEXT("adsfadsf"));
    }
}
void UArrayComponent::TickComponent(float DeltaSeconds, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    AActor* Parent = GetOwner();
    if (Parent)
    {
      Parent->SetActorLocation(
      Parent->GetActorLocation() +
      FVector(
      FMath::FRandRange(-1, 1)* MovementRadius,
      FMath::FRandRange(-1, 1)* MovementRadius,
      FMath::FRandRange(-1, 1)* MovementRadius));
        if(GEngine){
        GEngine->AddOnScreenDebugMessage(-1,4.f,FColor::Red,TEXT("siiii"));
    }
    }else{
    UE_LOG(LogTemp, Warning, TEXT("noooo")); 
     if(GEngine){
        GEngine->AddOnScreenDebugMessage(-1,4.f,FColor::Red,TEXT("noooooo"));
    }
    }
    
}



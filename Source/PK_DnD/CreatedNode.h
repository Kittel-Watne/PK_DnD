// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CreatedNode.generated.h"

/**
 * 
 */
UCLASS()
class PK_DND_API UCreatedNode : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NodeObject")
	FString MyData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "NodeObject")
	TObjectPtr<UCreatedNode> NextNode;

	UFUNCTION(BlueprintCallable, Category = "NodeObject")
	UCreatedNode* Node(FString Data);
};

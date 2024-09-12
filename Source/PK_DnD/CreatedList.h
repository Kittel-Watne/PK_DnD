// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CreatedNode.h"
#include "UObject/NoExportTypes.h"
#include "CreatedList.generated.h"

/**
 * 
 */
UCLASS()
class PK_DND_API UCreatedList : public UObject
{
	GENERATED_BODY()
public:
	/*
	 *Attributes
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ListObject")
	TObjectPtr<UCreatedNode> Head;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ListObject")
	FString Data;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ListObject")
	TObjectPtr<UCreatedNode> CurrentNode;
	/*
	 *Functions
	 */
	UFUNCTION(BlueprintCallable, Category = "ListObject")
	UCreatedNode* Append(FString AppendData);
	UFUNCTION(BlueprintCallable, Category = "ListObject")
	UCreatedNode* Prepend(FString PrependData);
	UFUNCTION(BlueprintCallable, Category = "ListObject")
	UCreatedNode* DeleteWithValue(FString Value);
	UFUNCTION(BlueprintCallable, Category = "ListObject")
	bool PrintList();
};

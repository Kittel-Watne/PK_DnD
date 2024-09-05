// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ExampleStackInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UExampleStackInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PK_DND_API IExampleStackInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "StackInterface")
	void Push(int32 Data);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "StackInterface")
	int32 Pop();
};

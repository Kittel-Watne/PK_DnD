// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ExampleStackInterface.h"
#include "UObject/NoExportTypes.h"
#include "ExampleStack.generated.h"

/**
 * 
 */
UCLASS()
class PK_DND_API UExampleStack : public UObject, public IExampleStackInterface
{
	GENERATED_BODY()
public:
	//ExampleStackInterface Begin
	virtual void Push_Implementation(int32 Data) override;

	//virtual int32 Pop_Implementation()override;
	//ExampleStackInterface End

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Stack")
	TArray<int32> IntegerStack;

	//UFUNCTION(BlueprintCallable)
	//void PrintStack();
};

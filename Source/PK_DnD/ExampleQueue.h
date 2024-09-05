// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ExampleQueueInterface.h"
#include "UObject/NoExportTypes.h"
#include "ExampleQueue.generated.h"

/**
 * 
 */
UCLASS()
class PK_DND_API UExampleQueue : public UObject, public IExampleQueueInterface
{
	GENERATED_BODY()
public:

	//ExampleQueueInterface Begin
	virtual void Enqueue_Implementation(int32 Data) override;

	virtual int32 Dequeue_Implementation() override;
	//ExampleQueueInterface End

	/*
	 *Variable
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Queue")
	TArray<int32> IntegerQueue;

	UFUNCTION(BlueprintCallable)
	void QueuePrint();

};

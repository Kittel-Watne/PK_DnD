// Fill out your copyright notice in the Description page of Project Settings.


#include "ExampleQueue.h"



void UExampleQueue::Enqueue_Implementation(int32 Data)
{
	IntegerQueue.Emplace(Data);
}

int32 UExampleQueue::Dequeue_Implementation()
{
	int32 DequeueData = 0;
	if (!IntegerQueue.IsEmpty())
	{
		DequeueData = IntegerQueue[0];
		IntegerQueue.RemoveAt(0);
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf("Dequeue: %d", DequeueData));
	}

	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf("ExampleQueue is empty."));

	return int32();
}

void UExampleQueue::QueuePrint()
{
	for (auto& Data : IntegerQueue ){}
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf("%d",Data));
}

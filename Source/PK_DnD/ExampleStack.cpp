// Fill out your copyright notice in the Description page of Project Settings.


#include "ExampleStack.h"

void UExampleStack::Push_Implementation(int32 Data)
{
	IntegerStack.Emplace(Data);
}

//int32 UExampleStack::Pop_Implementation()
//{
//	//int32 PopData = 0;
//	//if (!IntegerStack.IsEmpty())
//	//{
//	//	PopData = IntegerStack[IntegerStack.Num()];
//	//	IntegerStack.Pop();
//	//	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf("Dequeue: %d", PopData));
//	//}
//	//
//	//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf("ExampleQueue is empty."));
//	//
//	//return int32();
//	
//}
//
//void UExampleStack::PrintStack()
//{
//	for (auto& Data : IntegerStack)
//		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf("%d", Data));
//}
//
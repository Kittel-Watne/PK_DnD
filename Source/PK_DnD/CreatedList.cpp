// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatedList.h"
#include <windows.h>			//For using sleep function

UCreatedNode* UCreatedList::Append(FString AppendData)
{
	FString MyData = AppendData;

	TObjectPtr<UCreatedNode> NewNode = NewObject<UCreatedNode>(GetTransientPackage());
	NewNode->Node(MyData);


	if (IsValid(Head))
	{
		CurrentNode = Head;

		while (IsValid(CurrentNode->NextNode))
		{
			CurrentNode = CurrentNode->NextNode;
		}

		CurrentNode->NextNode = NewNode;

		return NewNode;
	}
	else
	{
		Head = NewNode;

		return NewNode;
	}
	
}

UCreatedNode* UCreatedList::Prepend(FString PrependData)
{
	FString MyData = PrependData;

	TObjectPtr<UCreatedNode> NewNode = NewObject<UCreatedNode>(GetTransientPackage());
	NewNode->Node(MyData);

	if (IsValid(Head))
	{		
		CurrentNode = NewNode;
		CurrentNode->NextNode = Head;
		Head = CurrentNode;

		return NewNode;
	}
	else
	{
		TObjectPtr<UCreatedNode> Node;
		Node->MyData = PrependData;
		Head = Node;

		return Node;
	}
}

UCreatedNode* UCreatedList::DeleteWithValue(FString Value)
{
	FString MyData = Value;
	if (IsValid(Head))
	{
		if(MyData == Head->MyData)
		{
			if (IsValid(Head->NextNode))
			{
				Head = Head->NextNode;
				return nullptr;
			}
			else
			{
				Head = nullptr;
			}
		}
		else
		{
			CurrentNode = Head;
			while (IsValid(CurrentNode->NextNode))
			{
				if (MyData == CurrentNode->NextNode->MyData)
				{
					if (IsValid(CurrentNode->NextNode->NextNode))
					{
						CurrentNode->NextNode = CurrentNode->NextNode->NextNode;
						return nullptr;
					}
					else
					{
						CurrentNode->NextNode = nullptr;
						return nullptr;
					}
				}
				else
				{
					CurrentNode = CurrentNode->NextNode;
				}
			}
		}
	}
	else
	{
		return nullptr;
	}

	return nullptr;
}

bool UCreatedList::PrintList()
{
	if (IsValid(Head))
	{
		CurrentNode = Head;
		while(IsValid(CurrentNode))
		{
			//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Cyan, FString::Printf(CurrentNode->MyData));

			CurrentNode = CurrentNode->NextNode;
		}
		return true;
	}
	else 
	{
		return false;
	}
}
/*
 *26.09.2024
 */

bool UCreatedList::BubbleSort()
{
	int32 Depth = GetDepth();
	TObjectPtr<UCreatedNode> AuxNode;

	for (int i = 0; i < Depth-1; i++) {
		CurrentNode = Head;
		TObjectPtr<UCreatedNode> PreviousNode = nullptr;;

		//Depth-i is used, since you don't need to check the final item, if it isn't sorted, it will be sorted by the time you get to the second to last item
		for (int j = 0; j < Depth - i; j++)
		{
			if (CurrentNode->MyData > CurrentNode->NextNode->MyData)
				if (CurrentNode == Head)
				{
					//Changes order of first 2 elements

					//Saves NextNode as AuxNode
					AuxNode = CurrentNode->NextNode;

					//Changes CurrentNodes NextNode reference to instead reference AuxNodes NextNode
					CurrentNode->NextNode = AuxNode->NextNode;

					//AuxNodes NextNode reference changes to instead reference CurrentNode
					AuxNode->NextNode = CurrentNode;

					//Sets AuxNode as the new Head of the list
					Head = AuxNode;

					//Saves AuxNode as previous node, since this is not a doubly linked list
					PreviousNode = AuxNode;
				}
				else
				{
					//Changes order of 2 elements, as well as updating the previous node to reference the correct node

					//Saves NextNode as AuxNode
					AuxNode = CurrentNode->NextNode;

					//Changes CurrentNodes NextNode reference to instead reference AuxNodes NextNode
					CurrentNode->NextNode = AuxNode->NextNode;

					//Previous NextNode reference changes to instead reference AuxNode
					PreviousNode->NextNode = AuxNode;

					//AuxNodes NextNode reference changes to instead reference CurrentNode
					AuxNode->NextNode = CurrentNode;

					//Saves AuxNode as previous node, since this is not a doubly linked list
					PreviousNode = AuxNode;
				}

			//If the 2 elements are sorted, it moves on to the next node
			else
				CurrentNode = CurrentNode->NextNode;
					
		}
	}
	if (IsSorted())
		return true;

	return false;
}

int32 UCreatedList::GetDepth()
{
	int32 DepthCounter = 0;
	while (CurrentNode->NextNode != NULL)
	{
		DepthCounter++;
		CurrentNode = CurrentNode->NextNode;
	}

	return DepthCounter;
}


bool UCreatedList::IsSorted()
{
	CurrentNode = Head;
	while (CurrentNode->MyData < CurrentNode->NextNode->MyData)
		CurrentNode = CurrentNode->NextNode;

	if (CurrentNode->NextNode == NULL)
		return true;

	return false;
}

bool UCreatedList::MiracleSort()
{
	if (IsSorted() == true)
		return true;

	Sleep(10000);

	if (IsSorted() == true)
		return true;

	return false;
}
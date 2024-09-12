// Fill out your copyright notice in the Description page of Project Settings.


#include "CreatedList.h"

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

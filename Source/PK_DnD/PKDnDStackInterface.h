#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PKDnDStackInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPKDnDStackInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class PK_DND_API IPKDnDStackInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "PKDnDStackInterface")
	void Push(FString& Data);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "PKDnDStackInterface")
	FString Pop();
};
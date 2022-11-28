#pragma once
#include "GameplayTagContainer.h"
#include "UEnum.h"

#include "Struct1.generated.h"

/** Test */
USTRUCT(BlueprintType)
struct STRUCTCONVERTER_API FStruct1
{
	GENERATED_BODY()
	
	FStruct1(): TestFloat(0), TestInt(0), TestBool(false), TestEnum()
	{
	}

	/**  */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TestFloat;
	
	/**  */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 TestInt;

	/**  */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool TestBool;

	/**  */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName TestFName;

	/**  */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	ETestEnum TestEnum;
};

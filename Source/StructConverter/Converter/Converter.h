// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructConverter/Struct/Struct1.h"
#include "UObject/Object.h"
#include "Converter.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class STRUCTCONVERTER_API UConverter : public UObject
{
	GENERATED_BODY()

	FStruct1 TestStruct1;

	UFUNCTION(BlueprintCallable)
	TMap<FString, FString> ConvertFStruct1ToMap(FStruct1 TestStruct);

	UFUNCTION(BlueprintCallable)
	FStruct1 ConvertMapToFStruct1(TMap<FString, FString> ConvertedMap);
};

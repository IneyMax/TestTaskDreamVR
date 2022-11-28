#include "Converter.h"
#include "Kismet/KismetMathLibrary.h"

TMap<FString, FString> UConverter::ConvertFStruct1ToMap(FStruct1 TestStruct)
{
	TMap<FString, FString> ReturnMap;
	for (TFieldIterator<FProperty> PropIt(FStruct1::StaticStruct()); PropIt; ++PropIt)
	{
		/*
		int *i = (int*)&TestStruct + PropIt->GetOffset_ForInternal() / sizeof(int);
		int *j = (int*)(&i);
		int k = *j;
		
		i = (int *)(&TestStruct.TestFloat2);
		j = (int *)(&i);
		int l = *j;
		ReturnMap.Add(FString::FromInt(k), FString::FromInt(l));
		*/

		FString PropertyClassName;
		//PropertyClassName.Append(PropIt->GetClass()->GetName());
		PropertyClassName.Append(PropIt->GetCPPType());
		ReturnMap.Add(PropIt->GetName(), PropertyClassName);
		
		if (PropIt->GetCPPType() == "float")
		{
			float *i = (float*)((char*)&TestStruct + PropIt->GetOffset_ForInternal() / sizeof(char));
			ReturnMap.Add(PropIt->GetName(), FString::SanitizeFloat(*i));
		}

		if (PropIt->GetCPPType() == "int32")
		{
			int32 *i = (int32*)((char*)&TestStruct + PropIt->GetOffset_ForInternal() / sizeof(char));
			ReturnMap.Add(PropIt->GetName(), FString::FromInt(*i));
		}

		if (PropIt->GetCPPType() == "bool")
		{
			bool *i = (bool*)((char*)&TestStruct + PropIt->GetOffset_ForInternal() / sizeof(char));
			ReturnMap.Add(PropIt->GetName(), *i ? FString("true") : FString("false"));
		}

		if (PropIt->GetCPPType() == "FName")
		{
			FName *i = (FName*)((char*)&TestStruct + PropIt->GetOffset_ForInternal() / sizeof(char));
			ReturnMap.Add(PropIt->GetName(), i->ToString());
		}

		if (PropIt->GetClass()->GetName() == "EnumProperty")
		{
			uint8 *i = (uint8*)((char*)&TestStruct + PropIt->GetOffset_ForInternal() / sizeof(char));
			ReturnMap.Add(PropIt->GetName(), FString::FromInt(*i));
		}

		if (PropIt->GetCPPType() == "FVector")
		{
			FVector *i = (FVector*)((char*)&TestStruct + PropIt->GetOffset_ForInternal() / sizeof(char));
			ReturnMap.Add(PropIt->GetName(), i->ToString());
		}
	}
	
	return ReturnMap;
}

FStruct1 UConverter::ConvertMapToFStruct1(TMap<FString, FString> ConvertedMap)
{
	FStruct1 ReturnStruct;
	for (TFieldIterator<FProperty> PropIt(FStruct1::StaticStruct()); PropIt; ++PropIt)
	{
		FString FindValue = ConvertedMap.FindAndRemoveChecked(PropIt->GetName());
		if (PropIt->GetCPPType() == "float")
		{
			float *i = (float*)((char*)&ReturnStruct + PropIt->GetOffset_ForInternal() / sizeof(char));
			*i = FCString::Atof(*FindValue);
		}
		
		if (PropIt->GetCPPType() == "int32")
		{
			int32 *i = (int32*)((char*)&ReturnStruct + PropIt->GetOffset_ForInternal() / sizeof(char));
			*i = FCString::Atoi(*FindValue);
		}

		if (PropIt->GetCPPType() == "bool")
		{
			bool *i = (bool*)((char*)&ReturnStruct + PropIt->GetOffset_ForInternal() / sizeof(char));
			*i = FindValue.ToBool();
		}

		if (PropIt->GetCPPType() == "FName")
		{
			FName *i = (FName*)((char*)&ReturnStruct + PropIt->GetOffset_ForInternal() / sizeof(char));
			*i = (FName)(FindValue);
		}

		if (PropIt->GetClass()->GetName() == "EnumProperty")
		{
			uint8 *i = (uint8*)((char*)&ReturnStruct + PropIt->GetOffset_ForInternal() / sizeof(char));
			*i = FCString::Atoi(*FindValue);
		}

		if (PropIt->GetCPPType() == "FVector")
		{
			FVector *i = (FVector*)((char*)&ReturnStruct + PropIt->GetOffset_ForInternal() / sizeof(char));
			FVector ResultVector;
			ResultVector.InitFromString(*FindValue);
			*i = ResultVector;
		}
	}
	return ReturnStruct;
}

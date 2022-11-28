#pragma once

#include "UEnum.generated.h"

UENUM(BlueprintType)
enum class ETestEnum : uint8
{
	None UMETA(DisplayName = "None"),
	TestEnum1 UMETA(DisplayName = "TestEnum1"),
	TestEnum2 UMETA(DisplayName = "TestEnum2"),
	TestEnum3 UMETA(DisplayName = "TestEnum3"),
	Max  UMETA ( Hidden )
};
ENUM_RANGE_BY_COUNT(ETestEnum, ETestEnum::Max)

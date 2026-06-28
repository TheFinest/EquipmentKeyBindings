#pragma once

#include "CoreMinimal.h"
#include "Equipment/FGEquipment.h"
#include "FGCharacterPlayer.h"
#include "FGInventoryComponentEquipment.h"
#include "EquipmentBlueprintFn.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(EquipmentKeyBindings, Verbose, All);

UCLASS()
class UEquipmentBlueprintFn : public UBlueprintFunctionLibrary
{	
	GENERATED_BODY()

public:
	/** Cycles the arm equipment slot by the given number of steps. Kept for backwards compatibility. */
	UFUNCTION(BlueprintCallable, Category = "CharacterPlayer")
	static void MultiCycleEquipment(AFGCharacterPlayer* CharacterPlayer, int32 cycles, bool hasAuthority);

	/** Selects a specific index in the arm equipment slot. Safe to call from a client. */
	UFUNCTION(BlueprintCallable, Category = "CharacterPlayer")
	static void SelectArmEquipmentByIndex(AFGCharacterPlayer* CharacterPlayer, int32 SlotIndex);
};
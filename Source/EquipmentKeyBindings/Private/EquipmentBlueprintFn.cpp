#include "EquipmentBlueprintFn.h"
#include "Equipment/FGEquipment.h"
#include "FGCharacterPlayer.h"
#include "FGInventoryComponentEquipment.h"

DEFINE_LOG_CATEGORY(EquipmentKeyBindings);

void UEquipmentBlueprintFn::MultiCycleEquipment(AFGCharacterPlayer* CharacterPlayer, int32 cycles, bool hasAuthority)
{
    UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn] Total Cycles: %d"), cycles);
    UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn] Has Authority? %s"), (hasAuthority ? TEXT("true") : TEXT("false")));

    int32 dir;
    if (cycles > 0) {
        UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn] Cycles > 0"));
        dir = 1;
    }
    else {
        UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn] Cycles < 0"));
        dir = -1;
    }

    while (cycles != 0) {
        if (hasAuthority) {
            UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn][Server] Cycle number: %d"), cycles);
            CharacterPlayer->DoCycleEquipment(dir);
        }
        else {
            UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn][Client] Cycle number: %d"), cycles);
            CharacterPlayer->Server_CycleHandEquipmentPressed(dir);
        }
        cycles = cycles - dir;
        UE_LOG(EquipmentKeyBindings, Verbose, TEXT("[EquipmentBlueprintFn] Cycles updated to: %d"), cycles);
    }
}

void UEquipmentBlueprintFn::SelectArmEquipmentByIndex(AFGCharacterPlayer* CharacterPlayer, int32 SlotIndex)
{
    if (!IsValid(CharacterPlayer))
    {
        UE_LOG(EquipmentKeyBindings, Warning, TEXT("[EquipmentBlueprintFn] SelectArmEquipmentByIndex called with invalid character"));
        return;
    }

    UFGInventoryComponentEquipment* ArmSlot = CharacterPlayer->GetEquipmentSlot(EEquipmentSlot::ES_ARMS);
    if (!IsValid(ArmSlot))
    {
        UE_LOG(EquipmentKeyBindings, Warning, TEXT("[EquipmentBlueprintFn] Failed to find arm equipment slot"));
        return;
    }

    const int32 NumSlots = ArmSlot->GetSizeLinear();
    if (SlotIndex < 0 || SlotIndex >= NumSlots)
    {
        UE_LOG(EquipmentKeyBindings, Warning, TEXT("[EquipmentBlueprintFn] Slot index %d out of range [0, %d)"), SlotIndex, NumSlots);
        return;
    }

    UE_LOG(EquipmentKeyBindings, Log, TEXT("[EquipmentBlueprintFn] Selecting arm equipment index %d"), SlotIndex);
    ArmSlot->Server_SetActiveEquipmentIndex(SlotIndex);
}
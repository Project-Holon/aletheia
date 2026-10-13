/*
 * file:     hand_common.c
 * unit:     yes
 * function: HAND_COMMON_IsMoveTarget, HAND_COMMON_IsLastToAct, HAND_COMMON_IsItemBoundToSpecies
 * address:  0x021E85F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from hand_waza.c by tools/splitfile.py.
 *
 * symbols:
 *   BTL_ID_IsArceusPlate  0x0689C980  thumb
 *   BTL_ID_IsGenesectDrive  0x0689C990  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AreAllOtherActionsDone  0x021C80AC  thumb  ov093
 */
#include "hand_common_protos.h"

/* Shared helper of the ability, item and move handlers: whether the Pokemon is one of the targets of the current move. */
int HAND_COMMON_IsMoveTarget(int pokeId)
{
    u32 i;
    u32 targetCount;

    targetCount = BTL_EVENT_GetVar(BTL_EVAR_DEFENDER_COUNT);
    i = 0;
    if (targetCount != 0) {
        do {
            if (pokeId == BTL_EVENT_GetVar(i + BTL_EVAR_DEFENDER_FIRST))
                return 1;
            i++;
        } while (i < targetCount);
    }
    return 0;
}

/* Shared helper (Protect family, abilities, items): whether every other Pokemon has already acted this turn. */
int HAND_COMMON_IsLastToAct(struct BtlServerFlow *flow, int pokeId)
{
    if (BTL_SERVER_FLOW_AreAllOtherActionsDone(flow, pokeId) != 0)
        return 1;
    return 0;
}

/*
 * Shared helper (Trick family, Knock Off, view code): whether the item cannot be taken from or
 * given to a Pokemon of that species (Griseous Orb on Giratina, Plates on Arceus, Drives on Genesect).
 */
int HAND_COMMON_IsItemBoundToSpecies(int speciesId, int itemId)
{
    switch (speciesId) {
    case BTL_SPECIES_GIRATINA:
        if (itemId == BTL_ITEM_GRISEOUS_ORB)
            return 1;
        break;
    case BTL_SPECIES_ARCEUS:
        if (BTL_ID_IsArceusPlate(itemId) != 0)
            return 1;
        break;
    case BTL_SPECIES_GENESECT:
        if (BTL_ID_IsGenesectDrive(itemId) != 0)
            return 1;
        break;
    }
    return 0;
}

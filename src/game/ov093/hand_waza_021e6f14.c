/*
 * file:     hand_waza_021e6f14.c
 * unit:     yes
 * function: HAND_WAZA_MeFirstBoostPower, HAND_WAZA_AddCopycat, HAND_WAZA_CopycatPickMove, HAND_WAZA_AddAllStatBoostChance, HAND_WAZA_AllStatBoostSetChance, HAND_WAZA_AddVenoshock
 * address:  0x021E6F14
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689CA5C  0x0689CA5C  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_SERVER_FLOW_GetLastActionId  0x021C8114  thumb  ov093
 *   BTL_SERVER_FLOW_DecideMoveTarget  0x021C8030  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gCopycatHandlers     0x021F26C4  data    a4
 *   gAllStatBoostChanceHandlers     0x021F262C  data   ov093  a4
 *   gVenoshockHandlers     0x021F251C  data   ov093  a4
 */
#include "hand_waza_021e62f4_types.h"

extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);
extern u16 BTL_SERVER_FLOW_GetLastActionId(u8 *flow);
extern int func_0689CA5C(int moveId);
extern int BTL_SERVER_FLOW_DecideMoveTarget(u8 *flow, int pokeId, u16 moveId);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern int gCopycatHandlers[];
extern int gAllStatBoostChanceHandlers[];
extern int gVenoshockHandlers[];

/* Me First: raise the power of the called move by half. */
void HAND_WAZA_MeFirstBoostPower(int factor, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID))
        BTL_EVENT_MultiplyVar(WAZAVAR_POWER_RATIO, 3 << 11);
}

/* Copycat: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddCopycat(int *handlerCount)
{
    *handlerCount = 1;
    return gCopycatHandlers;
}

/* Copycat: use the move that was used last in the battle, if it can be copied. */
void HAND_WAZA_CopycatPickMove(int factor, int flow, int pokeId)
{
    u16 moveId;
    int slot;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        moveId = BTL_SERVER_FLOW_GetLastActionId((u8 *)flow);
        if (moveId != 0 && func_0689CA5C(moveId) == 0) {
            slot = BTL_SERVER_FLOW_DecideMoveTarget((u8 *)flow, pokeId, moveId);
            BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_ID, moveId);
            BTL_EVENT_OverwriteVar(WAZAVAR_MOVE_SLOT, slot);
        }
    }
}

/* Ancient Power, Silver Wind and Ominous Wind: returns the handler table (the registry getter). */
int *HAND_WAZA_AddAllStatBoostChance(int *handlerCount)
{
    *handlerCount = 1;
    return gAllStatBoostChanceHandlers;
}

/* Ancient Power, Silver Wind and Ominous Wind: the all-stats boost has a 10 percent chance. */
void HAND_WAZA_AllStatBoostSetChance(int factor, int flow, int pokeId)
{
    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_DEFENDER_ID) && pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID))
        BTL_EVENT_OverwriteVar(WAZAVAR_SECONDARY_RATE, 10);
}

/* Venoshock: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddVenoshock(int *handlerCount)
{
    *handlerCount = 1;
    return gVenoshockHandlers;
}

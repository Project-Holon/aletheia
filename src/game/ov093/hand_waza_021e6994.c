/*
 * file:     hand_waza_021e6994.c
 * function: HAND_WAZA_RoostGroundFlyingType, HAND_WAZA_AddFocusPunch
 * address:  0x021E6994
 * packet:   pkt_ov093_021E6994
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gFocusPunchHandlers     0x021F2734  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord  0x021C88A4  thumb  ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord  0x021C88C8  thumb  ov093
 *   BTLV_CORE_MakeSlotKind2  0x021E896C  thumb  ov093
 *   BTLV_CORE_SetSlotFlag  0x021E8BD0  thumb  ov093
 */
#include "hand_waza_021e62f4_types.h"

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *flow, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *flow, void *record);
extern int BTLV_CORE_MakeSlotKind2(u32 kind, u32 turns);
union BtlSickCont;
extern void BTLV_CORE_SetSlotFlag(union BtlSickCont *cont, int value);

#define SICK_ROOST_GROUNDED 0x18

/* Roost: add the status that removes the Flying type for the turn. */
void HAND_WAZA_RoostGroundFlyingType(int factor, void *flow, int pokeId)
{
    struct HandWazaSickRecord *sick;
    int turns = 2;
    int cont;
    u32 *contSlot;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_POKE_ID)) {
        sick = BTL_SERVER_FLOW_AllocCmdRecord(flow, HANDEX_WAZA_KIND_ADD_SICK, pokeId);
        sick->pokeId = pokeId;
        sick->flag = 1;
        sick->sickKind = SICK_ROOST_GROUNDED;
        cont = BTLV_CORE_MakeSlotKind2(1, turns);
        contSlot = &sick->sickCont;
        *contSlot = cont;
        BTLV_CORE_SetSlotFlag((union BtlSickCont *)contSlot, 1);
        BTL_SERVER_FLOW_CommitCmdRecord(flow, sick);
    }
}

extern int gFocusPunchHandlers[];
int *HAND_WAZA_AddFocusPunch(int *handlerCount);

/* Focus Punch: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddFocusPunch(int *handlerCount)
{
    *handlerCount = 1;
    return gFocusPunchHandlers;
}

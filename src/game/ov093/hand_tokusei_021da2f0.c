/*
 * file:     hand_tokusei_021da2f0.c
 * unit: yes
 * function: HAND_TOKUSEI_NaturalCureOnMemberOut, HAND_TOKUSEI_AddNaturalCure
 * address: 0x021DA2F0
 * packet: pkt_ov093_021DA2F0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gNaturalCureHandlers 0x021F07F0 data a4
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_SERVER_FLOW_AllocCmdRecord 0x021C88A4 thumb ov093
 *   BTL_SERVER_FLOW_CommitCmdRecord 0x021C88C8 thumb ov093
 * extent: includes store-and-return followers 021DA320.
 */
#include "hand_tokusei_021d9adc_types.h"

extern unsigned char gNaturalCureHandlers[];
extern int BTL_EVENT_GetVar(int);
extern void *BTL_SERVER_FLOW_AllocCmdRecord(char *flowWork, int kind, int pokeId);
extern void BTL_SERVER_FLOW_CommitCmdRecord(void *flowWork, void *record);

/* Natural Cure: when the Pokemon leaves the field, cure its status condition. */
void HAND_TOKUSEI_NaturalCureOnMemberOut(int myHandle, void *flowWork, int pokeId)
{
    struct HandExCureSick *record;
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        record = BTL_SERVER_FLOW_AllocCmdRecord(flowWork, HANDEX_KIND_CURE_SICK, pokeId);
        record->sickKind = 0x24;
        record->pokeCount = 1;
        record->pokeIds[0] = pokeId;
        record->suppressMessage = 1;
        BTL_SERVER_FLOW_CommitCmdRecord(flowWork, record);
    }
}

void *HAND_TOKUSEI_AddNaturalCure(int *handlerCount)
{
    *handlerCount = 1;
    return gNaturalCureHandlers;
}

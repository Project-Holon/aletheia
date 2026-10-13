/*
 * file:     hand_waza_021e6fc8.c
 * function: HAND_WAZA_VenoshockDoublePowerOnPoison, HAND_WAZA_AddHex
 * address:  0x021E6FC8
 * packet:   pkt_ov093_021E6FC8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   gHexHandlers     0x021F2524  data   ov093  a4
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */
#include "hand_waza_021e62f4_types.h"

struct BtlPokeParam;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *flow, int pokeId);
extern int BTL_POKEPARAM_HasSick(struct BtlPokeParam *bpp, int sickId);
extern void BTL_EVENT_MultiplyVar(int key, int ratio);

#define BTL_SICK_POISON 5

/* Venoshock: double the power when the target is poisoned. */
void HAND_WAZA_VenoshockDoublePowerOnPoison(int factor, int flow, int pokeId)
{
    int ratioShift = 4;

    if (pokeId == BTL_EVENT_GetVar(WAZAVAR_ATTACKER_ID)) {
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam((int *)flow, (u8)BTL_EVENT_GetVar(WAZAVAR_DEFENDER_ID)), BTL_SICK_POISON) != 0) {
            BTL_EVENT_MultiplyVar(WAZAVAR_POWER_RATIO, ratioShift << 11);
        }
    }
}


extern int gHexHandlers[];
int *HAND_WAZA_AddHex(int *handlerCount);

/* Hex: returns the handler table of the move (the registry getter). */
int *HAND_WAZA_AddHex(int *handlerCount)
{
    *handlerCount = 1;
    return gHexHandlers;
}

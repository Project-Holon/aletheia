/*
 * function: HAND_ITEM_GetRaiseCriticalRateHandlers
 * address: 0x021DD8FC
 * packet: pkt_ov093_021DD8FC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DD87C.c and filed here.
 *
 * symbols:
 *   gBtlItemRaiseCriticalRateHandlers 0x021F1D94 data ov093 a4
 */

int *HAND_ITEM_GetRaiseCriticalRateHandlers(int *p);
extern int gBtlItemRaiseCriticalRateHandlers[];

int *HAND_ITEM_GetRaiseCriticalRateHandlers(int *p)
{
    *p = 5;
    return gBtlItemRaiseCriticalRateHandlers;
}

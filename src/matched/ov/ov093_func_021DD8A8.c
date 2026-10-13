/*
 * function: HAND_ITEM_GetRaiseSpeedOneHandlers
 * address: 0x021DD8A8
 * packet: pkt_ov093_021DD8A8
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
 *   gBtlItemRaiseSpeedOneHandlers 0x021F1D1C data ov093 a4
 */

int *HAND_ITEM_GetRaiseSpeedOneHandlers(int *p);

/* 021DD8B4  shifted 3-arg wrapper -> HAND_ITEM_RaiseStat(..., 0x5, 1) */
extern int gBtlItemRaiseSpeedOneHandlers[];

int *HAND_ITEM_GetRaiseSpeedOneHandlers(int *p)
{
    *p = 5;
    return gBtlItemRaiseSpeedOneHandlers;
}

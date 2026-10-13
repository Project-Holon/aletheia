/*
 * function: BTL_ITEM_GetRaiseDefenseOneHandlers
 * address: 0x021DD88C
 * packet: pkt_ov093_021DD88C
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
 *   gBtlItemRaiseDefenseOneHandlers 0x021F1CF4 data ov093 a4
 */

int *BTL_ITEM_GetRaiseDefenseOneHandlers(int *p);

/* 021DD898  shifted 3-arg wrapper -> BTL_ITEM_RaiseStat(..., 0x2, 1) */
extern int gBtlItemRaiseDefenseOneHandlers[];

int *BTL_ITEM_GetRaiseDefenseOneHandlers(int *p)
{
    *p = 5;
    return gBtlItemRaiseDefenseOneHandlers;
}

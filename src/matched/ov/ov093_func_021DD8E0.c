/*
 * function: BTL_ITEM_GetRaiseSpDefenseOneHandlers
 * address: 0x021DD8E0
 * packet: pkt_ov093_021DD8E0
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
 *   gBtlItemRaiseSpDefenseOneHandlers 0x021F1D6C data ov093 a4
 */

int *BTL_ITEM_GetRaiseSpDefenseOneHandlers(int *p);

/* 021DD8EC  shifted 3-arg wrapper -> BTL_ITEM_RaiseStat(..., 0x4, 1) */
extern int gBtlItemRaiseSpDefenseOneHandlers[];

int *BTL_ITEM_GetRaiseSpDefenseOneHandlers(int *p)
{
    *p = 5;
    return gBtlItemRaiseSpDefenseOneHandlers;
}

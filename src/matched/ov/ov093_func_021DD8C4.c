/*
 * function: HAND_ITEM_GetRaiseSpAttackOneHandlers
 * address: 0x021DD8C4
 * packet: pkt_ov093_021DD8C4
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
 *   gBtlItemRaiseSpAttackOneHandlers 0x021F1D44 data ov093 a4
 */

int *HAND_ITEM_GetRaiseSpAttackOneHandlers(int *p);

/* 021DD8D0  shifted 3-arg wrapper -> HAND_ITEM_RaiseStat(..., 0x3, 1) */
extern int gBtlItemRaiseSpAttackOneHandlers[];

int *HAND_ITEM_GetRaiseSpAttackOneHandlers(int *p)
{
    *p = 5;
    return gBtlItemRaiseSpAttackOneHandlers;
}

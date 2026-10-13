/*
 * function: HAND_ITEM_GetSuperEffectiveHitRecoverHandlers
 * address: 0x021DDA1C
 * packet: pkt_ov093_021DDA1C
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
 *   gBtlItemSuperEffectiveHitRecoverHandlers 0x021F16CC data ov093 a4
 */

int *HAND_ITEM_GetSuperEffectiveHitRecoverHandlers(int *p);
extern int gBtlItemSuperEffectiveHitRecoverHandlers[];

int *HAND_ITEM_GetSuperEffectiveHitRecoverHandlers(int *p)
{
    *p = 2;
    return gBtlItemSuperEffectiveHitRecoverHandlers;
}

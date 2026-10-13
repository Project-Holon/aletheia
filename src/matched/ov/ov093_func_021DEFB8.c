/*
 * function: HAND_ITEM_GetBlackSludgeHandlers
 * address: 0x021DEFB8
 * packet: pkt_ov093_021DEFB8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DEDF8.c and filed here.
 *
 * symbols:
 *   gBlackSludgeHandlers 0x021F14B4 data ov093 a4
 */

int *HAND_ITEM_GetBlackSludgeHandlers(int *p);
extern int gBlackSludgeHandlers[];

int *HAND_ITEM_GetBlackSludgeHandlers(int *p)
{
    *p = 1;
    return gBlackSludgeHandlers;
}

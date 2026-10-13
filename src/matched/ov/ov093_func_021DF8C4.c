/*
 * function: HAND_ITEM_GetOddIncenseHandlers
 * address: 0x021DF8C4
 * packet: pkt_ov093_021DF8C4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF870.c and filed here.
 *
 * symbols:
 *   gOddIncenseHandlers 0x021F155C data ov093 a4
 */

int *HAND_ITEM_GetOddIncenseHandlers(int *p);
extern int gOddIncenseHandlers[];

int *HAND_ITEM_GetOddIncenseHandlers(int *p)
{
    *p = 1;
    return gOddIncenseHandlers;
}

/*
 * function: HAND_ITEM_GetSeaIncenseHandlers
 * address: 0x021DF8F4
 * packet: pkt_ov093_021DF8F4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF8E8.c and filed here.
 *
 * symbols:
 *   gSeaIncenseHandlers 0x021F1544 data ov093 a4
 */

int *HAND_ITEM_GetSeaIncenseHandlers(int *p);
extern int gSeaIncenseHandlers[];

int *HAND_ITEM_GetSeaIncenseHandlers(int *p)
{
    *p = 1;
    return gSeaIncenseHandlers;
}

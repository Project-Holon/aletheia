/*
 * function: HAND_ITEM_GetRoseIncenseHandlers
 * address: 0x021DF924
 * packet: pkt_ov093_021DF924
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
 *   gRoseIncenseHandlers 0x021F1414 data a4
 */

int *HAND_ITEM_GetRoseIncenseHandlers(int *p);
extern int gRoseIncenseHandlers[];

int *HAND_ITEM_GetRoseIncenseHandlers(int *p)
{
    *p = 1;
    return gRoseIncenseHandlers;
}

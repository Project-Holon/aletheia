/*
 * function: HAND_ITEM_GetSmokeBallHandlers
 * address: 0x021DF390
 * packet: pkt_ov093_021DF390
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF370.c and filed here.
 *
 * symbols:
 *   gSmokeBallHandlers 0x021F15FC data ov093 a4
 */

extern int gSmokeBallHandlers[];
int *HAND_ITEM_GetSmokeBallHandlers(int *p);

int *HAND_ITEM_GetSmokeBallHandlers(int *p)
{
    *p = 2;
    return gSmokeBallHandlers;
}

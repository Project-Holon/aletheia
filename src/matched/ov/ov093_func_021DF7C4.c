/*
 * function: HAND_ITEM_GetSharpBeakHandlers
 * address: 0x021DF7C4
 * packet: pkt_ov093_021DF7C4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF7B8.c and filed here.
 *
 * symbols:
 *   gSharpBeakHandlers 0x021F144C data ov093 a4
 */

extern int gSharpBeakHandlers[];
int *HAND_ITEM_GetSharpBeakHandlers(int *p);

int *HAND_ITEM_GetSharpBeakHandlers(int *p)
{
    *p = 1;
    return gSharpBeakHandlers;
}

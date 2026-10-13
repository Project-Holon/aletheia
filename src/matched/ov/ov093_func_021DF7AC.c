/*
 * function: HAND_ITEM_GetMysticWaterHandlers
 * address: 0x021DF7AC
 * packet: pkt_ov093_021DF7AC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DF7A0.c and filed here.
 *
 * symbols:
 *   gMysticWaterHandlers 0x021F1444 data ov093 a4
 */

extern int gMysticWaterHandlers[];
int *HAND_ITEM_GetMysticWaterHandlers(int *p);

int *HAND_ITEM_GetMysticWaterHandlers(int *p)
{
    *p = 1;
    return gMysticWaterHandlers;
}

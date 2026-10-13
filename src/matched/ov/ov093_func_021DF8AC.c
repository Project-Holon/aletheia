/*
 * function: HAND_ITEM_GetSilkScarfHandlers
 * address: 0x021DF8AC
 * packet: pkt_ov093_021DF8AC
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
 *   gSilkScarfHandlers 0x021F159C data ov093 a4
 */

int *HAND_ITEM_GetSilkScarfHandlers(int *p);
extern int gSilkScarfHandlers[];

int *HAND_ITEM_GetSilkScarfHandlers(int *p)
{
    *p = 1;
    return gSilkScarfHandlers;
}

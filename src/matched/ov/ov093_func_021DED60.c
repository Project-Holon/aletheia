/*
 * function: HAND_ITEM_GetShellBellHandlers
 * address: 0x021DED60
 * packet: pkt_ov093_021DED60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DED28.c and filed here.
 *
 * symbols:
 *   gShellBellHandlers 0x021F152C data ov093 a4
 */

int *HAND_ITEM_GetShellBellHandlers(int *p);
extern int gShellBellHandlers[];

int *HAND_ITEM_GetShellBellHandlers(int *p)
{
    *p = 1;
    return gShellBellHandlers;
}

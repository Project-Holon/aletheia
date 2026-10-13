/*
 * function: HAND_ITEM_GetLightClayHandlers
 * address: 0x021DEDEC
 * packet: pkt_ov093_021DEDEC
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
 *   gLightClayHandlers 0x021F143C data ov093 a4
 */

int *HAND_ITEM_GetLightClayHandlers(int *p);
extern int gLightClayHandlers[];

int *HAND_ITEM_GetLightClayHandlers(int *p)
{
    *p = 1;
    return gLightClayHandlers;
}

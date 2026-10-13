/*
 * function: HAND_ITEM_GetEjectButtonHandlers
 * address: 0x021DFE1C
 * packet: pkt_ov093_021DFE1C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DFCE8.c and filed here.
 *
 * symbols:
 *   gHandItemEjectButtonHandlers 0x021F176C data ov093 a4
 */

int *HAND_ITEM_GetEjectButtonHandlers(int *p);
extern int gHandItemEjectButtonHandlers[];

int *HAND_ITEM_GetEjectButtonHandlers(int *p)
{
    *p = 2;
    return gHandItemEjectButtonHandlers;
}

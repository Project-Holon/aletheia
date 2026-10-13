/*
 * function: HAND_ITEM_GetCellBatteryHandlers
 * address: 0x021DFD98
 * packet: pkt_ov093_021DFD98
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
 *   gHandItemCellBatteryHandlers 0x021F174C data ov093 a4
 */

int *HAND_ITEM_GetCellBatteryHandlers(int *p);
extern int gHandItemCellBatteryHandlers[];

int *HAND_ITEM_GetCellBatteryHandlers(int *p)
{
    *p = 2;
    return gHandItemCellBatteryHandlers;
}

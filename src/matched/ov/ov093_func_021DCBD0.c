/*
 * function: BTL_HANDLER_TOKUSEI_AddHarvest
 * address: 0x021DCBD0
 * packet: pkt_ov093_021DCBD0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DCAE8.c and filed here.
 *
 * symbols:
 *   gHandlerTableHarvest 0x021F0728 data ov093 a4
 */

int *BTL_HANDLER_TOKUSEI_AddHarvest(int *p);
extern int gHandlerTableHarvest[];

int *BTL_HANDLER_TOKUSEI_AddHarvest(int *p)
{
    *p = 1;
    return gHandlerTableHarvest;
}

/*
 * function: BTL_HANDLER_ITEM_AddBerryJuice
 * address: 0x021DD570
 * packet: pkt_ov093_021DD570
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
 *   gHandlerTableBerryJuice 0x021F1AA4 data ov093 a4
 */

int *BTL_HANDLER_ITEM_AddBerryJuice(int *p);
extern int gHandlerTableBerryJuice[];

int *BTL_HANDLER_ITEM_AddBerryJuice(int *p)
{
    *p = 4;
    return gHandlerTableBerryJuice;
}

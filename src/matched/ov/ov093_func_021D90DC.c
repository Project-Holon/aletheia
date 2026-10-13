/*
 * function: BTL_ABILITY_GetRivalryHandlers
 * address: 0x021D90DC
 * packet: pkt_ov093_021D90DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D8D40.c and filed here.
 *
 * symbols:
 *   gRivalryHandlerTable 0x021F07E0 data ov093 a4
 */

int *BTL_ABILITY_GetRivalryHandlers(int *p);
extern int gRivalryHandlerTable[];

int *BTL_ABILITY_GetRivalryHandlers(int *p)
{
    *p = 1;
    return gRivalryHandlerTable;
}

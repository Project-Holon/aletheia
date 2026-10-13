/*
 * function: BTL_ABILITY_GetHeatproofHandlers
 * address: 0x021DA89C
 * packet: pkt_ov093_021DA89C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DA624_p01.c and filed here.
 *
 * symbols:
 *   gHeatproofHandlerTable 0x021F09D0 data ov093 a4
 */

int *BTL_ABILITY_GetHeatproofHandlers(int *p);
extern int gHeatproofHandlerTable[];

int *BTL_ABILITY_GetHeatproofHandlers(int *p)
{
    *p = 2;
    return gHeatproofHandlerTable;
}

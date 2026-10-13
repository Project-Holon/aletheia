/*
 * function: BTL_ABILITY_GetWonderGuardHandlers
 * address: 0x021DAD20
 * packet: pkt_ov093_021DAD20
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
 *   gWonderGuardHandlerTable 0x021F0660 data ov093 a4
 */

int *BTL_ABILITY_GetWonderGuardHandlers(int *p);
extern int gWonderGuardHandlerTable[];

int *BTL_ABILITY_GetWonderGuardHandlers(int *p)
{
    *p = 1;
    return gWonderGuardHandlerTable;
}

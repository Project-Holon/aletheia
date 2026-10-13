/*
 * function: BTL_ABILITY_GetSoundproofHandlers
 * address: 0x021DABE8
 * packet: pkt_ov093_021DABE8
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
 *   gSoundproofHandlerTable 0x021F0788 data ov093 a4
 */

int *BTL_ABILITY_GetSoundproofHandlers(int *p);
extern int gSoundproofHandlerTable[];

int *BTL_ABILITY_GetSoundproofHandlers(int *p)
{
    *p = 1;
    return gSoundproofHandlerTable;
}

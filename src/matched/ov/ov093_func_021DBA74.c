/*
 * function: BTL_TOKUSEI_GetArenaTrapHandlers
 * address: 0x021DBA74
 * packet: pkt_ov093_021DBA74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DB9AC.c and filed here.
 *
 * symbols:
 *   gArenaTrapHandlers 0x021F06E0 data ov093 a4
 */

int *BTL_TOKUSEI_GetArenaTrapHandlers(int *p);
extern int gArenaTrapHandlers[];

int *BTL_TOKUSEI_GetArenaTrapHandlers(int *p)
{
    *p = 1;
    return gArenaTrapHandlers;
}

/*
 * function: BTL_TOKUSEI_GetIceBodyHandlers
 * address: 0x021D9858
 * packet: pkt_ov093_021D9858
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D93D8.c and filed here.
 *
 * symbols:
 *   gIceBodyHandlers 0x021F05C0 data ov093 a4
 */

int *BTL_TOKUSEI_GetIceBodyHandlers(int *p);
extern int gIceBodyHandlers[];

int *BTL_TOKUSEI_GetIceBodyHandlers(int *p)
{
    *p = 1;
    return gIceBodyHandlers;
}

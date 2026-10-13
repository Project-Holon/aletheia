/*
 * function: BTL_TOKUSEI_GetDrizzleHandlers
 * address: 0x021D9754
 * packet: pkt_ov093_021D9754
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
 *   gDrizzleHandlers 0x021F08D0 data ov093 a4
 */

int *BTL_TOKUSEI_GetDrizzleHandlers(int *p);
extern int gDrizzleHandlers[];

int *BTL_TOKUSEI_GetDrizzleHandlers(int *p)
{
    *p = 2;
    return gDrizzleHandlers;
}

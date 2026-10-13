/*
 * function: HAND_TOKUSEI_GetPlusMinusHandlers
 * address: 0x021D8D90
 * packet: pkt_ov093_021D8D90
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
 *   gPlusMinusHandlers 0x021F06A0 data ov093 a4
 */

int *HAND_TOKUSEI_GetPlusMinusHandlers(int *p);

/*
 * lever: BTL_SERVER_FLOW_CollectAlivePokeIds returns a u8 count, so n is a u8 and the count is spilled and reloaded.
 */
extern int gPlusMinusHandlers[];

int *HAND_TOKUSEI_GetPlusMinusHandlers(int *p)
{
    *p = 1;
    return gPlusMinusHandlers;
}

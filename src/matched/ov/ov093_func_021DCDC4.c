/*
 * function: BTL_HANDLER_TOKUSEI_AddIllusion
 * address: 0x021DCDC4
 * packet: pkt_ov093_021DCDC4
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
 *   gHandlerTableIllusion 0x021F0B60 data ov093 a4
 */

int *BTL_HANDLER_TOKUSEI_AddIllusion(int *p);
extern int gHandlerTableIllusion[];

int *BTL_HANDLER_TOKUSEI_AddIllusion(int *p)
{
    *p = 3;
    return gHandlerTableIllusion;
}

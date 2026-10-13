/*
 * function: BTL_HANDLER_TOKUSEI_AddMagicBounce
 * address: 0x021DCB2C
 * packet: pkt_ov093_021DCB2C
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
 *   gHandlerTableMagicBounce 0x021F0AD0 data ov093 a4
 */

int *BTL_HANDLER_TOKUSEI_AddMagicBounce(int *p);
extern int gHandlerTableMagicBounce[];

int *BTL_HANDLER_TOKUSEI_AddMagicBounce(int *p)
{
    *p = 3;
    return gHandlerTableMagicBounce;
}

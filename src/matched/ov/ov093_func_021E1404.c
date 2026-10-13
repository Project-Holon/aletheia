/*
 * function: HAND_WAZA_AddWhirlpool
 * address: 0x021E1404
 * packet: pkt_ov093_021E1404
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E12A4.c and filed here.
 *
 * symbols:
 *   gWhirlpoolHandlers 0x021F2D98 data ov093 a4
 */

int *HAND_WAZA_AddWhirlpool(int *p);
extern int gWhirlpoolHandlers[];

int *HAND_WAZA_AddWhirlpool(int *p)
{
    *p = 4;
    return gWhirlpoolHandlers;
}

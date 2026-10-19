/*
 * function: HAND_TOKUSEI_GetBigPecksHandlers
 * address: 0x021DC5F8
 * packet: pkt_ov093_021DC5F8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DC57C.c and filed here.
 *
 * symbols:
 *   gIndirectGuardCause2Handlers 0x021F0940 data ov093 a4
 */

int *HAND_TOKUSEI_GetBigPecksHandlers(int *p);
extern int gIndirectGuardCause2Handlers[];

int *HAND_TOKUSEI_GetBigPecksHandlers(int *p)
{
    *p = 2;
    return gIndirectGuardCause2Handlers;
}

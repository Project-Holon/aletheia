/*
 * function: HAND_WAZA_RageGetHandlers
 * address: 0x021E208C
 * packet: pkt_ov093_021E208C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E203C.c and filed here.
 *
 * symbols:
 *   gRageHandlers 0x021F2C78 data ov093 a4
 */

int *HAND_WAZA_RageGetHandlers(int *p);
extern int gRageHandlers[];

int *HAND_WAZA_RageGetHandlers(int *p)
{
    *p = 3;
    return gRageHandlers;
}

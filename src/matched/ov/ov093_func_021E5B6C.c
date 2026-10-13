/*
 * function: HAND_WAZA_GetBatonPassHandlers
 * address: 0x021E5B6C
 * packet: pkt_ov093_021E5B6C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E5B78.c and filed here.
 *
 * symbols:
 *   gBatonPassHandlers 0x021F2454 data ov093 a4
 */

extern int gBatonPassHandlers[];
int *HAND_WAZA_GetBatonPassHandlers(int *p);

int *HAND_WAZA_GetBatonPassHandlers(int *p)
{
    *p = 1;
    return gBatonPassHandlers;
}

/*
 * function: HAND_WAZA_GetRecycleHandlers
 * address: 0x021E3F38
 * packet: pkt_ov093_021E3F38
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E3B64.c and filed here.
 *
 * symbols:
 *   gRecycleHandlers 0x021F27CC data ov093 a4
 */

int *HAND_WAZA_GetRecycleHandlers(int *p);
extern int gRecycleHandlers[];

int *HAND_WAZA_GetRecycleHandlers(int *p)
{
    *p = 1;
    return gRecycleHandlers;
}

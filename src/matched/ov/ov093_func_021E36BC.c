/*
 * function: HAND_WAZA_AddThief
 * address: 0x021E36BC
 * packet: pkt_ov093_021E36BC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E3420.c and filed here.
 *
 * symbols:
 *   gThiefHandlers 0x021F2A98 data ov093 a4
 */

int *HAND_WAZA_AddThief(int *p);
extern int gThiefHandlers[];

int *HAND_WAZA_AddThief(int *p)
{
    *p = 2;
    return gThiefHandlers;
}

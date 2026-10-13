/*
 * function: HAND_WAZA_AddSpikes
 * address: 0x021E5460
 * packet: pkt_ov093_021E5460
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E53E4.c and filed here.
 *
 * symbols:
 *   gSpikesHandlers 0x021F2604 data ov093 a4
 */

int *HAND_WAZA_AddSpikes(int *p);
extern int gSpikesHandlers[];

int *HAND_WAZA_AddSpikes(int *p)
{
    *p = 1;
    return gSpikesHandlers;
}

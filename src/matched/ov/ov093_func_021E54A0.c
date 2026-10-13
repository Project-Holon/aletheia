/*
 * function: HAND_WAZA_AddToxicSpikes
 * address: 0x021E54A0
 * packet: pkt_ov093_021E54A0
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
 *   gToxicSpikesHandlers 0x021F243C data ov093 a4
 */

int *HAND_WAZA_AddToxicSpikes(int *p);
extern int gToxicSpikesHandlers[];

int *HAND_WAZA_AddToxicSpikes(int *p)
{
    *p = 1;
    return gToxicSpikesHandlers;
}

/*
 * function: HAND_WAZA_GetEndureHandlers
 * address: 0x021E3A6C
 * packet: pkt_ov093_021E3A6C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E3A48.c and filed here.
 *
 * symbols:
 *   gEndureHandlers 0x021F2FC8 data ov093 a4
 */

int *HAND_WAZA_GetEndureHandlers(int *p);
extern int gEndureHandlers[];

int *HAND_WAZA_GetEndureHandlers(int *p)
{
    *p = 6;
    return gEndureHandlers;
}

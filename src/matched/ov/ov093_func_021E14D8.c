/*
 * function: HAND_WAZA_AddSonicBoom
 * address: 0x021E14D8
 * packet: pkt_ov093_021E14D8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E1478.c and filed here.
 *
 * symbols:
 *   gSonicBoomHandlers 0x021F256C data ov093 a4
 */

int *HAND_WAZA_AddSonicBoom(int *p);
extern int gSonicBoomHandlers[];

int *HAND_WAZA_AddSonicBoom(int *p)
{
    *p = 1;
    return gSonicBoomHandlers;
}

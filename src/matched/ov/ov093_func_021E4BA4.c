/*
 * function: HAND_WAZA_AddPsychUp
 * address: 0x021E4BA4
 * packet: pkt_ov093_021E4BA4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E492C.c and filed here.
 *
 * symbols:
 *   gPsychUpHandlers 0x021F25BC data ov093 a4
 */

int *HAND_WAZA_AddPsychUp(int *p);
extern int gPsychUpHandlers[];

int *HAND_WAZA_AddPsychUp(int *p)
{
    *p = 1;
    return gPsychUpHandlers;
}

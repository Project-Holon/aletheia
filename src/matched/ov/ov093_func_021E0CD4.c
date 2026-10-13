/*
 * function: HAND_WAZA_GetTrapHandlers
 * address: 0x021E0CD4
 * packet: pkt_ov093_021E0CD4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0C8C.c and filed here.
 *
 * symbols:
 *   gTrapHandlers 0x021F2644 data ov093 a4
 */

int *HAND_WAZA_GetTrapHandlers(int *p);
extern int gTrapHandlers[];

int *HAND_WAZA_GetTrapHandlers(int *p)
{
    *p = 1;
    return gTrapHandlers;
}

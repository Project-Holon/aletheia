/*
 * function: HAND_WAZA_GetMimicHandlers
 * address: 0x021E098C
 * packet: pkt_ov093_021E098C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E072C_p02.c and filed here.
 *
 * symbols:
 *   gMimicHandlers 0x021F280C data ov093 a4
 */

int *HAND_WAZA_GetMimicHandlers(int *p);
extern int gMimicHandlers[];

int *HAND_WAZA_GetMimicHandlers(int *p)
{
    *p = 1;
    return gMimicHandlers;
}

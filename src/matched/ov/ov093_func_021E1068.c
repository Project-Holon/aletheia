/*
 * function: HAND_WAZA_GetCaptivateHandlers
 * address: 0x021E1068
 * packet: pkt_ov093_021E1068
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0F50.c and filed here.
 *
 * symbols:
 *   gCaptivateHandlers 0x021F266C data ov093 a4
 */

int *HAND_WAZA_GetCaptivateHandlers(int *p);
extern int gCaptivateHandlers[];

int *HAND_WAZA_GetCaptivateHandlers(int *p)
{
    *p = 1;
    return gCaptivateHandlers;
}

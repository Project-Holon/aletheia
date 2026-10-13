/*
 * function: HAND_WAZA_GetCurseHandlers
 * address: 0x021E0DF4
 * packet: pkt_ov093_021E0DF4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0DC4.c and filed here.
 *
 * symbols:
 *   gCurseHandlers 0x021F28D8 data ov093 a4
 */

int *HAND_WAZA_GetCurseHandlers(int *p);
extern int gCurseHandlers[];

int *HAND_WAZA_GetCurseHandlers(int *p)
{
    *p = 2;
    return gCurseHandlers;
}

/*
 * function: HAND_WAZA_GetSketchHandlers
 * address: 0x021E0A74
 * packet: pkt_ov093_021E0A74
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0A74.c and filed here.
 *
 * symbols:
 *   gSketchHandlers 0x021F264C data ov093 a4
 */

extern int gSketchHandlers[];
int *HAND_WAZA_GetSketchHandlers(int *p);

int *HAND_WAZA_GetSketchHandlers(int *p)
{
    *p = 1;
    return gSketchHandlers;
}

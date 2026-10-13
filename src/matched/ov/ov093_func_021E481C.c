/*
 * function: HAND_WAZA_AddDisable
 * address: 0x021E481C
 * packet: pkt_ov093_021E481C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E4754.c and filed here.
 *
 * symbols:
 *   gDisableHandlers 0x021F2764 data ov093 a4
 */

int *HAND_WAZA_AddDisable(int *p);
extern int gDisableHandlers[];

int *HAND_WAZA_AddDisable(int *p)
{
    *p = 1;
    return gDisableHandlers;
}

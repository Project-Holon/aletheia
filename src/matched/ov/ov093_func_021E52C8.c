/*
 * function: HAND_WAZA_AddReflect
 * address: 0x021E52C8
 * packet: pkt_ov093_021E52C8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E508C.c and filed here.
 *
 * symbols:
 *   gReflectHandlers 0x021F25FC data ov093 a4
 */

int *HAND_WAZA_AddReflect(int *p);
extern int gReflectHandlers[];

int *HAND_WAZA_AddReflect(int *p)
{
    *p = 1;
    return gReflectHandlers;
}

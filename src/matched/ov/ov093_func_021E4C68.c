/*
 * function: HAND_WAZA_AddHeartSwap
 * address: 0x021E4C68
 * packet: pkt_ov093_021E4C68
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E4BB0.c and filed here.
 *
 * symbols:
 *   gHeartSwapHandlers 0x021F275C data ov093 a4
 */

int *HAND_WAZA_AddHeartSwap(int *p);
extern int gHeartSwapHandlers[];

int *HAND_WAZA_AddHeartSwap(int *p)
{
    *p = 1;
    return gHeartSwapHandlers;
}

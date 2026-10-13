/*
 * function: HAND_WAZA_AddSpite
 * address: 0x021E4AF4
 * packet: pkt_ov093_021E4AF4
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
 *   gSpiteHandlers 0x021F273C data ov093 a4
 */

int *HAND_WAZA_AddSpite(int *p);
extern int gSpiteHandlers[];

int *HAND_WAZA_AddSpite(int *p)
{
    *p = 1;
    return gSpiteHandlers;
}

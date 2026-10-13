/*
 * function: HAND_WAZA_AddCopycat
 * address: 0x021E6F30
 * packet: pkt_ov093_021E6F30
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E6F14_p01.c and filed here.
 *
 * symbols:
 *   gCopycatHandlers 0x021F26C4 data a4
 */

int *HAND_WAZA_AddCopycat(int *p);
extern int gCopycatHandlers[];

int *HAND_WAZA_AddCopycat(int *p)
{
    *p = 1;
    return gCopycatHandlers;
}

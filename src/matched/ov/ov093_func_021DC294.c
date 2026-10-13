/*
 * function: func_021DC294
 * address: 0x021DC294
 * packet: pkt_ov093_021DC294
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DC13C.c and filed here.
 *
 * symbols:
 *   gFlareBoostHandlers 0x021F0620 data ov093 a4
 */

int *func_021DC294(int *p);
extern int gFlareBoostHandlers[];

int *func_021DC294(int *p)
{
    *p = 1;
    return gFlareBoostHandlers;
}

/*
 * function: BG_SYS_SetSubPlaneVisible
 * address:  0x02043598
 * packet:   pkt_020428E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gVisiblePlane  0x02146A48  data
 *
 * The engine-B half of the visible-plane toggle: if the requested state
 * already holds, return; otherwise flip the bit in the software copy at
 * gVisiblePlane[0] and rewrite bits 8..12 of GXS_DISPCNT (0x04001000) from
 * it.  The engine-A twin at 0x020434DC is the same code against
 * gVisiblePlane[1] and 0x04000000; that one is materialised with a `mov`
 * because 0x04000000 is an ARM rotated immediate while 0x04001000 is not
 * and costs a pool word.
 *
 * The register address is a cast constant, not a relocation, so this file's
 * only attestable site is gVisiblePlane.
 */

typedef unsigned int u32;

extern u32 gVisiblePlane[2];

void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable)
{
    if (enable == 1) {
        if (gVisiblePlane[0] & mask) {
            return;
        }
    } else if (!(gVisiblePlane[0] & mask)) {
        return;
    }

    gVisiblePlane[0] ^= mask;
    *(volatile u32 *)0x04001000 =
        (*(volatile u32 *)0x04001000 & ~0x1f00) | (gVisiblePlane[0] << 8);
}

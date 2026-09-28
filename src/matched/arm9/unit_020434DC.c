/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: sub_020434DC, sub_02043534, sub_02043558
 * address:  0x020434DC
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
 * The engine-A visible-plane trio, against gVisiblePlane[1] and DISPCNT at
 * 0x04000000: toggle one plane only if the requested state differs, replace
 * the whole set, and reset to the one plane in bit 4.  The register address
 * is a rotated ARM immediate here (`mov r2, #0x4000000`), where the
 * engine-B twins at 0x02043598 / 0x020435F4 must pool 0x04001000.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020434DC.c \
 *       --addr 0x020434DC --arm
 */

typedef unsigned int u32;

extern u32 gVisiblePlane[2];

void sub_020434DC(u32 mask, u32 enable)
{
    if (enable == 1) {
        if (gVisiblePlane[1] & mask) {
            return;
        }
    } else if (!(gVisiblePlane[1] & mask)) {
        return;
    }

    gVisiblePlane[1] ^= mask;
    *(volatile u32 *)0x04000000 =
        (*(volatile u32 *)0x04000000 & ~0x1f00) | (gVisiblePlane[1] << 8);
}

void sub_02043534(u32 planes)
{
    gVisiblePlane[1] = planes;
    *(volatile u32 *)0x04000000 =
        (*(volatile u32 *)0x04000000 & ~0x1f00) | (planes << 8);
}

void sub_02043558(void)
{
    gVisiblePlane[0] &= 0x10;
}

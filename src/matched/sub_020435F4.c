/*
 * function: sub_020435F4
 * address:  0x020435F4
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
 * Engine-B "replace the whole visible-plane set": store the software copy
 * and rewrite bits 8..12 of GXS_DISPCNT from it.  Twin of sub_02043534.
 */

typedef unsigned int u32;

extern u32 gVisiblePlane[2];

void sub_020435F4(u32 planes)
{
    gVisiblePlane[0] = planes;
    *(volatile u32 *)0x04001000 =
        (*(volatile u32 *)0x04001000 & ~0x1f00) | (planes << 8);
}

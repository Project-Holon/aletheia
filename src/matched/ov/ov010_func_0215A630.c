/*
 * function: func_0215A630
 * address:  0x0215A630
 * packet:   pkt_ov010_0215A630
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter: word at +0x100 of the object whose pointer sits at +0x20.
 * Unlabelled leaf (leaf of func_021B0480).
 *
 * symbols:
 *   (none)
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

u32 func_0215A630(u8 *p)
{
    return *(u32 *)((u8 *)*(u32 *)(p + 0x20) + 0x100);
}

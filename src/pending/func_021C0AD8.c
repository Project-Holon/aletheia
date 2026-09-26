/*
 * function: func_021C0AD8
 * address:  0x021C0AD8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   d_021C3F64  0x021C3F64  data  ov217
 *   d_021C3F9C  0x021C3F9C  data  ov217
 *

 * Still MATCH: d_021C3F64 resolves as sole-ref/data, but d_021C3F9C is
 * contested -- another overlay in the window starts an object at 0x021C3F9C,
 * so the ov217 hint alone cannot carry it, and the function loads no
 * overlay_id site.  Needs a second witness for 0x021C3F9C (or the overlay
 * contest broken); all 24 bytes and the other two sites reproduce.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_0204A48C();
extern u8 d_021C3F64[];
extern u8 d_021C3F9C[];
void func_021C0AD8(u32 a0)
{
    func_0204A48C(d_021C3F64, d_021C3F9C, *(u16*)(((u8*)a0 + 0)));
}


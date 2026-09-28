/*
 * function: func_021C4214
 * address:  0x021C4214
 * packet:   pkt_021C4214
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B800  0x0204B800  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0204B800(void *, int);

void func_021C4214(u8 *p, u32 v)
{
    func_0204B800(*(void **)(p + 4), (u8)v);
}

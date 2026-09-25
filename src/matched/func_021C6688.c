/*
 * function: func_021C6688
 * address:  0x021C6688
 * packet:   pkt_021C6688
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C666C  0x021C666C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C666C(u8 *, int);

void func_021C6688(u8 *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        func_021C666C(p, i);
}

/*
 * function: func_021C0D5C
 * address:  0x021C0D5C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Indexed getter, tail call to func_021C2A00.
 *
 * symbols:
 *   func_021C2A00  0x021C2A00  thumb  ov217

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C2A00(u32);
void func_021C0D5C(u8 *p, u32 i)
{
    func_021C2A00(*(u32 *)(p + i * 4 + 0x2c));
}


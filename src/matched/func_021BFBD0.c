/*
 * function: func_021BFBD0
 * address:  0x021BFBD0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 24)) to func_0201ED04.
 *
 * symbols:
 *   func_0201ED04  0x0201ED04  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0201ED04(u32);

void func_021BFBD0(u8 *a0)
{
    func_0201ED04((u32)(*(u32*)(a0 + 24)));
}


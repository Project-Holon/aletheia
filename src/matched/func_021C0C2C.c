/*
 * function: func_021C0C2C
 * address:  0x021C0C2C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 36)) to func_0204B3B4.
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0204B3B4(u32);

void func_021C0C2C(u8 *a0)
{
    func_0204B3B4((u32)(*(u32*)(a0 + 36)));
}


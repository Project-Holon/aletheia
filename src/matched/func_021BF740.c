/*
 * function: func_021BF740
 * address:  0x021BF740
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to func_021C09B4.
 *
 * symbols:
 *   func_021C09B4  0x021C09B4  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C09B4(u32);

void func_021BF740(u8 *a0)
{
    func_021C09B4((u32)(*(u32*)(a0)));
}


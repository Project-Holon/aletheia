/*
 * function: func_021C1154
 * address:  0x021C1154
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) a0, 1 to func_021C16DC.
 *
 * symbols:
 *   func_021C16DC  0x021C16DC  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C16DC(u32 *p, u32 a1);

void func_021C1154(u8 *h)
{
    func_021C16DC((u32 *)h, 1);
}



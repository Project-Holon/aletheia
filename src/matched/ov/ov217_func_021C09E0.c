/*
 * function: func_021C09E0
 * address:  0x021C09E0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) a0, 0 to func_021C0D5C.
 *
 * symbols:
 *   func_021C0D5C  0x021C0D5C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C0D5C(u8 *p, u32 i);

void func_021C09E0(u32 a0, u32 a1)
{
    func_021C0D5C((u8 *)a0, 0);
}


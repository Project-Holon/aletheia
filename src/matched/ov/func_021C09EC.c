/*
 * function: func_021C09EC
 * address:  0x021C09EC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) a0, 0 to func_021C0D6C.
 *
 * symbols:
 *   func_021C0D6C  0x021C0D6C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C0D6C(u32, u32);

void func_021C09EC(u32 a0, u32 a1)
{
    func_021C0D6C(a0, 0);
}


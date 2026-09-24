/*
 * function: func_021C09D0
 * address:  0x021C09D0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards its first argument to func_021C0D7C.
 *
 * symbols:
 *   func_021C0D7C  0x021C0D7C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C0D7C(u32);

void func_021C09D0(u32 a0)
{
    func_021C0D7C(a0);
}


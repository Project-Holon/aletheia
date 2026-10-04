/*
 * function: func_021C2A10
 * address:  0x021C2A10
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards its first argument to func_021C2D9C.
 *
 * symbols:
 *   func_021C2D9C  0x021C2D9C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_021C2D9C(u32 *p);

void func_021C2A10(u32 a0)
{
    func_021C2D9C((u32 *)a0);
}


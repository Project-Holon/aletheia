/*
 * function: func_021C20CC
 * address:  0x021C20CC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) a0, 1 to func_021C218C.
 *
 * symbols:
 *   func_021C218C  0x021C218C  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C218C(void *p, u32 v);

void func_021C20CC(u32 a0)
{
    func_021C218C((void *)a0, 1);
}


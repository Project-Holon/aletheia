/*
 * function: func_021C2A00
 * address:  0x021C2A00
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer to func_021C2A28.
 *
 * symbols:
 *   func_021C2A28  0x021C2A28  thumb  ov217

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C2A28(void *p);
void func_021C2A00(u32 a0, u32 a1)
{
    func_021C2A28((void *)a0);
}


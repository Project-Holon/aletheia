/*
 * function: func_021C1184
 * address:  0x021C1184
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to func_021C1A58.
 *
 * symbols:
 *   func_021C1A58  0x021C1A58  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021C1A58(void *h, u32 v);

void func_021C1184(u8 *h, u32 v)
{
    func_021C1A58(h, v);
}


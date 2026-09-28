/*
 * function: func_021F7DA8
 * address:  0x021F7DA8
 * packet:   pkt_021F7DA8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9968  0x021F9968  thumb  ov135

 * Publish the u32 at +0xde4, the 0xffff sentinel at +0xbc and latch state 0xc.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F9968(u32 v, u32 k);

int func_021F7DA8(u8 *p)
{
    func_021F9968(*(u32 *)(p + 0xde4), 2);
    *(u16 *)(p + 0xbc) = 0xffff;
    *(u32 *)(p + 0x28) = 0xc;
    return 2;
}

/*
 * function: func_021F7E9C
 * address:  0x021F7E9C
 * packet:   pkt_021F7E9C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4BE0  0x021F4BE0  thumb  ov135

 * State setter: build with the fixed 0x14/0x126/0x3/0x0 argument pair and latch state 0xf.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);

int func_021F7E9C(u8 *p)
{
    func_021F4BE0((u32)p, 0x14, 0x126, 0x3, 0x0);
    *(u32 *)(p + 0x28) = 0xf;
    return 2;
}

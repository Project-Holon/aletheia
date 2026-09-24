/*
 * function: func_022007E0
 * address:  0x022007E0
 * packet:   pkt_022007E0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4BE0  0x021F4BE0  thumb  ov135

 * State setter: build with the fixed 0x12/0x102/0x3/0x1 argument pair and latch state 0xd.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F4BE0(u8 *p, u32 a, u32 b, u32 c, u32 d);

int func_022007E0(u8 *p)
{
    func_021F4BE0(p, 0x12, 0x102, 0x3, 0x1);
    *(u32 *)(p + 0x28) = 0xd;
    return 2;
}

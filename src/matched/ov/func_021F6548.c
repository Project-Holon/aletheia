/*
 * function: func_021F6548
 * address:  0x021F6548
 * packet:   pkt_021F6548
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4BE0  0x021F4BE0  thumb  ov135

 * State setter: build with the fixed 0x12/0x1ad/0x8/0x1 argument pair and latch state 0x10.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F4BE0(u32 a, u32 b, u32 c, u32 d, u8 e);

int func_021F6548(u8 *p)
{
    func_021F4BE0((u32)p, 0x12, 0x1ad, 0x8, 0x1);
    *(u32 *)(p + 0x28) = 0x10;
    return 2;
}

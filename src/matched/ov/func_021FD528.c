/*
 * function: func_021FD528
 * address:  0x021FD528
 * packet:   pkt_021FD528
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4BF8  0x021F4BF8  thumb  ov135

 * Build with the fixed 0x12/0x12e/3/4/1 argument pair and latch state 5.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021F4BF8(u8 *p, u32 a, u32 b, u32 c, u32 d, u32 e);

int func_021FD528(u8 *p)
{
    func_021F4BF8(p, 0x12, 0x12e, 3, 4, 1);
    *(u32 *)(p + 0x28) = 5;
    return 2;
}

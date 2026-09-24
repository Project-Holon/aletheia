/*
 * function: func_021F6178
 * address:  0x021F6178
 * packet:   pkt_021F6178
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4D50  0x021F4D50  thumb  ov135

 * Create the resource, register the three 5d/5e/5f entries and latch state 0xa.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 func_0201F81C(u32 a, u32 b);
extern void func_0201F878(u32 a, u32 b, u32 c, u32 d, u32 e);
extern void func_021F4D50(u8 *p, u32 a, u32 b, u32 c);

int func_021F6178(u8 *p)
{
    *(u32 *)(p + 0xde8) = func_0201F81C(3, 0x48);
    func_0201F878(*(u32 *)(p + 0xde8), *(u32 *)(p + 0xb6c), 0x5d, 1, 0x48);
    func_0201F878(*(u32 *)(p + 0xde8), *(u32 *)(p + 0xb6c), 0x5e, 2, 0x48);
    func_0201F878(*(u32 *)(p + 0xde8), *(u32 *)(p + 0xb6c), 0x5f, 3, 0x48);
    func_021F4D50(p, 0, 3, 0x14);
    *(u32 *)(p + 0x28) = 0xa;
    return 2;
}

/*
 * function: func_022004A0
 * address:  0x022004A0
 * packet:   pkt_022004A0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *

 *
 * Push the fixed 6/1/0x48 request with the caller's mode and stamp 3.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void func_0202208C(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);

int func_022004A0(u8 *p, u32 mode)
{
    func_0202208C(3, mode, 1, 0, 6, 1, 0x48);
    *(u32 *)(p + 0x28) = 3;
    return 2;
}

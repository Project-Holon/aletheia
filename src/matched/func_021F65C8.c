/*
 * function: func_021F65C8
 * address:  0x021F65C8
 * packet:   pkt_021F65C8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F5CD4  0x021F5CD4  thumb  ov135

 * While the +0xbfc buffer is free, feed the mode word at +0x20 to the dispatch.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern u32 func_0204B98C(u32 v);
extern void func_021F5CD4(u8 *p, u32 k);

int func_021F65C8(u8 *p)
{
    if (func_0204B98C(*(u32 *)(p + 0xbfc)) == 0) {
        func_021F5CD4(p, *(u32 *)(p + 0x20));
    }
    return 2;
}

/*
 * function: func_022014B8
 * address:  0x022014B8
 * packet:   pkt_022014B8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * State 9 with the slot cleared and the u16 at +0x32 set.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021C8770(u8 *p);

int func_022014B8(u8 *p)
{
    func_021C8770(p);
    *(u32 *)(p + 0x28) = 9;
    *(u32 *)(p + 0xf8c) = 0;
    *(u16 *)(p + 0x32) = 1;
    return 2;
}

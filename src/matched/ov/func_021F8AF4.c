/*
 * function: func_021F8AF4
 * address:  0x021F8AF4
 * packet:   pkt_021F8AF4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * Hand the object over, clear the +0xf8c slot and latch 1.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern void func_021C8DA0(u8 *p);

int func_021F8AF4(u8 *p)
{
    func_021C8DA0(p);
    *(u32 *)(p + 0xf8c) = 0;
    return 1;
}

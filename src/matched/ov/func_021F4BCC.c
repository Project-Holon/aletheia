/*
 * function: func_021F4BCC
 * address:  0x021F4BCC
 * packet:   pkt_021F4BCC
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 * Release the 0x10 channel on both hardware blocks.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void func_020434DC(u32 a, u32 b);
extern void func_02043598(u32 a, u32 b);

void func_021F4BCC(u8 *p)
{
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}

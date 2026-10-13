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
 *   BG_SYS_SetSubPlaneVisible  0x02043598  arm  arm9
 *   BG_SYS_SetMainPlaneVisible  0x020434DC  arm  arm9
 *

 * Release the 0x10 channel on both hardware blocks.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern void BG_SYS_SetMainPlaneVisible(u32 a, u32 b);
extern void BG_SYS_SetSubPlaneVisible(u32 a, u32 b);

void func_021F4BCC(u8 *p)
{
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

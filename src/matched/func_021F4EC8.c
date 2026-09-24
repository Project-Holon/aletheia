/*
 * function: func_021F4EC8
 * address:  0x021F4EC8
 * packet:   pkt_021F4EC8
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
 * Save the current value at +0x10 into +0x1c and move +0x14 down into +0x10.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
void func_021F4EC8(u8 *p)
{
    *(u32 *)(p + 0x1c) = *(u32 *)(p + 0x10);
    *(u32 *)(p + 0x10) = *(u32 *)(p + 0x14);
}

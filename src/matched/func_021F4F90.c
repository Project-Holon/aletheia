/*
 * function: func_021F4F90
 * address:  0x021F4F90
 * packet:   pkt_021F4F90
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *

 *
 * Set the u16 flag at +0xeb2 and clear the one at +0xeb0.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021F4F90(u8 *p)
{
    *(u16 *)(p + 0xeb2) = 1;
    *(u16 *)(p + 0xeb0) = 0;
}

/*
 * function: func_021C9890
 * address:  0x021C9890
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 *
 * Duplicates a 16-bit value across the 32-bit word at 0x021D4228.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned int u32;
typedef unsigned short u16;

void func_021C9890(u16 v)
{
    *(u32 *)0x021D4228 = v | ((u32)v << 16);
}

/*
 * function: func_021B69F0
 * address:  0x021B69F0
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Clear the 3-byte counter at g_021C88E4.
 *
 * symbols:
 *   g_021C88E4  0x021C88E4  data  ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021B69F0(void)
{
    u8 *p = (u8 *)0x021C88E4;
    *(u16 *)p = 0;
    *(u8 *)(p + 2) = 0;
}

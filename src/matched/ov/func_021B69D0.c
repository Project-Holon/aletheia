/*
 * function: func_021B69D0
 * address:  0x021B69D0
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Set the byte at +0x44 to 1.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021B69D0(void *p)
{
    *(u8 *)((char *)p + 0x44) = 1;
}

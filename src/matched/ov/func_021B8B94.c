/*
 * function: func_021B8B94
 * address:  0x021B8B94
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Record address, +0x80, stride 0x40.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

char *func_021B8B94(int unused, char *base, int i)
{
    return base + 0x80 + (i << 6);
}

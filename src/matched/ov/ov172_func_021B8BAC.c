/*
 * function: func_021B8BAC
 * address:  0x021B8BAC
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field getter, u8 at +0xa0 of record i (stride 0x40).
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u8 func_021B8BAC(int unused, char *base, int i)
{
    return *(u8 *)(base + (i << 6) + 0xa0);
}

/*
 * function: func_021B7B30
 * address:  0x021B7B30
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Field getter, u32 at +0x34 of record i (stride 0x1c).
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

u32 func_021B7B30(int unused, char *base, int i)
{
    return *(u32 *)(base + i * 0x1c + 0x34);
}

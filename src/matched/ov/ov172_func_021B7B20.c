/*
 * function: func_021B7B20
 * address:  0x021B7B20
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Set the two words at +0x38 and +0x3c of record i (stride 0x1c).
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021B7B20(int unused, char *base, int i)
{
    *(u32 *)(base + i * 0x1c + 0x38) = 1;
    *(u32 *)((char *)base + i * 0x1c + 0x3c) = 1;
}

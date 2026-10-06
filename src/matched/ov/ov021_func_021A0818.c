/*
 * function: func_021A0818
 * address:  0x021A0818
 * packet:   pkt_ov021_021A0818
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

void func_021A0818(s16 *o, s32 a, u32 b)
{
    o[0] = a & 0x1f;
    o[1] = (s16)(b & 0x1f) - (u16)o[0];
    o[2] = (a & 0x3e0) >> 5;
    o[3] = (s16)((b & 0x3e0) >> 5) - (u16)o[2];
    o[4] = (a & 0x7c00) >> 10;
    o[5] = (s16)((b & 0x7c00) >> 10) - (u16)o[4];
}

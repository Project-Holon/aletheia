/*
 * function: func_021A9DE0
 * address:  0x021A9DE0
 * packet:   pkt_ov021_021A9DE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_021A9DC8  0x021A9DC8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021A9DC8(void);

u32 func_021A9DE0(void)
{
    u32 v = func_021A9DC8();

    if (v < 0x14) return 0;
    if (v >= 0x14 && v < 0x28) return 1;
    if (v >= 0x28 && v < 0x32) return 2;
    if (v >= 0x32 && v < 0x3C) return 3;
    if (v >= 0x3C && v < 0x46) return 4;
    if (v >= 0x46 && v < 0x50) return 5;
    if (v >= 0x50 && v < 0x55) return 6;
    if (v >= 0x55 && v < 0x5A) return 7;
    if (v >= 0x5A && v < 0x5E) return 8;
    if (v >= 0x5E && v < 0x62) return 9;
    if (v == 0x62) return 10;
    return 11;
}

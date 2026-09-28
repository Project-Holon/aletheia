/*
 * function: func_021AA6E0
 * address:  0x021AA6E0
 * packet:   pkt_ov021_021AA6E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_020056EC(u32 v);
extern u32 func_0209C2B0(u32 a, u32 b);

u32 func_021AA6E0(void)
{
    return func_0209C2B0(func_020056EC(0xFFFF), 0x290);
}

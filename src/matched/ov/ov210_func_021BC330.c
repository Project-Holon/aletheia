/*
 * function: func_021BC330
 * address:  0x021BC330
 * packet:   pkt_ov210_021BC330
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern u32 func_02030EAC(u32 a);

u32 func_021BC330(u8 *p)
{
    return func_02030EAC(*(u32 *)(p + 8));
}

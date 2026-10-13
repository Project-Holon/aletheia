/*
 * function: func_021BE360
 * address:  0x021BE360
 * packet:   pkt_021BE360
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BRIGHTNESS_Set  0x02023F60  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void BRIGHTNESS_Set(u32 a0, u32 a1, u32 mask);

u32 func_021BE360(u32 a, u32 b, u32 *c)
{
    BRIGHTNESS_Set((s16)*c, 0x1d, 1);
    return 1;
}


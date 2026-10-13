/*
 * function: func_021BE3A4
 * address:  0x021BE3A4
 * packet:   pkt_021BE3A4
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void GFL_USE_CancelChangeAndPlayBgm(u32, u32);

u32 func_021BE3A4(u32 a, u32 b, u32 *c)
{
    GFL_USE_CancelChangeAndPlayBgm(*c, 0xffff);
    return 1;
}


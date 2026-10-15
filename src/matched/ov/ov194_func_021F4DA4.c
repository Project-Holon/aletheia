/*
 * function: NAMEIN_GRAPHIC_GetGridCell
 * address:  0x021F4DA4
 * packet:   pkt_021F4DA4
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   NAMEIN_GRAPHIC_GetGridWidth  0x021F4D9C  thumb  ov194
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 NAMEIN_GRAPHIC_GetGridWidth(const u16 *p);

u32 NAMEIN_GRAPHIC_GetGridCell(u8 *p, u16 a, u16 b)
{
    return *(u16 *)(p + ((a + b * NAMEIN_GRAPHIC_GetGridWidth((const u16 *)p)) << 1) + 4);
}


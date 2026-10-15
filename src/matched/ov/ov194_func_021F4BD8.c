/*
 * function: NAMEIN_GRAPHIC_DrawDisplay
 * address:  0x021F4BD8
 * packet:   pkt_021F4BD8
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   NAMEIN_GRAPHIC_DrawClact  0x021F4D0C  thumb  ov194
 *   NAMEIN_GRAPHIC_Empty  0x021F4CA4  thumb  ov194
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void NAMEIN_GRAPHIC_DrawClact(u8 *);
extern void NAMEIN_GRAPHIC_Empty(u8 *);

void NAMEIN_GRAPHIC_DrawDisplay(u8 *p)
{
    NAMEIN_GRAPHIC_DrawClact(p + 4);
    NAMEIN_GRAPHIC_Empty(p);
}


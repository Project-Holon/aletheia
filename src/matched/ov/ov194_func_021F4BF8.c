/*
 * function: NAMEIN_GRAPHIC_DisplayMainTask
 * address:  0x021F4BF8
 * packet:   pkt_021F4BF8
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   NAMEIN_GRAPHIC_ResetBg  0x021F4CA8  thumb  ov194
 *   NAMEIN_GRAPHIC_VBlankClact  0x021F4D14  thumb  ov194
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void NAMEIN_GRAPHIC_ResetBg(u8 *);
extern void NAMEIN_GRAPHIC_VBlankClact(u8 *);

void NAMEIN_GRAPHIC_DisplayMainTask(u32 a, u8 *b)
{
    NAMEIN_GRAPHIC_ResetBg(b);
    NAMEIN_GRAPHIC_VBlankClact(b + 4);
}


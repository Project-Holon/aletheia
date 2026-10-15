/*
 * function: INTRO_GRAPHIC_VBlank
 * address:  0x021BDD84
 * packet:   pkt_021BDD84
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRO_GRAPHIC_UpdateBg  0x021BDE28  thumb  ov204
 *   INTRO_GRAPHIC_VBlankClact  0x021BDF98  thumb  ov204
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void INTRO_GRAPHIC_UpdateBg(void *a0);
extern void INTRO_GRAPHIC_VBlankClact(void *a0);

void INTRO_GRAPHIC_VBlank(u32 a, u8 *b)
{
    INTRO_GRAPHIC_UpdateBg(b);
    INTRO_GRAPHIC_VBlankClact(b + 4);
}


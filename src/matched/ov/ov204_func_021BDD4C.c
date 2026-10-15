/*
 * function: INTRO_GRAPHIC_UpdateDisplay
 * address:  0x021BDD4C
 * packet:   pkt_021BDD4C
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRO_GRAPHIC_DrawClact  0x021BDF90  thumb  ov204
 *   INTRO_GRAPHIC_ResetBgSlot  0x021BDE10  thumb  ov204
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern void INTRO_GRAPHIC_DrawClact(void *a0);
extern void INTRO_GRAPHIC_ResetBgSlot(u8 *);

void INTRO_GRAPHIC_UpdateDisplay(u8 *p)
{
    INTRO_GRAPHIC_DrawClact(p + 4);
    INTRO_GRAPHIC_ResetBgSlot(p);
}


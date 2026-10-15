/*
 * function: RESEARCH_TOP_SelectPrev
 * address:  0x021BA1F8
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   RESEARCH_TOP_DrawSelector  0x021BA284  thumb  ov217
 *   RESEARCH_TOP_DrawSelectorIdle  0x021BA2BC  thumb  ov217
 *   RESEARCH_TOP_MoveSelection  0x021BA388  thumb  ov217
 *   RESEARCH_TOP_StartEntryPaletteAnime  0x021BA3E8  thumb  ov217
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00511.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void RESEARCH_TOP_DrawSelector(int sel);
extern void RESEARCH_TOP_DrawSelectorIdle(int sel);
extern void RESEARCH_TOP_MoveSelection(char *self, int d);
extern u32 RESEARCH_TOP_StartEntryPaletteAnime();
u32 RESEARCH_TOP_SelectPrev(u32 a0)
{
    RESEARCH_TOP_DrawSelectorIdle(((struct Obj00511 *)(((u8*)a0)))->f28);
    RESEARCH_TOP_MoveSelection((char *)a0, -1);
    RESEARCH_TOP_DrawSelector(((struct Obj00511 *)(((u8*)a0)))->f28);
    GFL_USE_PlaySeDefaultVolume(1352);
    return RESEARCH_TOP_StartEntryPaletteAnime(a0, 1);
}


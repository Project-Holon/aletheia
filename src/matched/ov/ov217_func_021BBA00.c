/*
 * function: RESEARCH_LIST_SetSelectionMode
 * address:  0x021BBA00
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
 *   RESEARCH_LIST_SetSelectionModeField  0x021BBD14  thumb  ov217
 *   RESEARCH_LIST_SetEntryPaletteIdle  0x021BBD18  thumb  ov217
 *   RESEARCH_LIST_SetEntryPaletteActive  0x021BBD28  thumb  ov217
 *   RESEARCH_LIST_StartListPaletteAnime  0x021BC580  thumb  ov217
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj02928.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void RESEARCH_LIST_SetSelectionModeField(void *p, u32 v);
extern void RESEARCH_LIST_SetEntryPaletteIdle(int a, int b);
extern void RESEARCH_LIST_SetEntryPaletteActive(int a, int b);
extern u32 RESEARCH_LIST_StartListPaletteAnime();
u32 RESEARCH_LIST_SetSelectionMode(u32 a0, u32 a1)
{
    RESEARCH_LIST_SetEntryPaletteActive(a0, ((struct Obj02928 *)(((u8*)a0)))->f2C);
    RESEARCH_LIST_SetSelectionModeField((void *)a0, a1);
    RESEARCH_LIST_SetEntryPaletteIdle(a0, ((struct Obj02928 *)(((u8*)a0)))->f2C);
    GFL_USE_PlaySeDefaultVolume(1352);
    return RESEARCH_LIST_StartListPaletteAnime(a0, 4);
}


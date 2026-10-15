/*
 * function: RESEARCH_LIST_SelectEntry
 * address:  0x021BBAA4
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
 *   RESEARCH_LIST_SetCursorSlot  0x021BBD38  thumb  ov217
 *   RESEARCH_LIST_ShowCursor  0x021BBD68  thumb  ov217
 *   RESEARCH_LIST_HideCursor  0x021BBDAC  thumb  ov217
 *   RESEARCH_LIST_StartListPaletteAnime  0x021BC580  thumb  ov217
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void RESEARCH_LIST_SetCursorSlot(void *p, u8 v);
extern void RESEARCH_LIST_ShowCursor(u8 *p);
extern void RESEARCH_LIST_HideCursor(u8 *p);
extern u32 RESEARCH_LIST_StartListPaletteAnime();
u32 RESEARCH_LIST_SelectEntry(u32 a0, u8 a1)
{
    RESEARCH_LIST_HideCursor((u8 *)a0);
    RESEARCH_LIST_SetCursorSlot((void *)a0, a1);
    RESEARCH_LIST_ShowCursor((u8 *)a0);
    GFL_USE_PlaySeDefaultVolume(1352);
    return RESEARCH_LIST_StartListPaletteAnime(a0, 1);
}


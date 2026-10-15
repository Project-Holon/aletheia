/*
 * function: RESEARCH_GRAPH_EnterFadeIn
 * address:  0x021BE094
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_GRAPH_SetStateChanged  0x021BE448  thumb  ov217
 *   RESEARCH_GRAPH_GetSubState  0x021BE4DC  thumb  ov217
 *   RESEARCH_GRAPH_IncSubState  0x021BE4E0  thumb  ov217
 *   RESEARCH_GRAPH_StopSlotPaletteAnime  0x021BF5BC  thumb  ov217
 *   RESEARCH_GRAPH_RequestFadeIn  0x021BF60C  thumb  ov217
 *   RESEARCH_GRAPH_IsFadeDone  0x021BF6A4  thumb  ov217
 *
 * Same two-case entry as RESEARCH_GRAPH_EnterFadeOut; mode 0 arms the +5 handle and
 * RESEARCH_GRAPH_RequestFadeIn().
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void RESEARCH_GRAPH_SetStateChanged(void *p);
extern u32 RESEARCH_GRAPH_GetSubState(void *p);
extern void RESEARCH_GRAPH_IncSubState(void *p);
extern void RESEARCH_GRAPH_StopSlotPaletteAnime(u8 *a0, u32 a1);
extern void RESEARCH_GRAPH_RequestFadeIn(char *p);
extern u32 RESEARCH_GRAPH_IsFadeDone(u8 *a0);
void RESEARCH_GRAPH_EnterFadeIn(u32 a0)
{
    switch (RESEARCH_GRAPH_GetSubState((void *)a0)) {
    case 0:
    RESEARCH_GRAPH_StopSlotPaletteAnime((u8 *)a0, 5);
    RESEARCH_GRAPH_RequestFadeIn((char *)a0);
    RESEARCH_GRAPH_IncSubState((void *)a0);
    break;
    case 1:
    if (RESEARCH_GRAPH_IsFadeDone((u8 *)a0) != 0) {
    RESEARCH_GRAPH_SetStateChanged((void *)a0);
    }
    break;
    }
}

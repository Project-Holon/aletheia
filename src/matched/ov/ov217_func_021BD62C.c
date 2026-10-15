/*
 * function: RESEARCH_GRAPH_Update
 * address:  0x021BD62C
 * packet:   pkt_ov217_021BD62C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RESEARCH_GRAPH_Init  0x021BD718  thumb  ov217
 *   RESEARCH_GRAPH_UpdateIntro  0x021BD868  thumb  ov217
 *   RESEARCH_GRAPH_HandleInput  0x021BD89C  thumb  ov217
 *   RESEARCH_GRAPH_HandleInputAlt  0x021BDC18  thumb  ov217
 *   RESEARCH_GRAPH_EnterDrawSlow  0x021BDF58  thumb  ov217
 *   RESEARCH_GRAPH_StepAnimation  0x021BE040  thumb  ov217
 *   RESEARCH_GRAPH_EnterFadeIn  0x021BE094  thumb  ov217
 *   RESEARCH_GRAPH_EnterFadeOut  0x021BE0D0  thumb  ov217
 *   RESEARCH_GRAPH_EnterDrawMedium  0x021BE108  thumb  ov217
 *   RESEARCH_GRAPH_EnterDrawMediumAlt  0x021BE21C  thumb  ov217
 *   RESEARCH_GRAPH_ExitFade  0x021BE33C  thumb  ov217
 *   RESEARCH_GRAPH_AdvanceWhileActive  0x021BE36C  thumb  ov217
 *   RESEARCH_GRAPH_Cleanup  0x021BE384  thumb  ov217
 *   RESEARCH_GRAPH_CheckQuestionnaireUpdated  0x021BF6D4  thumb  ov217
 *   RESEARCH_GRAPH_TickTimer  0x021BF710  thumb  ov217
 *   RESEARCH_GRAPH_UpdateCircles  0x021BED9C  thumb  ov217
 *   ARROW_Update  0x021C20C4  thumb  ov217
 *   RESEARCH_GRAPH_UpdatePaletteAnime  0x021BF600  thumb  ov217
 *   RESEARCH_GRAPH_UpdateSlotPalettes  0x021BF5E4  thumb  ov217
 *   RESEARCH_GRAPH_DrawCircles  0x021BEDC4  thumb  ov217
 *   RESEARCH_GRAPH_DrawSliceColor  0x021BEDEC  thumb  ov217
 *   RESEARCH_GRAPH_IncTimer  0x021BE490  thumb  ov217
 *   RESEARCH_GRAPH_ProcessCommand  0x021BE4A4  thumb  ov217
 *   CLACT_DrawSystem  0x0204A600  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned char  u8;
extern void RESEARCH_GRAPH_Init(unsigned char *p);
typedef unsigned int   u32;
extern void RESEARCH_GRAPH_UpdateIntro(u32 a0);
extern void RESEARCH_GRAPH_HandleInput(u8 *p);
extern void RESEARCH_GRAPH_HandleInputAlt(u8 *p);
extern void RESEARCH_GRAPH_EnterDrawSlow(u8 *p);
extern void RESEARCH_GRAPH_StepAnimation(u8 *p);
extern void RESEARCH_GRAPH_EnterFadeIn(u32 a0);
extern void RESEARCH_GRAPH_EnterFadeOut(u32 a0);
extern void RESEARCH_GRAPH_EnterDrawMedium(char *p);
extern void RESEARCH_GRAPH_EnterDrawMediumAlt(char *p);
extern void RESEARCH_GRAPH_ExitFade(u32 a0);
extern void RESEARCH_GRAPH_AdvanceWhileActive(u32 a0);
extern void RESEARCH_GRAPH_Cleanup(u8 *a0);
extern void RESEARCH_GRAPH_CheckQuestionnaireUpdated(char *p);
extern void RESEARCH_GRAPH_TickTimer(void *p);
extern void CLACT_DrawSystem(void *h);
extern void RESEARCH_GRAPH_UpdateCircles(char *p);
extern void ARROW_Update(void *h);
extern void RESEARCH_GRAPH_UpdatePaletteAnime(u8 *a0);
extern void RESEARCH_GRAPH_UpdateSlotPalettes(int *p);
extern void RESEARCH_GRAPH_DrawCircles(char *p);
extern void RESEARCH_GRAPH_DrawSliceColor(char *p);
extern void RESEARCH_GRAPH_IncTimer(void *p);
extern void RESEARCH_GRAPH_ProcessCommand(u32 a0);

void RESEARCH_GRAPH_Update(unsigned char *p)
{
    switch (((struct Obj00021 *)p)->f20) {
    case 0: RESEARCH_GRAPH_Init(p); break;
    case 1: RESEARCH_GRAPH_UpdateIntro((u32)p); break;
    case 2: RESEARCH_GRAPH_HandleInput(p); break;
    case 3: RESEARCH_GRAPH_HandleInputAlt(p); break;
    case 4: RESEARCH_GRAPH_EnterDrawSlow(p); break;
    case 5: RESEARCH_GRAPH_StepAnimation(p); break;
    case 6: RESEARCH_GRAPH_EnterFadeIn((u32)p); break;
    case 7: RESEARCH_GRAPH_EnterFadeOut((u32)p); break;
    case 8: RESEARCH_GRAPH_EnterDrawMedium((char *)p); break;
    case 9: RESEARCH_GRAPH_EnterDrawMediumAlt((char *)p); break;
    case 10: RESEARCH_GRAPH_ExitFade((u32)p); break;
    case 11: RESEARCH_GRAPH_AdvanceWhileActive((u32)p); break;
    case 12: RESEARCH_GRAPH_Cleanup((u8 *)p); break;
    case 13: return;
    }
    RESEARCH_GRAPH_CheckQuestionnaireUpdated((char *)p);
    RESEARCH_GRAPH_TickTimer(p);
    if (((struct Obj00021 *)p)->f3C4 != 0) {
        CLACT_DrawSystem(((struct Obj00021 *)p)->f3C4);
        RESEARCH_GRAPH_UpdateCircles((char *)p);
        ARROW_Update(((struct Obj00021 *)p)->f2D0);
        RESEARCH_GRAPH_UpdatePaletteAnime(p);
        RESEARCH_GRAPH_UpdateSlotPalettes((int *)p);
        RESEARCH_GRAPH_DrawCircles((char *)p);
        RESEARCH_GRAPH_DrawSliceColor((char *)p);
        *(volatile unsigned int *)0x04000540 = 0;
    }
    RESEARCH_GRAPH_IncTimer(p);
    RESEARCH_GRAPH_ProcessCommand((u32)p);
}

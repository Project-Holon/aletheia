/*
 * function: RESEARCH_GRAPH_ExitFade
 * address:  0x021BE33C
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
 *   RESEARCH_GRAPH_FadeOut  0x021BE90C  thumb  ov217
 *   FADE_IsActive  0x0204E804  arm  arm9
 *
 * Same two-case entry with RESEARCH_GRAPH_FadeOut() and the ARM9 query FADE_IsActive().
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
extern int FADE_IsActive(void);
extern void RESEARCH_GRAPH_FadeOut(void);
void RESEARCH_GRAPH_ExitFade(u32 a0)
{
    switch (RESEARCH_GRAPH_GetSubState((void *)a0)) {
    case 0:
    RESEARCH_GRAPH_FadeOut();
    RESEARCH_GRAPH_IncSubState((void *)a0);
    break;
    case 1:
    if (FADE_IsActive() == 0) {
    RESEARCH_GRAPH_SetStateChanged((void *)a0);
    }
    break;
    }
}

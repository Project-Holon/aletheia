/*
 * function: RESEARCH_TOP_StepExitFade
 * address:  0x021BA094
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   RESEARCH_TOP_SetCommandReady  0x021BA150  thumb  ov217
 *   RESEARCH_TOP_GetCommandTimer  0x021BA190  thumb  ov217
 *   RESEARCH_TOP_IncCommandTimer  0x021BA194  thumb  ov217
 *   RESEARCH_TOP_FadeOut  0x021BA364  thumb  ov217
 *   FADE_IsActive  0x0204E804  arm  arm9
 *
 * Two-case entry picked by RESEARCH_TOP_GetCommandTimer(): mode 0 runs the
 * RESEARCH_TOP_FadeOut()/RESEARCH_TOP_IncCommandTimer() pair, mode 1 runs RESEARCH_TOP_SetCommandReady() when the
 * ARM9 query FADE_IsActive() is clear.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern int FADE_IsActive(void);
extern void RESEARCH_TOP_SetCommandReady(void *p);
extern u32 RESEARCH_TOP_GetCommandTimer(void *p);
extern void RESEARCH_TOP_IncCommandTimer(void *p);
extern void RESEARCH_TOP_FadeOut(void);
void RESEARCH_TOP_StepExitFade(u32 a0)
{
    switch (RESEARCH_TOP_GetCommandTimer((void *)a0)) {
    case 0:
    RESEARCH_TOP_FadeOut();
    RESEARCH_TOP_IncCommandTimer((void *)a0);
    break;
    case 1:
    if (FADE_IsActive() == 0) {
    RESEARCH_TOP_SetCommandReady((void *)a0);
    }
    break;
    }
}

/*
 * function: POKETRADE_SAVE_StepWaitFade1
 * address:  0x021DFFE0
 * packet:   pkt_ov119_021DFFE0
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKETRADE_SAVE_PopBgmFadeIn24  0x021DFD7C  thumb  ov119
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_SAVE_StepWaitFade2  0x021E0008  thumb  ov119
 */
#include "../include/Obj22753.h"

extern void POKETRADE_SAVE_PopBgmFadeIn24(void *);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_SAVE_StepWaitFade2(char *p);

void POKETRADE_SAVE_StepWaitFade1(char *p)
{
    if (((struct Obj22753 *)p)->fF2C >= 0x10e) {
        POKETRADE_SAVE_PopBgmFadeIn24(p);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepWaitFade2);
    }
}

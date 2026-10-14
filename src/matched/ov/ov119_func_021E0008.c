/*
 * function: POKETRADE_SAVE_StepWaitFade2
 * address:  0x021E0008
 * packet:   pkt_ov119_021E0008
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   POKETRADE_SAVE_SetWaitCounter  0x021DFD30  thumb  ov119
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   POKETRADE_SAVE_StepAfterTrade  0x021E08E8  thumb  ov119
 */
#include "../include/Obj22754.h"

typedef unsigned int u32;

typedef unsigned char  u8;
extern void POKETRADE_SAVE_SetWaitCounter(u8 *p, u32 v);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_SAVE_StepAfterTrade(char *p);

void POKETRADE_SAVE_StepWaitFade2(char *p)
{
    if (((struct Obj22754 *)p)->fF2C >= 0x1a4) {
        POKETRADE_SAVE_SetWaitCounter((u8 *)p, 0);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_StepAfterTrade);
    }
}

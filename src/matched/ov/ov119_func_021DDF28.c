/*
 * function: POKETRADE_NEGO_StepOpenConfirmMenu
 * address: 0x021DDF28
 * packet: pkt_ov119_021DDF28
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E76E4 0x021E76E4 data a4
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   POKETRADE_SAVE_OpenTaskMenu 0x021E1410 thumb ov119
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepConfirmMenuChoice 0x021DDED4 thumb ov119
 */
#include "../include/Obj22741.h"
typedef struct { int a,b; } Pair;
extern const Pair d_021E76E4;
typedef unsigned int   u32;
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern void POKETRADE_SAVE_OpenTaskMenu(void *p, int *ids, int count);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepConfirmMenuChoice(unsigned char *p);
void POKETRADE_NEGO_StepOpenConfirmMenu(char *p)
{
    if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
        Pair t=d_021E76E4;
        POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),2);
        BG_SYS_SetMainVisiblePlanes(31);
        TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj22741 *)p)->f9C0),1,0);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepConfirmMenuChoice);
    }
}

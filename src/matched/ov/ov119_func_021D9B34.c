/*
 * function: POKETRADE_PROC_StepOpenMainMenu
 * address: 0x021D9B34
 * packet: pkt_ov119_021D9B34
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   POKETRADE_SAVE_OpenTaskMenu 0x021E1410 thumb ov119
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepMainMenuChoice 0x021D9A50 thumb ov119
 *   d_021E75E4 0x021E75E4 data
 */
#include "../include/Obj22726.h"
typedef struct {int a,b,c;} Triple;
typedef unsigned int   u32;
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern void POKETRADE_SAVE_OpenTaskMenu(void *p, int *ids, int count);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepMainMenuChoice(char *p);
extern const Triple d_021E75E4;
void POKETRADE_PROC_StepOpenMainMenu(char *p) { if(POKETRADE_SAVE_IsMessagePrintDone(p)) { Triple t=d_021E75E4; POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),3); BG_SYS_SetMainVisiblePlanes(31); TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj22726 *)p)->f9C0),1,0); POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepMainMenuChoice); } }

/*
 * function: POKETRADE_PROC_StepAfterSummaryWipe
 * address: 0x021D99F4
 * packet: pkt_ov119_021D99F4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   POKETRADE_SAVE_OpenSummaryScreen 0x021E1D68 thumb ov119
 *   POKETRADE_PROC_RequestBoxRedraw 0x021D8B38 thumb ov119
 *   WIPE_SYS_Start 0x0202208C thumb
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepMain 0x021D98AC thumb ov119
 */
#include "../include/Obj03775.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
extern void *POKETRADE_PROC_GetSideMon(void *,int);
extern void POKETRADE_SAVE_OpenSummaryScreen(char *p, void *a);
extern void POKETRADE_PROC_RequestBoxRedraw(char *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepMain(char *p);
void POKETRADE_PROC_StepAfterSummaryWipe(char *p) { if(WIPE_SYS_EndCheck()) { ((struct Obj03775 *)p)->f10A0=0; POKETRADE_SAVE_OpenSummaryScreen(p,POKETRADE_PROC_GetSideMon(p,0));POKETRADE_PROC_RequestBoxRedraw(p);WIPE_SYS_Start((void *)3,1,1,0,6,1,((struct Obj03775 *)p)->f5F4);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepMain); } }

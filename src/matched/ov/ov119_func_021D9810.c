/*
 * function: POKETRADE_PROC_StepReturnFromSummary
 * address: 0x021D9810
 * packet: pkt_ov119_021D9810
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_02040588 0x02040588 arm
 *   POKETRADE_SAVE_CloseSummaryPage 0x021E1CE8 thumb ov119
 *   POKETRADE_2D_LoadBackgroundGfx 0x021E3E80 thumb ov119
 *   POKETRADE_3D_AddUnitAndInit 0x021E3208 thumb ov119
 *   func_02041B6C 0x02041B6C arm
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   POKETRADE_PROC_SetSideMon 0x021D9468 thumb ov119
 *   POKETRADE_PROC_RequestBoxRedraw 0x021D8B38 thumb ov119
 *   WIPE_SYS_Start 0x0202208C thumb
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepShowTradeSummary 0x021D9AD8 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void POKETRADE_SAVE_CloseSummaryPage(void *,int);
extern void POKETRADE_2D_LoadBackgroundGfx(char *p);
extern void POKETRADE_3D_AddUnitAndInit(void *,int);
extern void func_02041B6C(u32 bit);
extern void *POKETRADE_PROC_GetSideMon(void *,int);
extern void POKETRADE_PROC_SetSideMon(void *,int,void *);
extern void POKETRADE_PROC_RequestBoxRedraw(char *p);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepShowTradeSummary(char *p);
void POKETRADE_PROC_StepReturnFromSummary(char *p) { int z,one; if(WIPE_SYS_EndCheck()) {z=0;func_02040588(3,0);one=1;POKETRADE_SAVE_CloseSummaryPage(p,1);func_02040588(4,0);POKETRADE_2D_LoadBackgroundGfx(p);POKETRADE_3D_AddUnitAndInit(p,0);func_02041B6C(3);*(u16 *)0x04000050=z;POKETRADE_PROC_SetSideMon(p,0,POKETRADE_PROC_GetSideMon(p,0));POKETRADE_PROC_SetSideMon(p,1,POKETRADE_PROC_GetSideMon(p,1));POKETRADE_PROC_RequestBoxRedraw(p);WIPE_SYS_Start((void *)3,1,1,0,6,one,((struct Obj00001 *)p)->f5F4);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepShowTradeSummary); } }

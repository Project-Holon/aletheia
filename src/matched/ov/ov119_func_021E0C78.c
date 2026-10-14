/*
 * function: POKETRADE_SAVE_StepBeginWipeOut
 * address: 0x021E0C78
 * packet: pkt_ov119_021E0C78
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_SAVE_StepRebuildSceneAfterWipe 0x021E0CC0 thumb ov119
 */
#include "../include/Obj10372.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_SAVE_StepRebuildSceneAfterWipe(char *p);
void POKETRADE_SAVE_StepBeginWipeOut(char *p) {int z;WIPE_SYS_Start(0,0,0,0,6,1,((struct Obj10372 *)p)->f5F4);z=0;((struct Obj10372 *)p)->fF2C=z;p[0x11f7]=z;POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepRebuildSceneAfterWipe);}

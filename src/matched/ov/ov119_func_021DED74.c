/*
 * function: POKETRADE_NEGO_StepWipeToBrowse
 * address: 0x021DED74
 * packet: pkt_ov119_021DED74
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepWaitWipeToBrowse 0x021DED58 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern int POKETRADE_PROC_IsNetSession(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepWaitWipeToBrowse(void *);
void POKETRADE_NEGO_StepWipeToBrowse(void *p) {
 if(!POKETRADE_PROC_IsNetSession(p) || ((struct Obj00001 *)p)->f1060) {
  WIPE_SYS_Start(0,0,0,0,6,1,((struct Obj00001 *)p)->f5F4);
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepWaitWipeToBrowse);
 }
}

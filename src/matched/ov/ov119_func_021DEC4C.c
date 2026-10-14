/*
 * function: POKETRADE_NEGO_StepWaitWipeBrowse
 * address: 0x021DEC4C
 * packet: pkt_ov119_021DEC4C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_2D_StepCursorSlide 0x021E69C0 thumb ov119
 *   POKETRADE_2D_MovePickedIconActor 0x021E68F4 thumb ov119
 *   POKETRADE_NEGO_SetupWindowRegsOffers 0x021DEBD4 thumb ov119
 *   POKETRADE_NEGO_StepShowNoOfferMessage 0x021DEBA0 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 */
#include "../include/Obj05337.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int POKETRADE_2D_StepCursorSlide(char *p);
extern void POKETRADE_2D_MovePickedIconActor(int p, int i);
extern void POKETRADE_NEGO_SetupWindowRegsOffers(void *);
extern void POKETRADE_NEGO_StepShowNoOfferMessage(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern u8 func_020355C4(void);
extern u32 WIPE_SYS_EndCheck(void);
void POKETRADE_NEGO_StepWaitWipeBrowse(void *p) {
 if(POKETRADE_2D_StepCursorSlide(p)) {
  if(func_020355C4()) {POKETRADE_2D_MovePickedIconActor((int)p,-1);((struct Obj05337 *)p)->f10A0=0;}
  else {POKETRADE_2D_MovePickedIconActor((int)p,0);((struct Obj05337 *)p)->f10A0=0;}
  if(WIPE_SYS_EndCheck()) {POKETRADE_NEGO_SetupWindowRegsOffers(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepShowNoOfferMessage);}
 }
}

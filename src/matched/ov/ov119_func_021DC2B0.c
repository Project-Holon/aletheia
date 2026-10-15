/*
 * function: POKETRADE_PROC_StepTouchbarAction
 * address: 0x021DC2B0
 * packet: pkt_ov119_021DC2B0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKETRADE_NEGO_HasOffer 0x021DD2F4 thumb ov119
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   POKETRADE_PROC_ClearDragIcon 0x021D8C6C thumb ov119
 *   POKETRADE_PROC_StepSlideInSubScreen 0x021DB198 thumb ov119
 *   POKETRADE_PROC_StepBeginOpenSubScreen 0x021DB45C thumb ov119
 *   POKETRADE_NEGO_StepShowCancelMessage 0x021DF5D8 thumb ov119
 *   POKETRADE_PROC_HideTouchbarButtons 0x021D9E54 thumb ov119
 *   POKETRADE_PROC_StepBrowseGrid 0x021DBE70 thumb ov119
 */
#include "../include/Obj00001.h"
struct S;
extern void TOUCHBAR_Update(struct S *p);extern int TOUCHBAR_GetPressedButtonIdIfDone(int);extern void POKETRADE_PROC_SetStep(void *,int);extern int POKETRADE_PROC_IsHostSide(void *);extern int POKETRADE_NEGO_HasOffer(void *);extern void TOUCHBAR_SetButtonVisible(int,int,int);extern void POKETRADE_PROC_ClearDragIcon(void *);extern void POKETRADE_PROC_StepSlideInSubScreen(void);extern void POKETRADE_PROC_StepBeginOpenSubScreen(void);extern void POKETRADE_NEGO_StepShowCancelMessage(void);extern void POKETRADE_PROC_HideTouchbarButtons(void);extern void POKETRADE_PROC_StepBrowseGrid(void);
void POKETRADE_PROC_StepTouchbarAction(char *p){TOUCHBAR_Update((struct S *)(*(int *)&((struct Obj00001 *)p)->f9C0));switch(TOUCHBAR_GetPressedButtonIdIfDone(*(int *)&((struct Obj00001 *)p)->f9C0)) {case 1:POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSlideInSubScreen);return;case 7:POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginOpenSubScreen);return;case 8:if(POKETRADE_PROC_IsHostSide(p)){if(POKETRADE_NEGO_HasOffer(p)){TOUCHBAR_SetButtonVisible(*(int *)&((struct Obj00001 *)p)->f9C0,7,0);TOUCHBAR_SetButtonVisible(*(int *)&((struct Obj00001 *)p)->f9C0,8,0);POKETRADE_PROC_ClearDragIcon(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepShowCancelMessage);return;}else{TOUCHBAR_SetButtonVisible(*(int *)&((struct Obj00001 *)p)->f9C0,7,1);TOUCHBAR_SetButtonVisible(*(int *)&((struct Obj00001 *)p)->f9C0,8,0);}}else{if(((struct Obj00001 *)p)->fF84==-1){TOUCHBAR_SetButtonVisible(*(int *)&((struct Obj00001 *)p)->f9C0,7,1);TOUCHBAR_SetButtonVisible(*(int *)&((struct Obj00001 *)p)->f9C0,8,0);}else{POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_HideTouchbarButtons);return;}}POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);return;}}

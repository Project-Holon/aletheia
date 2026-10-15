/*
 * function: POKETRADE_PROC_StepRebuildBrowseScene
 * address: 0x021DBBD0
 * packet: pkt_ov119_021DBBD0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_NEGO_SetOfferMarkersState 0x021DF7AC thumb ov119
 *   MI_CpuFill8 0x02082BCC arm
 *   POKETRADE_PROC_ShowDragIcon 0x021D8C84 thumb ov119
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   POKETRADE_2D_CreateBoxWindows 0x021E4420 thumb ov119
 *   POKETRADE_2D_SetupSubBlend 0x021E6700 thumb ov119
 *   POKETRADE_PROC_UpdateTouchbarButtons 0x021DBB6C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepBrowseGrid 0x021DBE70 thumb ov119
 */
#include "../include/Obj00001.h"
extern void POKETRADE_NEGO_SetOfferMarkersState(void *,int); extern void MI_CpuFill8(void *,int,int); extern void POKETRADE_PROC_ShowDragIcon(void *); extern void APP_TASKMENU_CloseMenu(int); extern void POKETRADE_2D_CreateBoxWindows(void *); extern void POKETRADE_2D_SetupSubBlend(void *); extern void POKETRADE_PROC_UpdateTouchbarButtons(void *); extern void POKETRADE_PROC_SetStep(void *,int); extern void POKETRADE_PROC_StepBrowseGrid(void);
void POKETRADE_PROC_StepRebuildBrowseScene(char *p) { POKETRADE_NEGO_SetOfferMarkersState(p,1); MI_CpuFill8(p+0xca0,0,0x78); MI_CpuFill8(p+0xd18,0,0x3c); MI_CpuFill8(p+0xd54,0,0x3c); POKETRADE_PROC_ShowDragIcon(p); if(*(int *)&((struct Obj00001 *)p)->f64C) {APP_TASKMENU_CloseMenu(*(int *)&((struct Obj00001 *)p)->f64C); *(int *)&((struct Obj00001 *)p)->f64C=0;} POKETRADE_2D_CreateBoxWindows(p);POKETRADE_2D_SetupSubBlend(p);POKETRADE_PROC_UpdateTouchbarButtons(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);}

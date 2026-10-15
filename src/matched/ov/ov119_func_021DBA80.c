/*
 * function: POKETRADE_PROC_StepResetGrid
 * address: 0x021DBA80
 * packet: pkt_ov119_021DBA80
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   POKETRADE_PROC_ShowDragIcon 0x021D8C84 thumb ov119
 *   POKETRADE_NEGO_SetOfferMarkersState 0x021DF7AC thumb ov119
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   POKETRADE_PROC_ClearSideMon 0x021D94A0 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepBeginBrowse 0x021DBA38 thumb ov119
 */
#include "../include/Obj00001.h"
extern void MI_CpuFill8(void *,int,int);
extern void POKETRADE_PROC_ShowDragIcon(void *);
extern void POKETRADE_NEGO_SetOfferMarkersState(void *,int);
struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void POKETRADE_PROC_ClearSideMon(void *,int);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepBeginBrowse(void *);
void POKETRADE_PROC_StepResetGrid(char *p)
{
    ((struct Obj00001 *)p)->f1088=0;
    ((struct Obj00001 *)p)->f1078=0;
    ((struct Obj00001 *)p)->f107A=0;
    MI_CpuFill8(p+0xca0,0,0x78);
    MI_CpuFill8(p+0xd18,0,0x3c);
    MI_CpuFill8(p+0xd54,0,0x3c);
    POKETRADE_PROC_ShowDragIcon(p);
    POKETRADE_NEGO_SetOfferMarkersState(p,1);
    if(*(int *)&((struct Obj00001 *)p)->f64C) {
        APP_TASKMENU_CloseMenu((struct TaskMenu *)(*(int *)&((struct Obj00001 *)p)->f64C));
        *(int *)&((struct Obj00001 *)p)->f64C=0;
    }
    POKETRADE_PROC_ClearSideMon(p,0);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginBrowse);
}

/*
 * function: POKETRADE_PROC_StepOpenPeerSummary
 * address: 0x021DA640
 * packet: pkt_ov119_021DA640
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_NEGO_SetOfferMarkersState 0x021DF7AC thumb ov119
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   POKETRADE_SAVE_OpenTaskMenu 0x021E1410 thumb ov119
 *   POKETRADE_PROC_LoadSlotMon 0x021D8D4C thumb ov119
 *   POKETRADE_SAVE_DrawSummaryPage 0x021E1E00 thumb ov119
 *   func_020307B0 0x020307B0 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKETRADE_PROC_ShowDragIcon 0x021D8C84 thumb ov119
 *   POKETRADE_PROC_RequestBoxRedraw 0x021D8B38 thumb ov119
 *   func_020355C4 0x020355C4 arm
 *   APP_TASKMENU_SetCursorActive 0x02027A08 thumb
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepPeerSummaryMenu 0x021DA318 thumb ov119
 *   d_021E7594 0x021E7594 data a4
 */
#include "../include/Obj02826.h"

typedef struct { int a,b; } Pair;
extern const Pair d_021E7594;
extern void POKETRADE_NEGO_SetOfferMarkersState(void *,int);
typedef unsigned int   u32;
struct TaskMenu;
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void POKETRADE_SAVE_OpenTaskMenu(void *p, int *ids, int count);
extern void *POKETRADE_PROC_LoadSlotMon(void **a, int b, int c, char *p);
extern void POKETRADE_SAVE_DrawSummaryPage(char *p, int mode, void *mon);
extern u32 func_020307B0(void *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void POKETRADE_PROC_ShowDragIcon(void *);
typedef unsigned char  u8;
extern void POKETRADE_PROC_RequestBoxRedraw(char *p);
extern u8 func_020355C4(void);
extern u32 APP_TASKMENU_SetCursorActive(struct TaskMenu *tm, u32 arg);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepPeerSummaryMenu(char *p);
void POKETRADE_PROC_StepOpenPeerSummary(char *p) {
    Pair t;
    int n;
    int zero=0;
    POKETRADE_NEGO_SetOfferMarkersState(p,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj02826 *)p)->f9C0),1,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj02826 *)p)->f9C0),7,0);
    TOUCHBAR_SetButtonVisible((unsigned char *)(((struct Obj02826 *)p)->f9C0),9,1);
    t=d_021E7594;
    POKETRADE_SAVE_OpenTaskMenu(p,(int *)(&t),2);
    n=(int)POKETRADE_PROC_LoadSlotMon(*(void ** *)&((struct Obj02826 *)p)->f828,((struct Obj02826 *)p)->fF98,((struct Obj02826 *)p)->fF94,p);
    ((struct Obj02826 *)p)->f10A0=zero;
    POKETRADE_SAVE_DrawSummaryPage(p,0,(void *)n);
    func_020307B0((void *)n);
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj02826 *)p)->fF04,0);
    POKETRADE_PROC_ShowDragIcon(p);
    POKETRADE_PROC_RequestBoxRedraw(p);
    if(func_020355C4()) APP_TASKMENU_SetCursorActive((struct TaskMenu *)(((struct Obj02826 *)p)->f64C),zero);
    else APP_TASKMENU_SetCursorActive((struct TaskMenu *)(((struct Obj02826 *)p)->f64C),1);
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepPeerSummaryMenu);
}

/*
 * function: POKETRADE_PROC_StepOpenSummaryMenu
 * address: 0x021DB10C
 * packet: pkt_ov119_021DB10C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   POKETRADE_SAVE_OpenTaskMenuAt 0x021E131C thumb ov119
 *   POKETRADE_2D_UpdateVisibleColumns 0x021E4E64 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepSummaryMenuChoice 0x021DB030 thumb ov119
 *   gSummaryMenuPos 0x021E758C data a4
 */
#include "../include/Obj00001.h"
typedef struct { int a,b; } Pair;
extern const Pair gSummaryMenuPos;
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern void POKETRADE_SAVE_OpenTaskMenuAt(char *p, int *ids, int count, int x, int y);
extern void POKETRADE_2D_UpdateVisibleColumns(int a, char *p, int b);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepSummaryMenuChoice(char *p);
void POKETRADE_PROC_StepOpenSummaryMenu(char *p)
{
    if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
        Pair t=gSummaryMenuPos;
        POKETRADE_SAVE_OpenTaskMenuAt(p,(int *)(&t),2,0x20,0xc);
        ((struct Obj00001 *)p)->f1080=-1;
        POKETRADE_2D_UpdateVisibleColumns(*(int *)&((struct Obj00001 *)p)->f828,p,0);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSummaryMenuChoice);
    }
}

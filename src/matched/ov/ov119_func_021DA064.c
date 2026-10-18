/*
 * function: POKETRADE_PROC_StepWaitKeyAfterMessage
 * address: 0x021DA064
 * packet: pkt_ov119_021DA064
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   KEY_GetTrg 0x020362DC arm
 *   UI_SetInputMode 0x020355D8 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepBrowseGrid 0x021DBE70 thumb ov119
 *   POKETRADE_2D_UpdateVisibleColumns 0x021E4E64 thumb ov119
 */
#include "../include/Obj00001.h"

typedef unsigned int u32;

typedef unsigned char  u8;
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern u32 KEY_GetTrg(void);
extern void UI_SetInputMode(u8 v);
extern int TOUCHPANEL_GetTrg(void);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepBrowseGrid(char *p);
extern void POKETRADE_2D_UpdateVisibleColumns(int a, char *p, int b);
void POKETRADE_PROC_StepWaitKeyAfterMessage(char *p) {
    int v;
    if (POKETRADE_SAVE_IsMessagePrintDone(p)) {
        v=KEY_GetTrg();
        if(v) UI_SetInputMode(0);
        if(!v) {
            v=TOUCHPANEL_GetTrg();
            if(v) UI_SetInputMode(1);
            if(!v) return;
        }
        ((struct Obj00001 *)p)->fF80=-1;
        ((struct Obj00001 *)p)->fF7C=-1;
        POKETRADE_SAVE_CloseMessageWindowClear(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBrowseGrid);
        ((struct Obj00001 *)p)->f1080=-1;
        POKETRADE_2D_UpdateVisibleColumns(*(int *)&((struct Obj00001 *)p)->f828,p,1);
    }
}

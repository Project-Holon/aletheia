/*
 * function: POKETRADE_SAVE_StepAfterTrade
 * address: 0x021E08E8
 * packet: pkt_ov119_021E08E8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Explicit unsigned range tests avoid the dense switch table.
 * symbols:
 *   POKETRADE_3D_DeleteMcssSlot 0x021E36D8 thumb ov119
 *   POKETRADE_SAVE_PopBgmFadeIn60 0x021DFD3C thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepBeginWipeOut 0x021D9434 thumb ov119
 *   POKETRADE_SAVE_SendTradeSummary 0x021E0054 thumb ov119
 *   POKETRADE_SAVE_StepRegisterReceived 0x021E0980 thumb ov119
 */
#include "../include/Obj00906.h"
#include "../include/Obj22758.h"
extern void POKETRADE_3D_DeleteMcssSlot(void *,int);
extern void POKETRADE_SAVE_PopBgmFadeIn60(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepBeginWipeOut(void *);
extern void POKETRADE_SAVE_SendTradeSummary(char *p);
extern void POKETRADE_SAVE_StepRegisterReceived(char *p);
void POKETRADE_SAVE_StepAfterTrade(char *p)
{
    int state;
    POKETRADE_3D_DeleteMcssSlot(p,0);POKETRADE_3D_DeleteMcssSlot(p,1);
    POKETRADE_3D_DeleteMcssSlot(p,2);POKETRADE_3D_DeleteMcssSlot(p,3);
    state=((struct Obj00906 *)p)->f118C;
    if(state==4 || (unsigned)(state-7)<=1) {
        ((struct Obj22758 *)(*(char * *)&((struct Obj00906 *)p)->f8))->f8=3;
        POKETRADE_SAVE_PopBgmFadeIn60(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginWipeOut);
        return;
    }
    if((unsigned)(state-1)<=2) {
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_SendTradeSummary);
        return;
    } else {
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepRegisterReceived);
        return;
    }
}

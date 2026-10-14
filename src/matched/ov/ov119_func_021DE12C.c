/*
 * function: POKETRADE_NEGO_StepBeginConfirm
 * address: 0x021DE12C
 * packet: pkt_ov119_021DE12C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_SetSideMon 0x021D9468 thumb ov119
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   POKETRADE_PROC_GetSideMon 0x021D8FA4 thumb ov119
 *   MI_CpuCopy8 0x02082D44 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepResolveConfirm 0x021DDF74 thumb ov119
 *   POKETRADE_NEGO_StepSendConfirm 0x021DE0F0 thumb ov119
 */
#include "../include/Obj05329.h"
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, unsigned int index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
typedef unsigned int   u32;
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
extern int POKETRADE_PROC_IsNetSession(void *);
extern void POKETRADE_PROC_SetSideMon(void *,int,void *);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void *POKETRADE_PROC_GetSideMon(void *,int);
extern void MI_CpuCopy8(void *,const void *,int);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepResolveConfirm(char *p);
extern void POKETRADE_NEGO_StepSendConfirm(void *);
void POKETRADE_NEGO_StepBeginConfirm(char *p)
{
    void *obj;
    int n;
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj05329 *)p)->f720),0x88,(void *)(((struct Obj05329 *)p)->f738));
    POKETRADE_SAVE_OpenMessageWindowTop(p);
    POKETRADE_SAVE_ShowTimeIcon(p);
    p[0x11f1]=120;
    if(POKETRADE_PROC_IsNetSession(p)==0) {
        p[0x11e0]=11;
        p[0x11e1]=11;
        obj=((struct Obj05329 *)p)->fFD8;
        POKETRADE_PROC_SetSideMon(p,1,obj);
        n=POKE_TOOL_GetPartyParamSize();
        MI_CpuCopy8(obj,POKETRADE_PROC_GetSideMon(p,1),n);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepResolveConfirm);
        return;
    }
    POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendConfirm);
}

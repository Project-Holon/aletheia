/*
 * function: POKETRADE_NEGO_StepWaitFinalMessage
 * address: 0x021DF4CC
 * packet: pkt_ov119_021DF4CC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   func_021DD140 0x021DD140 thumb ov119
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepOpenFinalAgreeMenu 0x021DF490 thumb ov119
 */
#include "../include/Obj00001.h"
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct Link;
struct MsgBank;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern int func_021DD140(char *p);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepOpenFinalAgreeMenu(void *);
void POKETRADE_NEGO_StepWaitFinalMessage(char *p)
{
    GFL_NET_GetHandleNetID((struct Link *)((unsigned)GFL_NET_HANDLE_GetCurrentHandle()));
    if (POKETRADE_SAVE_IsMessagePrintDone(p) && func_021DD140(p)) {
        MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),0x89,(void *)(*(int *)&((struct Obj00001 *)p)->f738));
        POKETRADE_SAVE_OpenMessageWindowTop(p);
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepOpenFinalAgreeMenu);
    }
}

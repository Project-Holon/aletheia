/*
 * function: POKETRADE_NEGO_StepWaitReplyKey
 * address: 0x021DDB90
 * packet: pkt_ov119_021DDB90
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepSendSync25 0x021DDB64 thumb ov119
 */
#include "../include/Obj00001.h"

typedef unsigned int u32;

typedef unsigned char  u8;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern u32 KEY_GetTrg(void);
extern void func_020355D8(u8 v);
extern int TOUCHPANEL_GetTrg(void);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepSendSync25(unsigned char *p);

void POKETRADE_NEGO_StepWaitReplyKey(unsigned char *p)
{
    int v;GFL_NET_HANDLE_GetCurrentHandle();if(POKETRADE_SAVE_IsMessagePrintDone((char *)p)){v=KEY_GetTrg();if(v)func_020355D8(0);if(v==0){v=TOUCHPANEL_GetTrg();if(v)func_020355D8(1);if(v==0)return;}MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),0x88,(void *)(*(int *)&((struct Obj00001 *)p)->f738));POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon((char *)p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepSendSync25);}
}

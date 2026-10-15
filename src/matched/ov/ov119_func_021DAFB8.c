/*
 * function: POKETRADE_PROC_StepSendStartRound
 * address: 0x021DAFB8
 * packet: pkt_ov119_021DAFB8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepSendContinue 0x021DAF68 thumb ov119
 *   POKETRADE_PROC_StepBeginWipeOut 0x021D9434 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 */
#include "../include/Obj00001.h"
#include "../include/Obj22732.h"
typedef unsigned short u16;
typedef unsigned char u8;
extern int POKETRADE_PROC_IsNetSession(void *);
extern void POKETRADE_PROC_SetStep(void *,int),POKETRADE_PROC_StepSendContinue(void *),POKETRADE_PROC_StepBeginWipeOut(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct MsgBank;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned,unsigned);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
void POKETRADE_PROC_StepSendStartRound(char *p) {
 u8 b;
 if(POKETRADE_PROC_IsNetSession(p)) {
  b=4;
  if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,(u32)(&b))) {
   MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),136,(void *)(*(int *)&((struct Obj00001 *)p)->f738));POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon(p);
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),26,8);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendContinue);
  }
 } else {((struct Obj22732 *)(*(char * *)&((struct Obj00001 *)p)->f8))->f8=3;POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginWipeOut);}
}

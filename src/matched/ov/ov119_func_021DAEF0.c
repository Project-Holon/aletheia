/*
 * function: POKETRADE_PROC_StepShowWaitMessageA
 * address: 0x021DAEF0
 * packet: pkt_ov119_021DAEF0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020355D8 0x020355D8 arm
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_SAVE_ShowTimeIcon 0x021E1030 thumb ov119
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepWaitMessageThenClear 0x021DAEC8 thumb ov119
 *   POKETRADE_PROC_StepResetGrid 0x021DBA80 thumb ov119
 */
#include "../include/Obj00001.h"

typedef unsigned int u32;
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern int POKETRADE_PROC_IsNetSession(void *);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
typedef unsigned char  u8;
extern void func_020355D8(u8 v);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_SAVE_ShowTimeIcon(char *p);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepWaitMessageThenClear(void *);
extern void POKETRADE_PROC_StepResetGrid(char *p);
static inline int poll_a(void) {int r=KEY_GetTrg();if(r)func_020355D8(0);return r;}
static inline int poll_b(void) {int r=TOUCHPANEL_GetTrg();if(r)func_020355D8(1);return r;}
void POKETRADE_PROC_StepShowWaitMessageA(char *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
  if(poll_a() || poll_b()) {
   POKETRADE_SAVE_CloseMessageWindowClear(p);
   if(POKETRADE_PROC_IsNetSession(p)) {
    MSGDATA_ReadString((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),50,(void *)(*(int *)&((struct Obj00001 *)p)->f738));POKETRADE_SAVE_OpenMessageWindowTop(p);POKETRADE_SAVE_ShowTimeIcon(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitMessageThenClear);
   } else POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepResetGrid);
  }
 }
}

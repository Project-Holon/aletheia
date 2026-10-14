/*
 * function: POKETRADE_SAVE_StepStartSave
 * address: 0x021E0BE8
 * packet: pkt_ov119_021E0BE8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_SAVE_ApplyTradeResult 0x021E049C thumb ov119
 *   func_020108C4 0x020108C4 thumb
 *   POKETRADE_SAVE_FreeBackups 0x021E0260 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_SAVE_StepWaitSaveDone 0x021E0C44 thumb ov119
 *   POKETRADE_SAVE_StepBeginWipeOut 0x021E0C78 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
extern int POKETRADE_SAVE_IsMessagePrintDone(char *);
extern int POKETRADE_PROC_IsNetSession(void *);
extern void POKETRADE_SAVE_ApplyTradeResult(char *p);
typedef unsigned int   u32;
extern void *func_020108C4(u32 heap, u32 a1, u32 a2, u32 a3);
extern void POKETRADE_SAVE_FreeBackups(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_SAVE_StepWaitSaveDone(char *p);
extern void POKETRADE_SAVE_StepBeginWipeOut(char *);
void POKETRADE_SAVE_StepStartSave(char *p) {if(POKETRADE_SAVE_IsMessagePrintDone(p)) {if(POKETRADE_PROC_IsNetSession(p)) {POKETRADE_SAVE_ApplyTradeResult(p);((struct Obj00001 *)p)->fEF8=(int)func_020108C4(((struct Obj00001 *)p)->f5F4,*(int *)&((struct Obj00001 *)p)->f82C,(u32)POKETRADE_SAVE_FreeBackups,(u32)p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepWaitSaveDone);return;}POKETRADE_PROC_SetStep(p,(int)POKETRADE_SAVE_StepBeginWipeOut);}}

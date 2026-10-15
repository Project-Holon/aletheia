/*
 * function: POKETRADE_PROC_StepShowSummaryMessage
 * address: 0x021DB164
 * packet: pkt_ov119_021DB164
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   POKETRADE_SAVE_OpenMessageWindowTop 0x021E1024 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepOpenSummaryMenu 0x021DB10C thumb ov119
 */
#include "../include/Obj10355.h"
typedef unsigned int   u32;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void POKETRADE_SAVE_OpenMessageWindowTop(void *);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepOpenSummaryMenu(char *p);
void POKETRADE_PROC_StepShowSummaryMessage(char *p) {
 MSGDATA_ReadString((struct MsgBank *)(((struct Obj10355 *)p)->f720),0x8c,(void *)(((struct Obj10355 *)p)->f738));
 POKETRADE_SAVE_OpenMessageWindowTop(p);
 ((struct Obj10355 *)p)->f1074=1;
 POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepOpenSummaryMenu);
}

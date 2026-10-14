/*
 * function: POKETRADE_PROC_StepStartSync20
 * address: 0x021D9BC4
 * packet: pkt_ov119_021D9BC4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepWaitSync20 0x021D9B84 thumb ov119
 */
#include "../include/Obj00001.h"
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern int POKETRADE_PROC_IsNetSession(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepWaitSync20(void *);
void POKETRADE_PROC_StepStartSync20(char *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p) && ((struct Obj00001 *)p)->fF2C>30) {
  if(POKETRADE_PROC_IsNetSession(p)) GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),20,8);
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitSync20);
 }
}

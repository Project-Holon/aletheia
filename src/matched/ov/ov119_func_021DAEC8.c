/*
 * function: POKETRADE_PROC_StepWaitMessageThenClear
 * address: 0x021DAEC8
 * packet: pkt_ov119_021DAEC8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepClearOffersNewRound 0x021DAE2C thumb ov119
 */
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned,unsigned);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepClearOffersNewRound(char *p);
void POKETRADE_PROC_StepWaitMessageThenClear(void *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p)) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),25,8);
  POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepClearOffersNewRound);
 }
}

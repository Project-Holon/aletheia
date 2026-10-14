/*
 * function: POKETRADE_PROC_StepWaitSync20
 * address: 0x021D9B84
 * packet: pkt_ov119_021D9B84
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepBeginWipeOut 0x021D9434 thumb ov119
 */
extern int POKETRADE_PROC_IsNetSession(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepBeginWipeOut(void *);
void POKETRADE_PROC_StepWaitSync20(void *p) {
 if(POKETRADE_PROC_IsNetSession(p)) {
  if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),20,8)) {
   POKETRADE_SAVE_CloseMessageWindowClear(p); POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginWipeOut);
  }
 } else { POKETRADE_SAVE_CloseMessageWindowClear(p); POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginWipeOut); }
}

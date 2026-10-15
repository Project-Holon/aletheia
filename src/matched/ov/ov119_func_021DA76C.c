/*
 * function: POKETRADE_PROC_StepWaitCursorSync
 * address: 0x021DA76C
 * packet: pkt_ov119_021DA76C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepSendCursorChoice 0x021DA700 thumb ov119
 */
extern int POKETRADE_PROC_IsNetSession(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *p, unsigned int lo, unsigned int hi);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepSendCursorChoice(char *p);
void POKETRADE_PROC_StepWaitCursorSync(void *p) {
 if(!POKETRADE_PROC_IsNetSession(p) || GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),13,8)) POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendCursorChoice);
}

/*
 * function: POKETRADE_PROC_StepAfterWipeLoadBox
 * address: 0x021DAC20
 * packet: pkt_ov119_021DAC20
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   POKETRADE_PROC_StepWaitNetSync22 0x021DABE8 thumb ov119
 *   POKETRADE_PROC_StepSendBoxInfo 0x021DAB34 thumb ov119
 */
typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
extern int POKETRADE_PROC_IsNetSession(void *);
extern void POKETRADE_PROC_SetStep(void *, int);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern void POKETRADE_PROC_StepWaitNetSync22(char *p);
extern void POKETRADE_PROC_StepSendBoxInfo(char *p);
void POKETRADE_PROC_StepAfterWipeLoadBox(void *p) {
 if(WIPE_SYS_EndCheck()) {
  if(POKETRADE_PROC_IsNetSession(p)) {
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),22,8);
   POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepWaitNetSync22);
  } else { POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepSendBoxInfo); }
 }
}

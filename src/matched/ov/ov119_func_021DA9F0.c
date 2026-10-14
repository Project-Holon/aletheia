/*
 * function: func_021DA9F0
 * address: 0x021DA9F0
 * packet: pkt_ov119_021DA9F0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_SAVE_IsMessagePrintDone 0x021E12AC thumb ov119
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021DA8F8 0x021DA8F8 thumb ov119
 */
typedef unsigned int   u32;
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern u32 WIPE_SYS_EndCheck(void);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void func_021DA8F8(char *p);
void func_021DA9F0(void *p) {
 if(POKETRADE_SAVE_IsMessagePrintDone(p) && WIPE_SYS_EndCheck()) {
  POKETRADE_SAVE_CloseMessageWindowClear(p);
  POKETRADE_PROC_SetStep(p,(int)func_021DA8F8);
 }
}

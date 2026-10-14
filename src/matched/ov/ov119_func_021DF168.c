/*
 * function: POKETRADE_NEGO_StepRetryMonCheck
 * address: 0x021DF168
 * packet: pkt_ov119_021DF168
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: field p+0x11fa re-read at 0x021DF18E after store at 0x021DF18C.
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   POKETRADE_2D_DeleteAllBoxIcons 0x021E4888 thumb ov119
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   WIPE_ResetBrightness 0x02022230 thumb
 *   POKETRADE_PROC_ClearNetAutoExit 0x021D89CC thumb ov119
 *   POKETRADE_PROC_StepBeginWipeOut 0x021D9434 thumb ov119
 *   POKETRADE_NEGO_StepStartMonCheck 0x021DF0B8 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 */
#include "../include/Obj13901.h"
typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
extern void POKETRADE_2D_DeleteAllBoxIcons(char *p);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void WIPE_ResetBrightness(u32 which);
extern void POKETRADE_PROC_ClearNetAutoExit(char *p);
extern void POKETRADE_PROC_StepBeginWipeOut(void *);
extern void POKETRADE_NEGO_StepStartMonCheck(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned,unsigned);
void POKETRADE_NEGO_StepRetryMonCheck(void *p) {
 if(WIPE_SYS_EndCheck()) {
  POKETRADE_2D_DeleteAllBoxIcons(p);BG_SYS_SetSubVisiblePlanes(4);WIPE_ResetBrightness(4);
  ++*(volatile unsigned char *)&((struct Obj13901 *)p)->f11FA;
  if(*(volatile unsigned char *)&((struct Obj13901 *)p)->f11FA>=3) {POKETRADE_PROC_ClearNetAutoExit(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepBeginWipeOut);return;}
  GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),31,8);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepStartMonCheck);
 }
}

/*
 * function: POKETRADE_PROC_StepClearOffersNewRound
 * address: 0x021DAE2C
 * packet: pkt_ov119_021DAE2C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   POKETRADE_NEGO_CheckCancelTouch 0x021DD24C thumb ov119
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   POKETRADE_NEGO_CloseCancelMenu 0x021DD294 thumb ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   MI_CpuFill8 0x02082BCC arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepResetGrid 0x021DBA80 thumb ov119
 */
#include "../include/Obj10354.h"
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned,unsigned);
typedef unsigned int   u32;
extern int POKETRADE_NEGO_CheckCancelTouch(char *p);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void POKETRADE_NEGO_CloseCancelMenu(char *p, int a, int b);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void MI_CpuFill8(void *,int,int);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepResetGrid(char *p);
void POKETRADE_PROC_StepClearOffersNewRound(char *p) {
 int i;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),25,8)==0) {POKETRADE_NEGO_CheckCancelTouch(p);return;}
 POKETRADE_NEGO_CloseCancelMenu(p,1,1);POKETRADE_SAVE_CloseMessageWindowClear(p);
 p[0x11e0]=0;p[0x11e1]=0;p[0x11e8]=0;p[0x11e9]=0;
 for(i=0;i<6;i++) {
  char *q=p+(i/3)*12+(i%3)*4;
  ((struct Obj10354 *)q)->fFA4=-1;
  if(((struct Obj10354 *)q)->fFD8)MI_CpuFill8(((struct Obj10354 *)q)->fFD8,0,POKE_TOOL_GetPartyParamSize());
 }
 POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepResetGrid);
}

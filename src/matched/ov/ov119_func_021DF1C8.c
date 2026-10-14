/*
 * function: POKETRADE_NEGO_StepBeginMonCheckWipe
 * address: 0x021DF1C8
 * packet: pkt_ov119_021DF1C8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   DWC_RAP_SetVchatTalkLock 0x0215642C thumb ov009
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_StepRetryMonCheck 0x021DF168 thumb ov119
 */
#include "../include/Obj13902.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void DWC_RAP_SetVchatTalkLock(int);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_StepRetryMonCheck(void *);
void POKETRADE_NEGO_StepBeginMonCheckWipe(void *p) {
 WIPE_SYS_Start((void *)4,0,0,0,6,1,((struct Obj13902 *)p)->f5F4);
 if(((struct Obj13902 *)p)->f118C==2) DWC_RAP_SetVchatTalkLock(1);
 POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepRetryMonCheck);
}

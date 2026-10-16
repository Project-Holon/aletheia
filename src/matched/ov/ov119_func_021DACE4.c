/*
 * function: POKETRADE_PROC_StepResetForNewRound
 * address: 0x021DACE4
 * packet: pkt_ov119_021DACE4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   POKETRADE_3D_DeleteMcssSlot 0x021E36D8 thumb ov119
 *   POKETRADE_NEGO_ClearOfferSlots 0x021DD1B8 thumb ov119
 *   POKETRADE_PROC_IsHostSide 0x021D8AA8 thumb ov119
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   POKETRADE_SAVE_CloseMessageWindowClear 0x021E1098 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepRestartNetSession 0x021DAC60 thumb ov119
 */
#include "../include/Obj04477.h"
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void POKETRADE_3D_DeleteMcssSlot(void *,int);
typedef unsigned int   u32;
extern void POKETRADE_NEGO_ClearOfferSlots(char *p);
extern int POKETRADE_PROC_IsHostSide(void *);
extern u32 POKE_TOOL_GetPartyParamSize(void);
struct Obj;
extern void MI_CpuFill8(void *,int,int);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepRestartNetSession(char *p);
void POKETRADE_PROC_StepResetForNewRound(char *p) {
 int i;
 GFL_NET_SYSTEM_GetCurrentAid();((struct Obj04477 *)p)->fF88=-1;((struct Obj04477 *)p)->fF84=-1;((struct Obj04477 *)p)->f800=0;((struct Obj04477 *)p)->fF60=0;((struct Obj04477 *)p)->f1060=0;
 POKETRADE_3D_DeleteMcssSlot(p,0);POKETRADE_3D_DeleteMcssSlot(p,1);if(POKETRADE_PROC_IsHostSide(p))POKETRADE_NEGO_ClearOfferSlots(p);
 MI_CpuFill8(((struct Obj04477 *)p)->f5DC,0,POKE_TOOL_GetPartyParamSize());MI_CpuFill8(((struct Obj04477 *)p)->f5E0,0,POKE_TOOL_GetPartyParamSize());
 for(i=0;i<10;i++) {if(*(int *)(p+0xefc+4*i))CLACT_SetActorDrawEnable((struct Obj *)*(int *)(p+0xefc+4*i),1);}
 POKETRADE_SAVE_CloseMessageWindowClear(p);POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepRestartNetSession);
}

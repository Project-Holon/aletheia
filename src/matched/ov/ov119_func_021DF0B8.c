/*
 * function: POKETRADE_NEGO_StepStartMonCheck
 * address: 0x021DF0B8
 * packet: pkt_ov119_021DF0B8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Second loop accesses use p+i*4+0xfe4, keeping the offset in r7 rather than hoisting p+0xfe4.
 * symbols:
 *   DWC_RAPCOMMON_CreateSubHeapUnlimited 0x02156E24 thumb ov009
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   func_0200853C 0x0200853C thumb
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   NHTTP_RAP_AllocPostData 0x021B98A0 thumb ov114
 *   NHTTP_RAP_AppendPostData 0x021B98D8 thumb ov114
 *   NHTTP_RAP_CreatePostRequest 0x021B98F8 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   POKETRADE_PROC_IsMonValid 0x021D89EC thumb ov119
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_NEGO_AbortHttpRequest 0x021DEEFC thumb ov119
 *   POKETRADE_NEGO_StepPollMonCheck 0x021DEF1C thumb ov119
 */
#include "../include/Obj02827.h"
#include "../include/Obj22746.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void DWC_RAPCOMMON_CreateSubHeapUnlimited(int,int,int);
extern void DWC_RAP_SetErrorCallback(int a0, int a1);
typedef unsigned int   u32;
struct Sub0200852CObj;
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern u8 *NHTTP_RAP_Create(int,int,int);
extern void NHTTP_RAP_AllocPostData(u8 *,int,int,int);
extern void NHTTP_RAP_AppendPostData(u8 *,int,int);
extern int NHTTP_RAP_CreatePostRequest(u8 *);
extern int NHTTP_RAP_StartConnection(u8 *);
extern int POKETRADE_PROC_IsMonValid(const u8 *p);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_NEGO_AbortHttpRequest(void **p);
extern void POKETRADE_NEGO_StepPollMonCheck(u8 *p);
void POKETRADE_NEGO_StepStartMonCheck(char *p) {
 int n=0;
 int i;
 DWC_RAPCOMMON_CreateSubHeapUnlimited(13,0x10000,((struct Obj02827 *)p)->f5F4);
 *(u8 * *)&((struct Obj02827 *)p)->f0=NHTTP_RAP_Create(((struct Obj02827 *)p)->f5F4,func_0200853C(((struct Obj02827 *)p)->f830),((struct Obj22746 *)(*(char * *)&((struct Obj02827 *)p)->f8))->f24);
 DWC_RAP_SetErrorCallback((int)POKETRADE_NEGO_AbortHttpRequest,(int)p);
 for(i=0;i<3;i++) if(POKETRADE_PROC_IsMonValid(*(void **)(p+0xfe4+i*4))) n++;
 NHTTP_RAP_AllocPostData(*(u8 * *)&((struct Obj02827 *)p)->f0,((struct Obj02827 *)p)->f5F4,POKE_TOOL_GetPartyParamSize()*n,2);
 for(i=0;i<3;i++) if(POKETRADE_PROC_IsMonValid(*(void **)(p+i*4+0xfe4))) NHTTP_RAP_AppendPostData(*(u8 * *)&((struct Obj02827 *)p)->f0,*(int *)(p+i*4+0xfe4),POKE_TOOL_GetPartyParamSize());
 NHTTP_RAP_CreatePostRequest(*(u8 * *)&((struct Obj02827 *)p)->f0);NHTTP_RAP_StartConnection(*(u8 * *)&((struct Obj02827 *)p)->f0);POKETRADE_PROC_SetStep(p,(int)POKETRADE_NEGO_StepPollMonCheck);
}

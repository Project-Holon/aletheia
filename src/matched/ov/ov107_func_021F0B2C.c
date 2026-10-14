/*
 * function: MB_PARENT_SYS_EventCallback
 * address: 0x021F0B2C
 * packet: pkt_ov107_021F0B2C
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MB_PARENT_SYS_GetState 0x021F0D28 thumb ov107
 *   MB_PARENT_SYS_GetChildStage 0x021F0D34 thumb ov107
 *   MB_PARENT_SYS_EndIfAllBootable 0x021F0B04 thumb ov107
 *   MB_PARENT_SYS_RejectRequest 0x021F0938 thumb ov107
 *   MB_PARENT_SYS_CheckRequest 0x021F08E4 thumb ov107
 *   MB_PARENT_SYS_StartSending 0x021F09B0 thumb ov107
 *   MB_CommGetChildUser 0x021F1B64 arm ov107
 *   MB_PARENT_SYS_SetState 0x021F0D1C thumb ov107
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   GFL_NET_FreeAligned 0x0203D7FC arm
 *   func_02034714 0x02034714 arm
 *   gMbParentSys 0x021F6EAC data a4
 *   gMbChildEntries 0x021F6EC8 data a4
 *   d_021F6EDE 0x021F6EDE data a2
 *   d_021F6EDF 0x021F6EDF data a1
 *   d_021F6EE0 0x021F6EE0 data a1
 *   d_021F6EE1 0x021F6EE1 data a1
 *   d_021F6EE2 0x021F6EE2 data a1
 *   d_021F6EE3 0x021F6EE3 data a1
 *   d_021F6EE4 0x021F6EE4 data a2
 *   d_021F6E24 0x021F6E24 data a4
 */
#include "../include/Obj04440.h"
#include "../include/G_Masks.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 MB_PARENT_SYS_GetState(void);
extern int MB_PARENT_SYS_GetChildStage(u16);
extern void MB_PARENT_SYS_EndIfAllBootable(void),MB_PARENT_SYS_RejectRequest(u16),MB_PARENT_SYS_CheckRequest(u16),MB_PARENT_SYS_StartSending(u16);
extern void *MB_CommGetChildUser(u16);
extern void MB_PARENT_SYS_SetState(u16);
extern u32 OS_DisableInterrupts(void),OS_RestoreInterrupts(u32);
extern void MI_CpuCopy8(const void *,void *,u32);
extern u32 func_020307B0(void *p);
extern void GFL_NET_FreeAligned(void *);
extern void func_02034714(const char *expr, u32 line, const char *file);
typedef struct {void *f00,*f04;u16 f08,f0A,f0C,f0E,f10,f12,f14;} Masks;
extern struct Masks gMbParentSys;
extern u8 gMbChildEntries[],d_021F6EDE[],d_021F6EDF[],d_021F6EE0[],d_021F6EE1[],d_021F6EE2[],d_021F6EE3[],d_021F6EE4[],d_021F6E24[];
#define H(o) (*(u16 *)((u32)&gMbParentSys+(o)))
#define P(o) (*(void **)((u32)&gMbParentSys+(o)))
void MB_PARENT_SYS_EventCallback(u16 aid,u32 event,u8 *p)
{
 u32 state;u16 mask;void *q;u32 offset;
 switch(event){
 case 2:
  if(MB_PARENT_SYS_GetState()!=2)break;
  state=OS_DisableInterrupts();H(10)|=(u16)(1<<aid);OS_RestoreInterrupts(state);
  offset=30*(aid-1);
  *(u8 *)((u32)d_021F6EDE+offset)=p[10];
  *(u8 *)((u32)d_021F6EDF+offset)=p[11];
  *(u8 *)((u32)d_021F6EE0+offset)=p[12];
  *(u8 *)((u32)d_021F6EE1+offset)=p[13];
  *(u8 *)((u32)d_021F6EE2+offset)=p[14];
  *(u8 *)((u32)d_021F6EE3+offset)=p[15];
  *(u16 *)((u32)d_021F6EE4+offset)=aid;break;
 case 3:
  if(MB_PARENT_SYS_GetChildStage(aid)==6)break;
  mask=~(1<<aid);state=OS_DisableInterrupts();
  H(10)&=mask;H(12)&=mask;H(14)&=mask;H(16)&=mask;H(18)&=mask;H(20)&=mask;
  OS_RestoreInterrupts(state);MB_PARENT_SYS_EndIfAllBootable();break;
 case 10:
  if(MB_PARENT_SYS_GetState()!=2){MB_PARENT_SYS_RejectRequest(aid);break;}
  H(12)|=(u16)(1<<aid);MB_PARENT_SYS_CheckRequest(aid);
  q=MB_CommGetChildUser(aid);if(q)MI_CpuCopy8(q,(void *)((u32)gMbChildEntries+30*(aid-1)),22);break;
 case 14:
  H(12)&=(u16)~(1<<aid);H(14)|=(u16)(1<<aid);MB_PARENT_SYS_StartSending(aid);break;
 case 7:
  H(16)&=(u16)~(1<<aid);H(18)|=(u16)(1<<aid);break;
 case 9:
  H(18)&=(u16)~(1<<aid);H(20)|=(u16)(1<<aid);MB_PARENT_SYS_EndIfAllBootable();break;
 case 12:
  if(MB_PARENT_SYS_GetState()==4)MB_PARENT_SYS_SetState(5);else MB_PARENT_SYS_SetState(0);
  if(P(0)){func_020307B0(P(0));P(0)=0;}
  if(P(4)){GFL_NET_FreeAligned(P(4));P(4)=0;}break;
 case 13:
  switch(((struct Obj04440 *)p)->f0){case 1:case 2:case 9:MB_PARENT_SYS_SetState(7);break;case 8:break;}break;
 case 1:case 4:case 5:case 6:case 8:case 11:
 break;
 case 0:
 default:func_02034714((const char *)d_021F6E24,0,(const char *)d_021F6E24);break;
 }
}

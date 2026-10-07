/*
 * file:     mb_comm_sys_p11.c
 * unit:     yes
 * function: func_021F0B04, func_021F0B2C, func_021F0D1C, func_021F0D28
 * address:  0x021F0B04
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021F6EAC 0x021F6EAC data a4
 *   func_021F5F74 0x021F5F74 arm ov107
 *   func_021F0D34 0x021F0D34 thumb ov107
 *   func_021F0938 0x021F0938 thumb ov107
 *   func_021F08E4 0x021F08E4 thumb ov107
 *   func_021F09B0 0x021F09B0 thumb ov107
 *   func_021F1B64 0x021F1B64 arm ov107
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_0203D7FC 0x0203D7FC arm
 *   func_02034714 0x02034714 arm
 *   d_021F6EC8 0x021F6EC8 data a4
 *   d_021F6EDE 0x021F6EDE data a2
 *   d_021F6EDF 0x021F6EDF data a1
 *   d_021F6EE0 0x021F6EE0 data a1
 *   d_021F6EE1 0x021F6EE1 data a1
 *   d_021F6EE2 0x021F6EE2 data a1
 *   d_021F6EE3 0x021F6EE3 data a1
 *   d_021F6EE4 0x021F6EE4 data a2
 *   d_021F6E24 0x021F6E24 data a4
 */
#include "../../matched/include/G_Masks.h"
#include "../../matched/include/Obj04440.h"

#define H(o) (*(u16 *)((u32)&d_021F6EAC+(o)))
#define P(o) (*(void **)((u32)&d_021F6EAC+(o)))
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {void *f00,*f04;u16 f08,f0A,f0C,f0E,f10,f12,f14;} Masks;

typedef short s16;

typedef signed char s8;

typedef int s32;

extern void func_021F5F74(void);
extern int func_021F0D34(u16);
extern void func_021F0B04(void),func_021F0938(u16),func_021F08E4(u16),func_021F09B0(u16);
extern void *func_021F1B64(u16);
extern u32 func_02087988(void),func_0208799C(u32);
extern void func_02082D44(const void *,void *,u32);
extern u32 func_020307B0(void *p);
extern void func_0203D7FC(void *);
extern void func_02034714(const char *expr, u32 line, const char *file);
void func_021F0B04(void);
void func_021F0B2C(u16 aid,u32 event,u8 *p);
void func_021F0D1C(u16 v);
u16 func_021F0D28(void);
extern struct Masks d_021F6EAC;
extern u8 d_021F6EC8[],d_021F6EDE[],d_021F6EDF[],d_021F6EE0[],d_021F6EE1[],d_021F6EE2[],d_021F6EE3[],d_021F6EE4[],d_021F6E24[];

void func_021F0B04(void) { if(*(u16 *)(((u8 *)&d_021F6EAC)+8)==4 && *(u16 *)(((u8 *)&d_021F6EAC)+10)==*(u16 *)(((u8 *)&d_021F6EAC)+20) && *(int *)(((u8 *)&d_021F6EAC)+24)==1){*(int *)(((u8 *)&d_021F6EAC)+24)=0;func_021F5F74();} }

void func_021F0B2C(u16 aid,u32 event,u8 *p)
{
 u32 state;u16 mask;void *q;u32 offset;
 switch(event){
 case 2:
  if(func_021F0D28()!=2)break;
  state=func_02087988();H(10)|=(u16)(1<<aid);func_0208799C(state);
  offset=30*(aid-1);
  *(u8 *)((u32)d_021F6EDE+offset)=p[10];
  *(u8 *)((u32)d_021F6EDF+offset)=p[11];
  *(u8 *)((u32)d_021F6EE0+offset)=p[12];
  *(u8 *)((u32)d_021F6EE1+offset)=p[13];
  *(u8 *)((u32)d_021F6EE2+offset)=p[14];
  *(u8 *)((u32)d_021F6EE3+offset)=p[15];
  *(u16 *)((u32)d_021F6EE4+offset)=aid;break;
 case 3:
  if(func_021F0D34(aid)==6)break;
  mask=~(1<<aid);state=func_02087988();
  H(10)&=mask;H(12)&=mask;H(14)&=mask;H(16)&=mask;H(18)&=mask;H(20)&=mask;
  func_0208799C(state);func_021F0B04();break;
 case 10:
  if(func_021F0D28()!=2){func_021F0938(aid);break;}
  H(12)|=(u16)(1<<aid);func_021F08E4(aid);
  q=func_021F1B64(aid);if(q)func_02082D44(q,(void *)((u32)d_021F6EC8+30*(aid-1)),22);break;
 case 14:
  H(12)&=(u16)~(1<<aid);H(14)|=(u16)(1<<aid);func_021F09B0(aid);break;
 case 7:
  H(16)&=(u16)~(1<<aid);H(18)|=(u16)(1<<aid);break;
 case 9:
  H(18)&=(u16)~(1<<aid);H(20)|=(u16)(1<<aid);func_021F0B04();break;
 case 12:
  if(func_021F0D28()==4)func_021F0D1C(5);else func_021F0D1C(0);
  if(P(0)){func_020307B0(P(0));P(0)=0;}
  if(P(4)){func_0203D7FC(P(4));P(4)=0;}break;
 case 13:
  switch(((struct Obj04440 *)p)->f0){case 1:case 2:case 9:func_021F0D1C(7);break;case 8:break;}break;
 case 1:case 4:case 5:case 6:case 8:case 11:
 break;
 case 0:
 default:func_02034714((const char *)d_021F6E24,0,(const char *)d_021F6E24);break;
 }
}

void func_021F0D1C(u16 v) { *(u16 *)(((u8 *)&d_021F6EAC) + 8) = v; }

u16 func_021F0D28(void) { return *(u16 *)(((u8 *)&d_021F6EAC) + 8); }

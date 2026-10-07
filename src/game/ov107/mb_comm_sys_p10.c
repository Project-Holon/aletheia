/*
 * file:     mb_comm_sys_p10.c
 * unit:     yes
 * function: func_021F0938, func_021F09B0, func_021F0A28, func_021F0A64, func_021F0AE4
 * address:  0x021F0938
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
 *   func_021F1C30 0x021F1C30 arm ov107
 *   func_021F5FB0 0x021F5FB0 arm ov107
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   d_021F6EAC 0x021F6EAC data a4
 *   func_021F0D1C 0x021F0D1C thumb ov107
 *   func_021F1BE0 0x021F1BE0 arm ov107
 *   func_021F5F74 0x021F5F74 arm ov107
 */
#include "../../matched/include/G_Masks.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {u8 pad[10];u16 f0A,f0C,f0E,f10,f12,f14;} Masks;

extern int func_021F1C30(u16,int);
extern void func_021F5FB0(u16);
extern u32 func_02087988(void);
extern u32 func_0208799C(u32);
extern void func_021F0D1C(u16);
extern int func_021F1BE0(u16);
extern void func_021F0D1C(u16),func_021F5F74(void);
void func_021F0938(u16 aid);
void func_021F09B0(u16 aid);
int func_021F0A28(void);
void func_021F0A64(void);
void func_021F0AE4(void);
extern struct Masks d_021F6EAC;

void func_021F0938(u16 aid){u16 mask;u32 state;
if(!func_021F1C30(aid,0)){mask=~(1<<aid);state=func_02087988();d_021F6EAC.f0A&=mask;d_021F6EAC.f0C&=mask;d_021F6EAC.f0E&=mask;d_021F6EAC.f10&=mask;d_021F6EAC.f12&=mask;d_021F6EAC.f14&=mask;func_0208799C(state);func_021F5FB0(aid);}
else {state=func_02087988();d_021F6EAC.f0C&=(u16)~(1<<aid);d_021F6EAC.f0A&=(u16)~(1<<aid);func_0208799C(state);}}

void func_021F09B0(u16 aid){u16 mask;u32 state;u16 bit;
if(!func_021F1C30(aid,2)){mask=~(1<<aid);state=func_02087988();d_021F6EAC.f0A&=mask;d_021F6EAC.f0C&=mask;d_021F6EAC.f0E&=mask;d_021F6EAC.f10&=mask;d_021F6EAC.f12&=mask;d_021F6EAC.f14&=mask;func_0208799C(state);func_021F5FB0(aid);}
else {state=func_02087988();mask=~(1<<aid);bit=1<<aid;d_021F6EAC.f0E&=mask;d_021F6EAC.f10|=bit;func_0208799C(state);}}

int func_021F0A28(void) { u16 i; if(!*(u16 *)(((u8 *)&d_021F6EAC)+10))return 0;for(i=1;i<16;i++){if(*(u16 *)(((u8 *)&d_021F6EAC)+10)&(1<<i)){if(!func_021F1BE0(i))return 0;}}return 1; }

void func_021F0A64(void){u32 active;u16 aid;int bit;u16 mask;u32 state;
active=0;for(aid=1;aid<16;aid++){bit=1<<aid;if(d_021F6EAC.f12&bit){if(!func_021F1C30(aid,3)){mask=~bit;state=func_02087988();d_021F6EAC.f0A&=mask;d_021F6EAC.f0C&=mask;d_021F6EAC.f0E&=mask;d_021F6EAC.f10&=mask;d_021F6EAC.f12&=mask;d_021F6EAC.f14&=mask;func_0208799C(state);func_021F5FB0(aid);}else active|=(u16)bit;}}
if(!active){func_021F0D1C(7);return;}func_021F0D1C(4);}

void func_021F0AE4(void) { func_021F0D1C(6);if(*(int *)(((u8 *)&d_021F6EAC)+24)==1){*(int *)(((u8 *)&d_021F6EAC)+24)=0;func_021F5F74();} }

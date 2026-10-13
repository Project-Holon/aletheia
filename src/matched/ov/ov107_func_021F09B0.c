/*
 * function: func_021F09B0
 * address: 0x021F09B0
 * packet: pkt_ov107_021F09B0
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F1C30 0x021F1C30 arm ov107
 *   func_021F5FB0 0x021F5FB0 arm ov107
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   d_021F6EAC 0x021F6EAC data a4
 *   func_021F0D1C 0x021F0D1C thumb ov107
 */

#include "../include/G_Masks.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F1C30(u16,int);
extern void func_021F5FB0(u16);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32);
extern void func_021F0D1C(u16);
typedef struct {u8 pad[10];u16 f0A,f0C,f0E,f10,f12,f14;} Masks;
extern struct Masks d_021F6EAC;
void func_021F09B0(u16 aid){u16 mask;u32 state;u16 bit;
if(!func_021F1C30(aid,2)){mask=~(1<<aid);state=OS_DisableInterrupts();d_021F6EAC.f0A&=mask;d_021F6EAC.f0C&=mask;d_021F6EAC.f0E&=mask;d_021F6EAC.f10&=mask;d_021F6EAC.f12&=mask;d_021F6EAC.f14&=mask;OS_RestoreInterrupts(state);func_021F5FB0(aid);}
else {state=OS_DisableInterrupts();mask=~(1<<aid);bit=1<<aid;d_021F6EAC.f0E&=mask;d_021F6EAC.f10|=bit;OS_RestoreInterrupts(state);}}

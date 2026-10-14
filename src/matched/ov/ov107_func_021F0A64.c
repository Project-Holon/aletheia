/*
 * function: MB_PARENT_SYS_StartBoot
 * address: 0x021F0A64
 * packet: pkt_ov107_021F0A64
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MB_CommResponseRequest 0x021F1C30 arm ov107
 *   MB_DisconnectChild 0x021F5FB0 arm ov107
 *   OS_DisableInterrupts 0x02087988 arm
 *   OS_RestoreInterrupts 0x0208799C arm
 *   gMbParentSys 0x021F6EAC data a4
 *   MB_PARENT_SYS_SetState 0x021F0D1C thumb ov107
 */

#include "../include/G_Masks.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int MB_CommResponseRequest(u16,int);
extern void MB_DisconnectChild(u16);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32);
extern void MB_PARENT_SYS_SetState(u16);
typedef struct {u8 pad[10];u16 f0A,f0C,f0E,f10,f12,f14;} Masks;
extern struct Masks gMbParentSys;
void MB_PARENT_SYS_StartBoot(void){u32 active;u16 aid;int bit;u16 mask;u32 state;
active=0;for(aid=1;aid<16;aid++){bit=1<<aid;if(gMbParentSys.f12&bit){if(!MB_CommResponseRequest(aid,3)){mask=~bit;state=OS_DisableInterrupts();gMbParentSys.f0A&=mask;gMbParentSys.f0C&=mask;gMbParentSys.f0E&=mask;gMbParentSys.f10&=mask;gMbParentSys.f12&=mask;gMbParentSys.f14&=mask;OS_RestoreInterrupts(state);MB_DisconnectChild(aid);}else active|=(u16)bit;}}
if(!active){MB_PARENT_SYS_SetState(7);return;}MB_PARENT_SYS_SetState(4);}

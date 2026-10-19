/*
 * function: MB_PARENT_SYS_AcceptRequest
 * address: 0x021F08E4
 * packet: pkt_ov107_021F08E4
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
 */

#include "../include/G_Masks.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int MB_CommResponseRequest(u16,int);
extern void MB_DisconnectChild(u16);
extern u32 OS_DisableInterrupts(void);
extern u32 OS_RestoreInterrupts(u32);
typedef struct {u8 pad[10];u16 f0A,f0C,f0E,f10,f12,f14;} Masks;
extern struct Masks gMbParentSys;
void MB_PARENT_SYS_AcceptRequest(u16 aid){
 u16 mask; u32 state;
 if(!MB_CommResponseRequest(aid,1)){
 mask=~(1<<aid);state=OS_DisableInterrupts();
 gMbParentSys.f0A&=mask;
 gMbParentSys.f0C&=mask;
 gMbParentSys.f0E&=mask;
 gMbParentSys.f10&=mask;
 gMbParentSys.f12&=mask;
 gMbParentSys.f14&=mask;
 OS_RestoreInterrupts(state);MB_DisconnectChild(aid);
 }
}

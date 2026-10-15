/*
 * function: MB_COMM_SYS_ResetHook
 * address: 0x021EFCA8
 * packet: pkt_ov107_021EFCA8
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MB_PARENT_SYS_IsRegistered 0x021F0DDC thumb ov107
 *   MB_PARENT_SYS_Cancel 0x021F0AE4 thumb ov107
 *   MB_PARENT_SYS_GetState 0x021F0D28 thumb ov107
 *   OS_WaitIrq 0x0208459C arm
 *   WIH_End 0x02179570 thumb ov014
 *   gMbParentUi 0x021F6EA0 data ov107 a4
 *   MB_COMM_SYS_WmEndCallback 0x021EFC10 thumb ov107
 */
#include "../include/Obj22279.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned MB_PARENT_SYS_IsRegistered(void);
extern void MB_PARENT_SYS_Cancel(void);
extern u16 MB_PARENT_SYS_GetState(void);
typedef unsigned int   u32;
extern void OS_WaitIrq(int clear, u32 irqFlags);
extern int WIH_End(void (*cb)(int));
extern u8 gMbParentUi[];
extern int MB_COMM_SYS_WmEndCallback(void);
void MB_COMM_SYS_ResetHook(u8 *p) {
 unsigned v=MB_PARENT_SYS_IsRegistered();
 if(v==1) MB_PARENT_SYS_Cancel();
 while(MB_PARENT_SYS_GetState()!=0&&MB_PARENT_SYS_GetState()!=5) OS_WaitIrq(1,1);
 if(((struct Obj22279 *)p)->f1C==1) {
 *(int *)(gMbParentUi+8)=0;
 while(WIH_End((void (*)(int))((int)MB_COMM_SYS_WmEndCallback))) OS_WaitIrq(1,1);
 while(*(int *)(gMbParentUi+8)==0) OS_WaitIrq(1,1);
 }
}

/*
 * function: MB_PARENT_SYS_Cancel
 * address: 0x021F0AE4
 * packet: pkt_ov107_021F0AE4
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gMbParentSys 0x021F6EAC data a4
 *   MB_PARENT_SYS_SetState 0x021F0D1C thumb ov107
 *   func_021F5F74 0x021F5F74 arm ov107
 */

#include "../include/G_Masks.h"

typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern struct Masks gMbParentSys;extern void MB_PARENT_SYS_SetState(u16),func_021F5F74(void);
void MB_PARENT_SYS_Cancel(void) { MB_PARENT_SYS_SetState(6);if(*(int *)(((u8 *)&gMbParentSys)+24)==1){*(int *)(((u8 *)&gMbParentSys)+24)=0;func_021F5F74();} }

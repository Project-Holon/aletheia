/*
 * function: WORLDTRADE_SERVER_StateShowErrorMessageB
 * address: 0x02202000
 * packet: pkt_ov135_02202000
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   WORLDTRADE_SERVER_GetErrorMessageId 0x02201F18 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WORLDTRADE_DeleteTimeIcon 0x021F4FC4 thumb ov135
 *   WORLDTRADE_SUBLCD_UpdateSlotAnims 0x021FFBC8 thumb ov135
 */
#include "../include/Obj00018.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 WORLDTRADE_SERVER_GetErrorMessageId(u8 *p);
extern void WORLDTRADE_SetNextState(u8 *,u32,u32),WORLDTRADE_SetStateAndReturn(u8 *,u32,u32),WORLDTRADE_DeleteTimeIcon(u8 *),WORLDTRADE_SUBLCD_UpdateSlotAnims(u8 *);
int WORLDTRADE_SERVER_StateShowErrorMessageB(u8 *p) { WORLDTRADE_SERVER_GetErrorMessageId(p); WORLDTRADE_SetNextState(p,41,40); WORLDTRADE_SetStateAndReturn(p,1,0); WORLDTRADE_DeleteTimeIcon(p); if(((struct Obj00018 *)p)->fD0>0) WORLDTRADE_SUBLCD_UpdateSlotAnims(p); return 2; }

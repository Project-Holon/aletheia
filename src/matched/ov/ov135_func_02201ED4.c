/*
 * function: WORLDTRADE_SERVER_StateShowRetryMessage
 * address: 0x02201ED4
 * packet: pkt_ov135_02201ED4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_INPUT_PrintStringPlain 0x021F90A0 thumb ov135
 *   WORLDTRADE_SetNextState 0x021F4E98 thumb ov135
 *   WORLDTRADE_SetStateAndReturn 0x021F4EC0 thumb ov135
 *   WORLDTRADE_DeleteTimeIcon 0x021F4FC4 thumb ov135
 *   WORLDTRADE_SUBLCD_UpdateSlotAnims 0x021FFBC8 thumb ov135
 */
#include "../include/Obj00018.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WORLDTRADE_INPUT_PrintStringPlain(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void WORLDTRADE_SetNextState(u8 *, u32, u32);
extern void WORLDTRADE_SetStateAndReturn(u8 *, u32, u32);
extern void WORLDTRADE_DeleteTimeIcon(u8 *);
extern void WORLDTRADE_SUBLCD_UpdateSlotAnims(u8 *);
int WORLDTRADE_SERVER_StateShowRetryMessage(u8 *p)
{
    WORLDTRADE_INPUT_PrintStringPlain((u32)p, (u32)(((struct Obj00018 *)p)->fB6C), 0x99, 1, 0xf0f);
    WORLDTRADE_SetNextState(p, 0x2a, 0x28);
    WORLDTRADE_SetStateAndReturn(p, 1, 0);
    WORLDTRADE_DeleteTimeIcon(p);
    WORLDTRADE_SUBLCD_UpdateSlotAnims(p);
    return 2;
}

/*
 * function: UNION_MSG_CheckTalkPrintEnd
 * address: 0x0217F1EC
 * packet: pkt_ov019_0217F1EC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_MSGBG_PlainWinMain 0x021916E0 thumb ov021
 */
#include "../include/Obj00033.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 FIELD_MSGBG_PlainWinMain(u32 *p);
u32 UNION_MSG_CheckTalkPrintEnd(u8 *p)
{
    if (*(u32 * *)&((struct Obj00033 *)p)->f280C == 0 || ((struct Obj00033 *)p)->f2828 == 0) return 1;
    return FIELD_MSGBG_PlainWinMain(*(u32 * *)&((struct Obj00033 *)p)->f280C);
}

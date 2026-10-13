/*
 * function: UNION_MSG_SetupYesNo
 * address: 0x0217F22C
 * packet: pkt_ov019_0217F22C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELDMAP_GetMsgBg 0x02188C54 thumb ov021
 *   FIELD_MSGBG_CreateYesNoMenu 0x02190BE4 thumb ov021
 */
#include "../include/Obj00033.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern u32 *FIELD_MSGBG_CreateYesNoMenu(u16 *a, u32 b);
void UNION_MSG_SetupYesNo(u8 *p, u32 a)
{
    if (*(u32 * *)&((struct Obj00033 *)p)->f2814 == 0) {
        *(u32 * *)&((struct Obj00033 *)p)->f2814 = FIELD_MSGBG_CreateYesNoMenu((u16 *)FIELDMAP_GetMsgBg((u8 *)a), 0);
    }
}

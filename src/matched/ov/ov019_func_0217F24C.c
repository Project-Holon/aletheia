/*
 * function: UNION_MSG_DeleteYesNo
 * address: 0x0217F24C
 * packet: pkt_ov019_0217F24C
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_MSGBG_DeleteMenuFunc 0x021909BC thumb ov021
 */
#include "../include/Obj00033.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int FIELD_MSGBG_DeleteMenuFunc(void *a);
void UNION_MSG_DeleteYesNo(u8 *p)
{
    if (((struct Obj00033 *)p)->f2814 != 0) {
        FIELD_MSGBG_DeleteMenuFunc((void *)(((struct Obj00033 *)p)->f2814));
        ((struct Obj00033 *)p)->f2814 = 0;
    }
}

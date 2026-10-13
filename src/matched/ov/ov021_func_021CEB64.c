/*
 * function: COMM_ENTRY_MENU_EndYesNo
 * address:  0x021CEB64
 * packet:   pkt_ov021_021CEB64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 */
#include "../include/Obj07591.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FIELD_MSGBG_DeleteMenuFunc(void *a);

void COMM_ENTRY_MENU_EndYesNo(u8 *p)
{
    if (((struct Obj07591 *)p)->f140 != 0) {
        FIELD_MSGBG_DeleteMenuFunc((void *)(((struct Obj07591 *)p)->f140));
        ((struct Obj07591 *)p)->f140 = 0;
        p[0x40e] = 0;
    }
}

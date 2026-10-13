/*
 * function: PARTY_SELECT_LIST_DeleteTextWindow
 * address:  0x021CCFD8
 * packet:   pkt_021CCFD8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on the word at +0xb0.
 *
 * symbols:
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18359.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_MSGBG_DeleteSysWin(u32 a);

void PARTY_SELECT_LIST_DeleteTextWindow(u8 *p)
{
    FIELD_MSGBG_DeleteSysWin(((struct Obj18359 *)p)->fB0);
}

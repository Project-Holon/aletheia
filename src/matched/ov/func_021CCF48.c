/*
 * function: PARTY_SELECT_LIST_ProcessMenu
 * address:  0x021CCF48
 * packet:   pkt_021CCF48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on the word at +0xac.
 *
 * symbols:
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18357.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_MSGBG_DeleteMenuFunc(void *a);

void PARTY_SELECT_LIST_ProcessMenu(u8 *p)
{
    FIELD_MSGBG_DeleteMenuFunc((void *)(((struct Obj18357 *)p)->fAC));
}

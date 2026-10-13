/*
 * function: PARTY_SELECT_LIST_IsTextDone
 * address:  0x021CCFF8
 * packet:   pkt_021CCFF8
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
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18361.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_MSGBG_SysWinMain(u32 *p);

int PARTY_SELECT_LIST_IsTextDone(u8 *p)
{
    return FIELD_MSGBG_SysWinMain((u32 *)(((struct Obj18361 *)p)->fB0));
}

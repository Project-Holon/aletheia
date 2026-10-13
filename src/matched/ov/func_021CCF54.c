/*
 * function: PARTY_SELECT_LIST_GetMenuResult
 * address:  0x021CCF54
 * packet:   pkt_021CCF54
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
 *   FIELD_MSGBG_MenuFuncMain  0x021909E4  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18358.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Handle;
extern int FIELD_MSGBG_MenuFuncMain(struct Handle *h);

u32 PARTY_SELECT_LIST_GetMenuResult(u8 *p)
{
    return FIELD_MSGBG_MenuFuncMain((struct Handle *)(((struct Obj18358 *)p)->fAC));
}

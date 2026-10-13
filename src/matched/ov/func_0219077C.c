/*
 * function: FIELD_MSGBG_IsMsgWinTransDone
 * address:  0x0219077C
 * packet:   pkt_0219077C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x4.
 *
 * symbols:
 *   FIELD_MSGBG_IsMsgPrintTransDone  0x0219061C  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17928.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_MSGBG_IsMsgPrintTransDone(u32 *p);

int FIELD_MSGBG_IsMsgWinTransDone(u8 *p)
{
    return FIELD_MSGBG_IsMsgPrintTransDone((u32 *)(((struct Obj17928 *)p)->f4));
}

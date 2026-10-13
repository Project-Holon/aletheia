/*
 * function: FIELD_MSGBG_ClearPrintQue
 * address:  0x02190490
 * packet:   pkt_02190490
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0xc.
 *
 * symbols:
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17921.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct PrintSys;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);

void FIELD_MSGBG_ClearPrintQue(u8 *p)
{
    PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj17921 *)p)->fC));
}

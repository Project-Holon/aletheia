/*
 * function: FIELD_MSGBG_IsPrintQueFinished
 * address:  0x0219049C
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
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj17922.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct PrintSys;
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);

int FIELD_MSGBG_IsPrintQueFinished(u8 *p)
{
    return PRINTSYS_QUE_IsFinished((const struct PrintSys *)(((struct Obj17922 *)p)->fC));
}

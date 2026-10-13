/*
 * function: FIELD_SUBPROC_MGR_RunDraw
 * address:  0x021BB954
 * packet:   pkt_021BB954
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: the object's word at +0x14.
 *
 * symbols:
 *   func_02030D28  0x02030D28  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18175.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern void func_02030D28(struct Ctx *c);

void FIELD_SUBPROC_MGR_RunDraw(u8 *p)
{
    func_02030D28((struct Ctx *)(((struct Obj18175 *)p)->f14));
}

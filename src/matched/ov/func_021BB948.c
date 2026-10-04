/*
 * function: func_021BB948
 * address:  0x021BB948
 * packet:   pkt_021BB948
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call on the word at +0x10.
 *
 * symbols:
 *   func_02030D28  0x02030D28  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj18174.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ctx;
extern void func_02030D28(struct Ctx *c);

void func_021BB948(u8 *p)
{
    func_02030D28((struct Ctx *)(((struct Obj18174 *)p)->f10));
}

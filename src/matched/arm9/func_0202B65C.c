/*
 * function: func_0202B65C
 * address:  0x0202B65C
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_0202B59C.c is now a manifest entry (matched class)
 *
 * Builds the +0x24 sub-object from the object's u16 id.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B65C.c \
 *       --func func_0202B65C --addr 0x0202B65C --thumb --cc 1.1p1
 */
#include "../include/Obj00563.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern u8 *func_0202B894(u32 id);

void func_0202B65C(struct Obj *o)
{
    ((struct Obj00563 *)o)->f24 = (u32)func_0202B894(((struct Obj00563 *)o)->f0);
}

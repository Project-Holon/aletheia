/*
 * function: func_02200290
 * address:  0x02200290
 * packet:   pkt_02200290
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 *

 *
 * Tail call into CLACT_DeleteActor with the pointer held at +0xbf4.
 */
#include "../include/Obj18604.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void func_02200290(u8 *p)
{
    CLACT_DeleteActor((struct Obj *)(((struct Obj18604 *)p)->fBF4));
}

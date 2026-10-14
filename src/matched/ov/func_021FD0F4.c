/*
 * function: WORLDTRADE_LIST_DeleteActors
 * address:  0x021FD0F4
 * packet:   pkt_021FD0F4
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
 * Tail call into CLACT_DeleteActor with the pointer held at +0xd08.
 */
#include "../include/Obj18570.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void WORLDTRADE_LIST_DeleteActors(u8 *p)
{
    CLACT_DeleteActor((struct Obj *)(((struct Obj18570 *)p)->fD08));
}

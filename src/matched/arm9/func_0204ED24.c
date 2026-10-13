/*
 * function: func_0204ED24
 * address:  0x0204ED24
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   BILLBOARD_DeleteAllImages  0x0204F27C  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Free an actor and its two sub-objects, in +8, +4, self order.
 */
#include "../include/Obj11443.h"

typedef unsigned char u8;

struct Actor;
extern void BILLBOARD_DeleteAllImages(struct Actor *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_0204ED24(void *p)
{
    BILLBOARD_DeleteAllImages(p);
    func_020307B0(((struct Obj11443 *)p)->f8);
    func_020307B0(((struct Obj11443 *)p)->f4);
    func_020307B0(p);
}

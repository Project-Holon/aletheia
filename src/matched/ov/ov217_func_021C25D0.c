/*
 * function: ARROW_CreateActors
 * address: 0x021C25D0
 * packet: pkt_ov217_021C25D0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero padding bytes at 0x021C2612, not a follower.
 * ABI: 0204B294's legacy source says void; original caller stores returned
 *      r0 at 021C2608. Preserve that observable return and its seven inputs.
 * symbols:
 *   CLACT_CreateActor 0x0204B294 arm
 */
#include "../include/Obj03378.h"
#include "../include/Obj08444.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Arg { u16 a,b,c; u8 d,e; };
struct Obj;
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
void ARROW_CreateActors(u8 *p)
{
    struct Arg arg;
    u32 *q=(u32 *)(p+8);
    int i=0;
    arg.a=0;
    arg.b=0;
    arg.c=0;
    arg.d=0;
    arg.e=0;
    for (;i<26;i++) {
        *(u32 *)(p+i*24+0x3c)=(u32)CLACT_CreateActor((void *)((struct Obj03378 *)p)->f4,q[0],q[1],q[2],&arg,((struct Obj08444 *)q)->fC,((struct Obj03378 *)p)->f0);
    }
}

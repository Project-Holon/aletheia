/*
 * function: RESEARCH_COMMON_DeleteActor
 * address:  0x021C0C2C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 36)) to CLACT_DeleteActor.
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25988.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void RESEARCH_COMMON_DeleteActor(u8 *a0)
{
    CLACT_DeleteActor((struct Obj *)((u32)(((struct Obj25988 *)a0)->f24)));
}


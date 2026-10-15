/*
 * function: BILLBOARD_SetField20
 * address:  0x0204ED98
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Halfword field store into the actor at +0x20 from the caller's pointer.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204ED98 and its body ends at 0x0204EDA4.
 *
 * symbols:
 *   none (no external calls, no data references)
 */
#include "../include/Obj16112.h"

typedef unsigned char  u8;
typedef unsigned short u16;

void BILLBOARD_SetField20(u8 *dst, u16 *src)
{
    ((struct Obj16112 *)dst)->f20 = *src;
}

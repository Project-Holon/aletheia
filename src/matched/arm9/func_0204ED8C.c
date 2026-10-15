/*
 * function: BILLBOARD_SetAmbient
 * address:  0x0204ED8C
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Halfword field store into the actor at +0x1e from the caller's pointer.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204ED8C and its body ends at 0x0204ED98.
 *
 * symbols:
 *   none (no external calls, no data references)
 */
#include "../include/Obj16110.h"

typedef unsigned char  u8;
typedef unsigned short u16;

void BILLBOARD_SetAmbient(u8 *dst, u16 *src)
{
    ((struct Obj16110 *)dst)->f1E = *src;
}

/*
 * function: func_0204EDC4
 * address:  0x0204EDC4
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * Two halfword field stores, +0x36 and +0x38, from the two value
 * parameters.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it and the worklist's function list for this
 * packet does not carry it (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * It starts at 0x0204EDC4 and its body ends at 0x0204EDD0.
 *
 * symbols:
 *   none (no external calls, no data references)
 */
#include "../include/Obj11444.h"

typedef unsigned char  u8;
typedef unsigned short u16;

void func_0204EDC4(u8 *dst, u16 a, u16 b)
{
    ((struct Obj11444 *)dst)->f36 = a;
    ((struct Obj11444 *)dst)->f38 = b;
}

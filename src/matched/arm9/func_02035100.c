/*
 * function: UI_GetSuspendHook
 * address:  0x02035100
 * packet:   pkt_0203508C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * An unlabelled leaf.  disasm.py only traces a prologue that saves lr, so this
 * eight-byte getter was printed as `.word 0xE590001C / .word 0xE12FFF1E` in
 * the word run that follows UI_SetResumeAndSuspendHooks's literal pool
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  It is the
 * only callee UI_GetSuspendHookGlobal has, and that neighbour stays capped at MATCH for
 * as long as this address has no manifest entry
 * (docs/idioms/a-veneer-attests-nothing-while-its-target-is-an-unlabelled-leaf.md
 * is the same shape, where the stub in between makes a `matched` entry useless
 * - here the pool word names the leaf directly, so the entry is the unblock).
 */
#include "../include/Obj15886.h"

typedef unsigned int u32;

u32 UI_GetSuspendHook(u32 *p)
{
    return ((struct Obj15886 *)p)->f1C;
}

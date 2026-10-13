/*
 * function: CLACT_SetOamManagerMainParam
 * address:  0x0204C024
 * packet:   pkt_0204BE84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *   func_02063378  0x02063378  arm
 *
 * Tail call through the singleton pointer: the pool word for the global is
 * loaded, its value passed as the first argument, and the callee reached with
 * the compiler's usual `ldr ip, [pc, #4]` / `bx ip` plus a second pool word.
 */

#include "../include/G_Mgr.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

extern struct Mgr *g_ClactSystem;
extern void func_02063378(u32 a0, u32 a1);

void CLACT_SetOamManagerMainParam(u32 v)
{
    func_02063378((u32)((u8 *)g_ClactSystem), v);
}

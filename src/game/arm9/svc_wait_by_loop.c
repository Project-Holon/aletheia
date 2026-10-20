/*
 * file:     svc_wait_by_loop.c
 * function: SVC_WaitByLoop
 * address:  0x02004490
 * packet:   pkt_02004490
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     wave 16: the CCERR of 2026-09-20 no longer reproduces; EXACT* (the
 *           listing extent runs over the data that follows this 4-byte SVC
 *           stub).  A Thumb `asm` function: swi, then return.
 */

#include "../types.h"

/* hand-written in the original: SVC_WaitByLoop, SVC stub in the arm9 secure area (swi 3; bx lr) */
asm void SVC_WaitByLoop(s32 count)
{
    swi 3
    bx lr
}

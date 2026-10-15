/*
 * function: RESEARCH_LIST_SetState
 * address:  0x021BB978
 * packet:   pkt_ov217_021BB978
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocker: byte-correct but capped at MATCH.  The tail-call site to
 * RESEARCH_LIST_ClearSubState (0x021BB998) has no witness outside this range: no func_
 * label at the address anywhere, and no branch to it from elsewhere.
 *
 * This address is also matched as RESEARCH_LIST_SetState in ov021; the ov217 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   RESEARCH_LIST_ClearSubState  0x021BB998  thumb  ov217
 *
 * Addresses are Black-image addresses.
 
 *
 * UNBLOCKED: RESEARCH_LIST_ClearSubState is now an EXACT entry in layout/matched/ov217;
 * the call site resolves as matched, verdict promoted to EXACT.
*/
#include "../include/Obj14731.h"

extern void *RESEARCH_LIST_ClearSubState(void *p);

int RESEARCH_LIST_SetState(char *p, int a1)
{
    int off = 0x56;
    ((struct Obj14731 *)p)->f1C = a1;
    ((struct Obj14731 *)p)->f24 = 0;
    *(int *)(p + (off << 2)) = 0;
    return (int)RESEARCH_LIST_ClearSubState(p);
}

/*
 * function: func_021BB978
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
 * func_021BB998 (0x021BB998) has no witness outside this range: no func_
 * label at the address anywhere, and no branch to it from elsewhere.
 *
 * This address is also matched as func_021BB978 in ov021; the ov217 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   func_021BB998  0x021BB998  thumb  ov217
 *
 * Addresses are Black-image addresses.
 
 *
 * UNBLOCKED: func_021BB998 is now an EXACT entry in layout/matched/ov217;
 * the call site resolves as matched, verdict promoted to EXACT.
*/
#include "../include/Obj14731.h"

extern void *func_021BB998(void *p);

int func_021BB978(char *p, int a1)
{
    int off = 0x56;
    ((struct Obj14731 *)p)->f1C = a1;
    ((struct Obj14731 *)p)->f24 = 0;
    *(int *)(p + (off << 2)) = 0;
    return (int)func_021BB998(p);
}

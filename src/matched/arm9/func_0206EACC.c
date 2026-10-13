/*
 * function: NNSi_G3dTexPatAnmGetTrackByIdx
 * address:  0x0206EACC
 * packet:   pkt_0206E964
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The null test is on the *computed* pointer, not on `p`: the original opens
 * with `adds r3, r0, #12` and branches on its zero flag.  The field reads for
 * the bound and the offset stay p-relative (+13, +18) while the indexed
 * halfword goes through the computed base - that mix of spellings is what
 * reproduces the register use, not a local `q` for all three.
 *
 * The two guards must be `goto`s, not `return 0`s: as returns, mwccarm
 * predicates the body (see docs/idioms/a-factored-tail-lets-the-compiler-predicate-the-arms.md);
 * as gotos the original's `beq`/`bcs` branches survive.
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_G3dTexPatAnmGetTrackByIdx.c \
 *       --func NNSi_G3dTexPatAnmGetTrackByIdx --addr 0x0206EACC --cc 1.1p1 --arm
 */
#include "../include/Obj11641.h"

typedef unsigned short u16;
typedef unsigned int   u32;

unsigned char *NNSi_G3dTexPatAnmGetTrackByIdx(void *p, u32 idx)
{
    unsigned char *q = (unsigned char *)p + 12;
    u16 off;
    u16 n;

    if (q == 0)
        goto fail;
    if (idx >= *((unsigned char *)p + 13))
        goto fail;
    off = ((struct Obj11641 *)p)->f12;
    n = *(u16 *)(q + off);
    return q + off + 4 + n * idx;
fail:
    return 0;
}

/*
 * function: CLACT_IsOamPending
 * address:  0x0204BB38
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactSystem   0x02146A74  data
 *
 * The reader for the word CLACT_SetOamPending writes, returning 0 before the system
 * is constructed.  Both arms are predicated off the null test (`ldrne` and
 * `moveq` into the same register), which is why this has to be written as one
 * `if`/`else` over two returns rather than an early return followed by the
 * load.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_IsOamPending.c \
 *       --func CLACT_IsOamPending --addr 0x0204BB38 --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Mgr *g_ClactSystem;

u32 CLACT_IsOamPending(void)
{
    if (g_ClactSystem != 0) {
        return g_ClactSystem->unk_0fc;
    } else {
        return 0;
    }
}

/*
 * function: CLACT_SetOamPending
 * address:  0x0204BB20
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
 * Store a word at +0xfc of the cell-actor singleton, silently doing nothing
 * before the system is constructed.  A leaf: the guarded store predicates to
 * `strne` and no lr is saved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_SetOamPending.c \
 *       --func CLACT_SetOamPending --addr 0x0204BB20 --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Mgr *g_ClactSystem;

void CLACT_SetOamPending(u32 v)
{
    if (g_ClactSystem != 0) {
        g_ClactSystem->unk_0fc = v;
    }
}

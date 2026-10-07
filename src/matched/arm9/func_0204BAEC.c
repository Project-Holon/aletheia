/*
 * function: func_0204BAEC
 * address:  0x0204BAEC
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A74   0x02146A74  data
 *
 * Store a word at +0xf8 of the cell-actor singleton, silently doing nothing
 * before the system is constructed.  A leaf: the guarded store predicates to
 * `strne` and no lr is saved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BAEC.c \
 *       --func func_0204BAEC --addr 0x0204BAEC --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Mgr *g_02146A74;

void func_0204BAEC(u32 v)
{
    if (g_02146A74 != 0) {
        g_02146A74->unk_0f8 = v;
    }
}

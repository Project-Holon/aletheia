/*
 * function: CLACT_SetOamManagerSubParam
 * address:  0x0204C040
 * packet:   pkt_0204BE84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Same forward as CLACT_SetOamManagerMainParam but aimed at the sub-block at +0x20.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  The
 * function starts at the computed address and its body ends at 0x0204C060.
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *   NNS_G2dEntryOamManagerAffine  0x02063378  arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Mgr *g_ClactSystem;
extern void NNS_G2dEntryOamManagerAffine(void *block, u32 arg);

void CLACT_SetOamManagerSubParam(u32 arg)
{
    NNS_G2dEntryOamManagerAffine((u8 *)g_ClactSystem + 0x20, arg);
}

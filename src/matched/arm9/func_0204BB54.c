/*
 * function: CLACT_ResetOamIfPending
 * address:  0x0204BB54
 * packet:   pkt_0204B954
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *   CLACT_IsOamPending  0x0204BB38  arm
 *   CLACT_ResetOamManagers  0x0204BD18  arm
 *   CLACT_SetOamPending  0x0204BB20  arm
 *
 * Drop the singleton's +0xfc latch: if it is set, release the two OAM
 * sub-records hanging off the singleton itself and clear the latch.
 *
 * Two early returns, each predicated into its own `popeq`, so they are two
 * separate `if`s rather than one `&&`
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * is the opposite shape: one shared exit block).  The address of the global
 * is held in r4 across both calls, but the pointer itself is re-read for the
 * third call because CLACT_IsOamPending may have stored to it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_ResetOamIfPending.c \
 *       --func CLACT_ResetOamIfPending --addr 0x0204BB54 --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Mgr *g_ClactSystem;

extern u32  CLACT_IsOamPending(void);
struct Obj;
extern void CLACT_ResetOamManagers(struct Obj *o);
extern void CLACT_SetOamPending(u32 v);

void CLACT_ResetOamIfPending(void)
{
    if (g_ClactSystem == 0) {
        return;
    }
    if (CLACT_IsOamPending() == 0) {
        return;
    }

    CLACT_ResetOamManagers((struct Obj *)g_ClactSystem);
    CLACT_SetOamPending(0);
}

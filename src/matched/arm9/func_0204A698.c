/*
 * function: CLACT_FlushOamIfPending
 * address:  0x0204A698
 * packet:   pkt_0204A600
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *   CLACT_SetSystemActive  0x0204BAEC  arm
 *   CLACT_ResetOamIfPending  0x0204BB54  arm
 *
 * Cell-actor latch-only tick: latch off, flush the actor bank list, latch
 * back on.  No render update compared with func_0204A600.
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Mgr *g_ClactSystem;

extern void CLACT_SetSystemActive(u32 v);
extern void CLACT_ResetOamIfPending(void);

void CLACT_FlushOamIfPending(void)
{
    if (((u8 *)g_ClactSystem) == 0) {
        return;
    }
    CLACT_SetSystemActive(0);
    CLACT_ResetOamIfPending();
    CLACT_SetSystemActive(1);
}

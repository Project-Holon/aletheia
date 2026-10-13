/*
 * function: CLACT_VBlankSystem
 * address:  0x0204A648
 * packet:   pkt_0204A600
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_ClactSystem    0x02146A74  data
 *   CLACT_IsSystemActive 0x0204BB04  arm
 *   CLACT_SetOamPending 0x0204BB20  arm
 *   CLACT_ApplyOamManagers 0x0204BCF4  arm
 *   CLACT_ExecuteTransfers 0x0204C7A4  arm
 *
 * The cell-actor manager's teardown pass, and the exact inverse of
 * src/pending/CLACT_DrawSystem.c: each guard re-reads the context pointer from
 * its slot (the two `popeq` exits are the short-circuit returns, which is why
 * neither guard is predicated), the +0xEC latch decides whether the +0xE0
 * sub-object is released, and the flag goes back to 1.
 *
 * The 0x0204BCF4 call site resolves off the `label` class (its own
 * src/pending/CLACT_ApplyOamManagers.c is capped, but the branch has witnesses outside
 * this range), so this file is EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/CLACT_VBlankSystem.c \
 *       --func CLACT_VBlankSystem --addr 0x0204A648 --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Mgr *g_ClactSystem;

extern u32  CLACT_IsSystemActive(void);
extern void CLACT_SetOamPending(u32 v);
struct Obj;
struct Table;
extern void CLACT_ApplyOamManagers(struct Obj *o);
extern void CLACT_ExecuteTransfers(struct Table *t);

void CLACT_VBlankSystem(void)
{
    if (g_ClactSystem == 0)
        return;
    if (CLACT_IsSystemActive() == 0)
        return;

    CLACT_ApplyOamManagers((struct Obj *)g_ClactSystem);

    if (g_ClactSystem->field_EC != 0)
        CLACT_ExecuteTransfers((struct Table *)((char *)g_ClactSystem + 0xe0));

    CLACT_SetOamPending(1);
}

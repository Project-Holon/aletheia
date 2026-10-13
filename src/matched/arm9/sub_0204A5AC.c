/*
 * unit:     no
 * function: CLACT_ExitSystem
 * address:  0x0204A5AC
 * packet:   pkt_0204A03C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Was blocked at MATCH pending CLACT_ExitResources (+0x003C), which was itself
 * capped at MATCH behind VMAN_Delete.  Both are now `matched`
 * (src/matched/CLACT_ExitResources.c, src/matched/VMAN_Delete.c), closing the
 * cell-actor system destructor.
 *
 * symbols:
 *   g_ClactSystem     0x02146A74  data
 *   CLACT_SetSystemActive  0x0204BAEC  arm
 *   CLACT_ExitOamManagers  0x0204BCD8  arm
 *   CLACT_ExitRenderer  0x0204BE28  arm
 *   CLACT_ExitTransferPool  0x0204C6E4  arm
 *   CLACT_ExitResources  0x0204D8AC  arm
 *   sub_020307B0   0x020307B0  arm
 *
 * Tear down the single global cell-actor system behind 0x02146A74.  The block
 * is one allocation with four embedded sub-objects at +0x00, +0x40, +0x0e0 and
 * +0x104, each released by its own finaliser, after which the block is freed
 * and the global cleared.  src/matched/CLACT_SetUnitDefaultRenderer.c points a bank at
 * +0x40 of the same block, so that sub-object is the shared default.
 *
 * The global is re-read from the pool word before every call because each
 * callee could store to it; that is not a `volatile` (see
 * docs/idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md,
 * which is about the opposite case), it is just an extern the compiler cannot
 * see through.
 *
 * The zero passed to CLACT_SetSystemActive and the null stored back at the end are the
 * same register: the constant is materialised once into r5 and the argument
 * copied off it
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/CLACT_ExitSystem.c \
 *       --func CLACT_ExitSystem --addr 0x0204A5AC --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Mgr *g_ClactSystem;

extern void CLACT_SetSystemActive(u32 which);
struct Obj;
struct Pool;
struct Res;
extern void CLACT_ExitOamManagers(struct Obj *o);
extern void CLACT_ExitRenderer(int *p);
extern void CLACT_ExitTransferPool(struct Pool *p);
extern void CLACT_ExitResources(struct Res *res);
extern u32 sub_020307B0(void *p);

void CLACT_ExitSystem(void)
{
    CLACT_SetSystemActive(0);
    CLACT_ExitOamManagers((struct Obj *)((u8 *)g_ClactSystem));
    CLACT_ExitRenderer((int *)(((u8 *)g_ClactSystem) + 0x40));
    CLACT_ExitTransferPool((struct Pool *)(((u8 *)g_ClactSystem) + 0xe0));
    CLACT_ExitResources((struct Res *)(((u8 *)g_ClactSystem) + 0x104));
    sub_020307B0(((u8 *)g_ClactSystem));
    g_ClactSystem = 0;
}

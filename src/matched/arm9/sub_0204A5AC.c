/*
 * unit:     no
 * function: sub_0204A5AC
 * address:  0x0204A5AC
 * packet:   pkt_0204A03C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Was blocked at MATCH pending func_0204D8AC (+0x003C), which was itself
 * capped at MATCH behind func_020345DC.  Both are now `matched`
 * (src/matched/func_0204D8AC.c, src/matched/func_020345DC.c), closing the
 * cell-actor system destructor.
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   func_0204BAEC  0x0204BAEC  arm
 *   func_0204BCD8  0x0204BCD8  arm
 *   func_0204BE28  0x0204BE28  arm
 *   func_0204C6E4  0x0204C6E4  arm
 *   func_0204D8AC  0x0204D8AC  arm
 *   sub_020307B0   0x020307B0  arm
 *
 * Tear down the single global cell-actor system behind 0x02146A74.  The block
 * is one allocation with four embedded sub-objects at +0x00, +0x40, +0x0e0 and
 * +0x104, each released by its own finaliser, after which the block is freed
 * and the global cleared.  src/matched/sub_0204B270.c points a bank at
 * +0x40 of the same block, so that sub-object is the shared default.
 *
 * The global is re-read from the pool word before every call because each
 * callee could store to it; that is not a `volatile` (see
 * docs/idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md,
 * which is about the opposite case), it is just an extern the compiler cannot
 * see through.
 *
 * The zero passed to func_0204BAEC and the null stored back at the end are the
 * same register: the constant is materialised once into r5 and the argument
 * copied off it
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204A5AC.c \
 *       --func sub_0204A5AC --addr 0x0204A5AC --cc 1.1p1 --arm
 */

#include "../include/G_Mgr.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern struct Mgr *g_02146A74;

extern void func_0204BAEC(u32 which);
struct Obj;
struct Pool;
struct Res;
extern void func_0204BCD8(struct Obj *o);
extern void func_0204BE28(int *p);
extern void func_0204C6E4(struct Pool *p);
extern void func_0204D8AC(struct Res *res);
extern u32 sub_020307B0(void *p);

void sub_0204A5AC(void)
{
    func_0204BAEC(0);
    func_0204BCD8((struct Obj *)((u8 *)g_02146A74));
    func_0204BE28((int *)(((u8 *)g_02146A74) + 0x40));
    func_0204C6E4((struct Pool *)(((u8 *)g_02146A74) + 0xe0));
    func_0204D8AC((struct Res *)(((u8 *)g_02146A74) + 0x104));
    sub_020307B0(((u8 *)g_02146A74));
    g_02146A74 = 0;
}

/*
 * function: func_020312CC
 * address:  0x020312CC
 * packet:   pkt_020312CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146990     0x02146990  data
 *   func_020314F4  0x020314F4  arm
 *
 * Forwarder: passes the object held in g_02146990 to func_020314F4 with
 * the caller's three arguments.  Formerly mislabelled SDK EL_LinkFileEx.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/arm9/func_020312CC.c \
 *       --func func_020312CC --addr 0x020312CC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *g_02146990;
struct Obj020314F4;
extern void func_020314F4(struct Obj020314F4 *obj, u32 a1, u32 a2, u32 a3);

void func_020312CC(u32 a1, u32 a2, u32 a3)
{
    func_020314F4(g_02146990, a1, a2, a3);
}

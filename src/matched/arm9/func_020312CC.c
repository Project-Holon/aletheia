/*
 * function: PROCSYS_PushGlobal
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
 *   PROCSYS_PushInternal  0x020314F4  arm
 *
 * Forwarder: passes the object held in g_02146990 to PROCSYS_PushInternal with
 * the caller's three arguments.  Formerly mislabelled SDK EL_LinkFileEx.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/arm9/PROCSYS_PushGlobal.c \
 *       --func PROCSYS_PushGlobal --addr 0x020312CC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *g_02146990;
struct Obj020314F4;
extern void PROCSYS_PushInternal(struct Obj020314F4 *obj, u32 a1, u32 a2, u32 a3);

void PROCSYS_PushGlobal(u32 a1, u32 a2, u32 a3)
{
    PROCSYS_PushInternal(g_02146990, a1, a2, a3);
}

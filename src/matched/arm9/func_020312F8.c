/*
 * function: PROCSYS_ReplaceGlobal
 * address:  0x020312F8
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
 *   PROCSYS_QueueReplace   0x020314DC  arm
 *
 * Forwarder: passes the object held in g_02146990 to PROCSYS_QueueReplace with
 * the caller's three arguments.  Formerly mislabelled SDK EL_LinkFileEx.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/arm9/PROCSYS_ReplaceGlobal.c \
 *       --func PROCSYS_ReplaceGlobal --addr 0x020312F8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *g_02146990;
struct S020314DC;
extern void PROCSYS_QueueReplace(struct S020314DC *p, u32 a, u32 b, u32 c);

void PROCSYS_ReplaceGlobal(u32 a1, u32 a2, u32 a3)
{
    PROCSYS_QueueReplace(g_02146990, a1, a2, a3);
}

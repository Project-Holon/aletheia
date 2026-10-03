/*
 * function: func_020312F8
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
 *   sub_020314DC   0x020314DC  arm
 *
 * Forwarder: passes the object held in g_02146990 to sub_020314DC with
 * the caller's three arguments.  Formerly mislabelled SDK EL_LinkFileEx.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/arm9/func_020312F8.c \
 *       --func func_020312F8 --addr 0x020312F8 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *g_02146990;
struct S020314DC;
extern void sub_020314DC(struct S020314DC *p, u32 a, u32 b, u32 c);

void func_020312F8(u32 a1, u32 a2, u32 a3)
{
    sub_020314DC(g_02146990, a1, a2, a3);
}

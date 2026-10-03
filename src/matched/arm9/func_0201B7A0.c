/*
 * function: func_0201B7A0
 * address:  0x0201B7A0
 * packet:   pkt_0201B7A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0209E45C (literal) - its only pool word is this function's own,
 *           at 0x0201B7B0, inside the compared range; every concrete byte is
 *           right.
 *
 * symbols:
 *   g_0209E45C     0x0209E45C  data
 *   func_0201B850  0x0201B850  thumb
 *
 * A three-byte-stride table entry is handed to func_0201B850 along with the
 * caller's own third and fourth arguments.  Those two are forwarded
 * unchanged - they are already in r2/r3 - so no instruction moves them, and
 * that is also why the call is a real `bl` rather than a tail call: a Thumb
 * tail call spends r3 on the target address, so a four-argument call cannot
 * be one.  The 3 is lsls #1 plus adds; the table pointer is this function's
 * own pool word at 0x0201B7B0.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201B7A0.c \
 *       --func func_0201B7A0 --addr 0x0201B7A0 --cc 1.1p1 --thumb
 */

typedef signed char s8;

extern const s8 g_0209E45C[];
typedef unsigned int   u32;
extern void func_0201B850(void *mon, const s8 *tbl, int a2, u32 a3);

void func_0201B7A0(void *a0, int a1, int a2, int a3)
{
    func_0201B850(a0, &g_0209E45C[a1 * 3], a2, a3);
}

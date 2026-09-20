/*
 * function: func_0201B818
 * address:  0x0201B818
 * packet:   pkt_0201B7A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  0209E462 (literal) - its only pool word is this function's own,
 *           at 0x0201B84C, inside the compared range; every concrete byte is
 *           right.
 *
 * symbols:
 *   g_0209E462     0x0209E462  data
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201B850  0x0201B850  thumb
 *
 * for (i = 0; i < count(a0); i++) func_0201B850(entry(a0, i), &g_0209E462,
 * a1, a2); - the entry pointer the loop computes is what feeds the second
 * call's first argument, which is why no `r0 = a0` copy appears in front of
 * it (the returned r0 is already the argument), and the bound is
 * re-evaluated at the bottom of the loop so it stays a call in the
 * condition.  The table pointer is this function's own pool word at
 * 0x0201B84C, behind the C0 46 alignment filler at 0x0201B84A.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0201B818.c \
 *       --func func_0201B818 --addr 0x0201B818 --cc 1.1p1 --thumb
 */

typedef signed char s8;
typedef unsigned int u32;

extern const s8 g_0209E462[];
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern void func_0201B850(void *a0, const s8 *tbl, int a2, int a3);

void func_0201B818(void *a0, int a1, int a2)
{
    int i;

    for (i = 0; i < (int)func_0201AA18(a0); i++) {
        func_0201B850(func_0201AB28(a0, i), g_0209E462, a1, a2);
    }
}

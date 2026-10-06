/*
 * function: func_02091524
 * address:  0x02091524
 * packet:   pkt_0209149C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Walks the three 0x4C-byte records of g_020A8730 and asks func_02091B5C
 * about every record whose +4 bitfield 3..5 is set, returning -1 as soon as
 * one of them fails and 0 otherwise.
 *
 * The two `!= 0` conditions are what put the g_020A8730 address in a
 * callee-saved register: the source names the global in the loop's own
 * advance expression (`p = (i < 3) ? g_020A8730 + i++ * 0x4c : 0`) rather
 * than binding it to a pointer local, so the loaded address is CSE'd into one
 * value that stays live across the func_02091B5C call and lands in r8, while
 * the cursor itself dies as that call's argument and lives in r0.  A `u8
 * *base` local instead sends the address to r5 and the induction variable to
 * r6, and the loop tail then renumbers (16 bytes of diff, and 0209149C's
 * sibling goes the same way).
 *
 * `i++ * 0x4c` rather than `i * 0x4c` is pinned by the increment sitting in
 * the true arm only: the whole ternary is if-converted, so the increment is
 * `addlt r5, r5, #1` and the false arm's 0 is rematerialised in its own
 * register (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091524.c \
 *       --func func_02091524 --addr 0x02091524 --cc 1.1p1 --arm
 *   EXACT, 100 bytes, 2 relocation sites, both resolved.
 *
 * symbols:
 *   g_020A8730     0x020A8730  data
 *   func_02091B5C  0x02091B5C  arm
 */
#include "../include/Obj00481.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 g_020A8730[];
struct P02091B5C;
extern int func_02091B5C(struct P02091B5C *p);

int func_02091524(void)
{
    u8 *p = g_020A8730;
    int i = 1;
    int r = 0;

    do {
        if (((((struct Obj00481 *)p)->f4 << 22) >> 29) != 0) {
            if (func_02091B5C((struct P02091B5C *)p) != 0)
                r = -1;
        }
        p = (i < 3) ? g_020A8730 + i++ * 0x4c : 0;
    } while (p != 0);
    return r;
}

/*
 * function: MSL_C_LIB_FlushAll
 * address:  0x02091524
 * packet:   pkt_0209149C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Walks the three 0x4C-byte records of gMslStream0 and asks MSL_C_LIB_FlushStream
 * about every record whose +4 bitfield 3..5 is set, returning -1 as soon as
 * one of them fails and 0 otherwise.
 *
 * The two `!= 0` conditions are what put the gMslStream0 address in a
 * callee-saved register: the source names the global in the loop's own
 * advance expression (`p = (i < 3) ? gMslStream0 + i++ * 0x4c : 0`) rather
 * than binding it to a pointer local, so the loaded address is CSE'd into one
 * value that stays live across the MSL_C_LIB_FlushStream call and lands in r8, while
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
 *   python tools/match.py one --src src/matched/MSL_C_LIB_FlushAll.c \
 *       --func MSL_C_LIB_FlushAll --addr 0x02091524 --cc 1.1p1 --arm
 *   EXACT, 100 bytes, 2 relocation sites, both resolved.
 *
 * symbols:
 *   gMslStream0     0x020A8730  data
 *   MSL_C_LIB_FlushStream  0x02091B5C  arm
 */
#include "../include/Obj00481.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 gMslStream0[];
struct P02091B5C;
extern int MSL_C_LIB_FlushStream(struct P02091B5C *p);

int MSL_C_LIB_FlushAll(void)
{
    u8 *p = gMslStream0;
    int i = 1;
    int r = 0;

    do {
        if (((((struct Obj00481 *)p)->f4 << 22) >> 29) != 0) {
            if (MSL_C_LIB_FlushStream((struct P02091B5C *)p) != 0)
                r = -1;
        }
        p = (i < 3) ? gMslStream0 + i++ * 0x4c : 0;
    } while (p != 0);
    return r;
}

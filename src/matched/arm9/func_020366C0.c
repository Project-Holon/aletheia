/*
 * function: func_020366C0
 * address:  0x020366C0
 * packet:   pkt_020366C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Counts the 20-byte records of the array at p+0x18 whose halfword at +0x0E is
 * non-zero, up to the count in p+0x1C.  60 bytes, no calls, no pool: the loop
 * is rotated and the test is a predicated `addne`.
 *
 * The declaration order is the whole lever.  Declared `e, i, c, n` the four
 * locals land in r1, r2, r3 and ip exactly as the image has them: the cursor
 * first, then the index, then the counter (whose `mov r3, #0` then feeds
 * `mov r2, r3` for the index), and the bound last in ip, so the bound's load
 * is the one that survives to just before the `ble`.  With the bound declared
 * first - how this file previously stood - the bound takes r2, the cursor r3
 * and the counter ends up in r0, which frees the `mov r0, r3` before the
 * return and shortens the body to 56 bytes (DIFF).  A param pointer (`u32 *p`
 * plus `q = (u8 *)p[6]`) does not reach it either: the four locals colour the
 * same way whatever the order.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020366C0.c \
 *       --func func_020366C0 --addr 0x020366C0 --cc 1.1p1 --arm
 */
#include "../include/Obj11347.h"
#include "../include/Obj15903.h"

typedef unsigned short u16;

int func_020366C0(char *p)
{
    const char *e = *(char * *)&((struct Obj11347 *)p)->f18;
    int         i;
    int         c = 0;
    int         n = ((struct Obj11347 *)p)->f1C;

    for (i = 0; i < n; i++, e += 0x14) {
        if (((struct Obj15903 *)e)->fE != 0)
            c++;
    }
    return c;
}

/*
 * function: func_020519E4
 * address:  0x020519E4
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The class-3 slot carries only a halfword at +2.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020519E4.c \
 *       --func func_020519E4 --addr 0x020519E4 --cc 1.1p1 --arm
 */
#include "../include/Obj16190.h"

typedef unsigned short u16;

extern void *func_020518AC(void *obj, int kind);

void func_020519E4(void *p, u16 *q)
{
    char *r = func_020518AC(p, 3);

    if (r != 0)
        ((struct Obj16190 *)r)->f2 = *q;
}

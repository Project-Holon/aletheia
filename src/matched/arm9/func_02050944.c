/*
 * function: func_02050944
 * address:  0x02050944
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02050944.c \
 *       --func func_02050944 --addr 0x02050944 --cc 1.1p1 --arm
 */
#include "../include/Obj16163.h"

typedef unsigned short u16;

struct S14 {
    u16 f : 14;
};

extern int func_02050984(int a);

int func_02050944(void *p, struct S14 *q)
{
    int (*fn)(void *, struct S14 *);

    fn = (int (*)(void *, struct S14 *))func_02050984(q->f);
    ((struct Obj16163 *)p)->f1C = q->f;
    return fn(p, q);
}

/*
 * function: func_0205207C
 * address:  0x0205207C
 * packet:   pkt_02051C6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0205207C.c \
 *       --func func_0205207C --addr 0x0205207C --cc 1.1p1 --arm
 */
#include "../include/Obj16198.h"

typedef unsigned int u32;

struct S12 {
    u32 a;
    u32 b;
    u32 c;
};

void func_0205207C(char *p, struct S12 *q, struct S12 *r, u32 v)
{
    *(struct S12 *)p = *q;
    *(struct S12 *)(p + 12) = *r;
    ((struct Obj16198 *)p)->f18 = v;
}

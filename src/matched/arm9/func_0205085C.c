/*
 * function: func_0205085C
 * address:  0x0205085C
 * packet:   pkt_02050340
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0205085C.c \
 *       --func func_0205085C --addr 0x0205085C --cc 1.1p1 --arm
 */
#include "../include/Obj02611.h"
#include "../include/Obj16158.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_020500A0(void *p);

void func_0205085C(void *p, int idx, u16 v)
{
    char *e = (char *)(((struct Obj16158 *)p)->f18 + idx * 40);

    func_020500A0(e);
    ((struct Obj02611 *)e)->f10 = v;
}

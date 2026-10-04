/*
 * unit:     no
 * function: func_02009FD4
 * address:  0x02009FD4
 * packet:   pkt_02009F1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj15578.h"

struct Obj;
extern unsigned int func_0200A400(struct Obj *p);
extern void *func_0200A43C(struct Obj *p, unsigned int i);
typedef unsigned int   u32;
extern u32 func_02009F0C(u32 a);
void *func_02009FD4(char *p, unsigned int idx)
{
    unsigned char *e = (unsigned char *)func_0200A43C((struct Obj *)p, idx);
    unsigned int n = func_0200A400((struct Obj *)p);
    if (idx < n && func_02009F0C(((struct Obj15578 *)e)->fB3) != 0)
        return e;
    return 0;
}


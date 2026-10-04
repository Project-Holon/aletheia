/*
 * unit:     no
 * function: func_0200A104
 * address:  0x0200A104
 * packet:   pkt_0200A104
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj15581.h"

struct Obj;
extern unsigned int func_0200A400(struct Obj *obj);
extern void func_0200A49C(struct Obj *obj);
extern void func_0200A480(struct Obj *obj);
extern void *func_0200A43C(struct Obj *obj, unsigned int index);
int func_0200A104(char *p, unsigned int idx)
{
    int r = 0;
    unsigned int n = func_0200A400((struct Obj *)p);
    func_0200A49C((struct Obj *)p);
    if (idx < n) {
        unsigned char *e = (unsigned char *)func_0200A43C((struct Obj *)p, idx);
        if (((unsigned int)(((struct Obj15581 *)e)->fB4) << 0x1e) >> 0x1f)
            r = 1;
    }
    func_0200A480((struct Obj *)p);
    return r;
}

/*
 * function: func_021F254C
 * address: 0x021F254C
 * packet: pkt_ov032_021F254C
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_021F2588 0x021F2588 thumb ov032
 */
#include "../include/Obj07639.h"
typedef struct { void *f00; void *f04; unsigned f08; void *f0c; void *f10; } Desc;
typedef struct { int state; void *f04; unsigned f08; void *owner; unsigned f10; unsigned f14; unsigned f18; } Work;
extern Desc *func_020122C0(void *, void *, int (*)(int, int, int *), unsigned);
extern Work *func_020124E8(Desc *);
extern int func_021F2588(int, int, int *);
Desc *func_021F254C(char *p, unsigned a, unsigned b, unsigned c)
{
    Desc *d;
    Work *w;
    d = func_020122C0(((struct Obj07639 *)p)->f0, 0, func_021F2588, 0x1c);
    w = func_020124E8(d);
    w->owner = p;
    w->f04 = ((struct Obj07639 *)p)->f0;
    w->f08 = ((struct Obj07639 *)p)->f8;
    w->f10 = a;
    w->f14 = b;
    w->f18 = c;
    ((struct Obj07639 *)p)->f72 = 1;
    return d;
}

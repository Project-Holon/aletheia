/*
 * function: BEACON_VIEW_CreateTaskProc
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
 *   BEACON_VIEW_TaskProc 0x021F2588 thumb ov032
 */
#include "../include/Obj07639.h"
typedef struct { void *f00; void *f04; unsigned f08; void *f0c; void *f10; } Desc;
typedef struct { int state; void *f04; unsigned f08; void *owner; unsigned f10; unsigned f14; unsigned f18; } Work;
typedef unsigned int   u32;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern int BEACON_VIEW_TaskProc(int, int, int *);
Desc *BEACON_VIEW_CreateTaskProc(char *p, unsigned a, unsigned b, unsigned c)
{
    Desc *d;
    Work *w;
    d = (Desc *)func_020122C0(((struct Obj07639 *)p)->f0, 0, BEACON_VIEW_TaskProc, 0x1c);
    w = func_020124E8((struct Obj *)d);
    w->owner = p;
    w->f04 = ((struct Obj07639 *)p)->f0;
    w->f08 = ((struct Obj07639 *)p)->f8;
    w->f10 = a;
    w->f14 = b;
    w->f18 = c;
    ((struct Obj07639 *)p)->f72 = 1;
    return d;
}

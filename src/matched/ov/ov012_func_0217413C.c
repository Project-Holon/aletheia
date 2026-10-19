/*
 * function: UNION_SCENE_CreateSubEvent
 * address: 0x0217413C
 * packet: pkt_ov012_0217413C
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   UNION_SCENE_SubEventMain 0x0217416C thumb ov012
 */
#include "../include/Obj19269.h"
typedef unsigned char u8;
typedef struct { int f0; int f4; u8 *f8; } Work;
typedef unsigned int   u32;
struct Desc;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern int UNION_SCENE_SubEventMain(int, int *, int *);
int UNION_SCENE_CreateSubEvent(int a, int b, u8 *p)
{
    int task;
    Work *w;
    task = (int)func_020122C0((void *)a, 0, (void *)((int)UNION_SCENE_SubEventMain), 12);
    w = func_020124E8((struct Obj *)task);
    w->f0 = a;
    w->f4 = b;
    w->f8 = p;
    ((struct Obj19269 *)p)->f3548 = 1;
    return task;
}

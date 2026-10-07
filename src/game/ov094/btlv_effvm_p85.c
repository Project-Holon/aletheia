/*
 * file:     btlv_effvm_p85.c
 * unit:     yes
 * function: func_02201FD8, func_02201FF4, func_0220203C, func_02202058
 * address:  0x02201FD8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_0204B570  0x0204B570  arm
 *   func_0204B5AC  0x0204B5AC  arm
 *   func_022020A0  0x022020A0  thumb  ov094
 */
#include "../../matched/include/Obj21735.h"
#include "../../matched/include/Obj21736.h"

struct S02030EE8;
struct Actor;
struct Obj;
struct Pair;
typedef unsigned int u32;

typedef struct {
    int a, b;
    void *h;
    int d;
} Ent;

typedef struct {
    Ent *tbl;   /* 0x00 */
    int x, y;   /* 0x04 */
    int pad;    /* 0x0c */
    int idx;    /* 0x10 */
    int mover[1]; /* 0x14 */
} Obj;

typedef unsigned short u16;

extern u32 func_02030EE8(struct S02030EE8 *p);
extern int func_021F9260(void *m, int *out);
extern void func_021F89BC(void *p);
extern void func_0204B570(struct Actor *actor, u32 value);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
extern struct Obj *func_022020A0(int a, int b, int c, int d, int e, int f, int g, int h, u16 heap);
void func_02201FD8(void *h);
void func_02201FF4(void *a, Obj *o);
void func_0220203C(void *h);
struct Obj *func_02202058(int a, int b, int c, int d, int e, u16 k);


void func_02201FD8(void *h)
{
    int *q = (int *)func_02030EE8(h);
    char *p = (char *)q[0];
    ((struct Obj21735 *)p)->f78 &= (1 << q[4]) ^ -1;
}


void func_02201FF4(void *a, Obj *o)
{
    Ent *t = o->tbl;
    int r = func_021F9260(o->mover, &o->x);
    int v[2];

    v[0] = o->x;
    v[1] = o->y;
    func_0204B570(t[o->idx].h, 1);
    func_0204B5AC(t[o->idx].h, (struct Pair *)v);
    if (r == 1)
        func_021F89BC(a);
}


void func_0220203C(void *h)
{
    int *q = (int *)func_02030EE8(h);
    char *p = (char *)q[0];
    ((struct Obj21736 *)p)->f7C &= (1 << q[4]) ^ -1;
}


struct Obj *func_02202058(int a, int b, int c, int d, int e, u16 k)
{
    return func_022020A0(a, b, 0, c, d, e, 0, 0, k);
}

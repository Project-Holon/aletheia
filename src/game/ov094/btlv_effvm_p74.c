/*
 * file:     btlv_effvm_p74.c
 * unit:     yes
 * function: func_02200D30, func_02200D68
 * address:  0x02200D30
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
 *   func_02030EE8  0x02030EE8  arm
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_022019F4  0x022019F4  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_02015FBC  0x02015FBC  thumb
 */
#include "../../matched/include/Obj06316.h"

struct S02030EE8;
typedef unsigned char u8;

typedef int fx32;

typedef struct {
    fx32 x, y, z;
} VecFx32;

typedef struct {
    void *h;                /* 0x00 */
    char pad04[0x58];
} Entry;

typedef struct {
    int pad00;              /* 0x000 */
    void *obj;              /* 0x004 */
    Entry e[14];            /* 0x008 */
    char pad[0x528 - 0x008 - 14 * 0x5c];
    unsigned int mask;      /* 0x528 */
    char pad52c[0x588 - 0x52c];
    u8 tag[1];              /* 0x588 */
} Work;

typedef struct {
    char body[0x3c];
} Mover;

typedef struct {
    Work *w;                /* 0x00 */
    int key;                /* 0x04 */
    char pad08[0x0c];
    Mover mv;               /* 0x14 */
    int tag;                /* 0x50 */
} Ctx;

typedef unsigned int   u32;

extern u32 func_02030EE8(struct S02030EE8 *p);
extern int func_021F935C(int x);
extern int func_022019F4(char *p, int key);
extern void func_021F89BC(void *o);
extern int func_021F9260(void *m, int *out);
extern void func_02015FBC(char *p, int v);
void func_02200D30(void *h);
void func_02200D68(void *o, char *q);


void func_02200D30(void *h)
{
    Ctx *c = (Ctx *)func_02030EE8(h);

    if (c->tag == c->w->tag[c->key])
        c->w->mask &= func_021F935C(c->key) ^ 0xFFFFFFFF;
}


void func_02200D68(void *o, char *q)
{
    char *p = *(char * *)&((struct Obj06316 *)q)->f0;
    int i = func_022019F4(p, ((struct Obj06316 *)q)->f4);
    char *e;
    int off;
    int r;

    if (i == -1) {
        func_021F89BC(o);
        return;
    }
    e = p + 8;
    off = i * 0x5C;
    if (*(int *)(e + off) == 0) {
        func_021F89BC(o);
        return;
    }
    if (((struct Obj06316 *)q)->f50 != *(u8 *)(p + ((struct Obj06316 *)q)->f4 + 0x596)) {
        func_021F89BC(o);
        return;
    }
    r = func_021F9260(q + 0x14, (int *)(q + 8));
    func_02015FBC(*(char **)(e + off), (u8)(((struct Obj06316 *)q)->f8 >> 12));
    if (r == 1)
        func_021F89BC(o);
}

/*
 * file:     event_field_proclink_p09.c
 * unit:     yes
 * function: func_02161724, func_02161824, func_02161850, func_021618A0, func_021618E0
 * address:  0x02161724
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DEE0  0x0216DEE0  thumb  ov010
 *   func_0216DE54  0x0216DE54  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216DB04  0x0216DB04  thumb  ov010
 *   func_0216DA5C  0x0216DA5C  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02161938  0x02161938  thumb  ov010
 *   func_02197D3C  0x02197D3C  thumb  ov021
 *   func_02161964  0x02161964  thumb  ov010
 *   func_02161984  0x02161984  thumb  ov010
 *   func_02161950  0x02161950  thumb  ov010
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   d_02171404     0x02171404  data  a1
 *   d_021713FC     0x021713FC  data  a1
 *   d_021713F4     0x021713F4  data  a1
 *   d_021713EC     0x021713EC  data  a1
 */
#include "../../matched/include/Obj05855.h"

struct AnimWork;
struct Ctx;
struct Desc;
struct Obj;
struct Obj00020;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct AnimWork {
    u32 f00;
    void *field;        /* 0x04 */
    u32 f08;
    u8 busy;            /* 0x0C */
} AnimWork;

typedef struct Obj {
    u8 pad00[4];
    void *f04;          /* 0x04 */
    u8 pad08[4];
    u16 f0c;            /* 0x0C */
    u8 pad0e[2];
    void *f10;          /* 0x10 */
} Obj;

extern void *func_02188C7C(u8 *p);
extern void *func_0216DEE0(void *map);
extern void *func_0216DE54(void *map, u32 kind);
extern void func_0216D9A0(void *map);
extern int func_0216D454(void *obj);
extern char *func_0216DB04(void *a0);
extern int func_0216DA5C(void *obj);
extern void func_0216DAF8(void *obj);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02161938(void *a, u32 b);
extern void *func_02197D3C(void *a, void *b);
extern int func_02161964(int a0, int a1);
extern int func_02161984(int a0);
void func_02161950(char *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern u16 func_0216D5F8(void *p);
int func_02161724(void *task, u32 *seq, AnimWork *w);
void *func_02161824(void *a, void *b);
int func_02161850(void *a0, int *state, Obj *o);
/* * Allocator with callback, then a sub-init call and link fields. */ void *func_021618A0(void *p, int a1, int a2, int a3);
void *func_021618E0(void *a, void *b);
extern const char d_02171404[];
extern const char d_021713FC[];
extern const char d_021713F4[];
extern const char d_021713EC[];


/*
 * Three-step sequence over the field map's objects: step 0 starts the
 * animations that are not yet running and records them in w->busy, step
 * 1 waits until every recorded one has finished, step 2 answers done.
 *
 * The image keeps a second object that is always NULL (`movs r6, #0;
 * beq` reuses the movs flags, and the NULL is still passed to
 * func_0216DA5C in step 1): written as a pointer local set to 0 and
 * tested. w->field is read into a local before the switch.
 */
int func_02161724(void *task, u32 *seq, AnimWork *w)
{
    void *map;
    void *a;
    void *b;
    void *c;
    void *field;

    field = w->field;
    switch (*seq) {
    case 0:
        map = func_02188C7C(field);
        a = func_0216DEE0(map);
        func_0216DE54(map, 0x30);
        w->busy = 0;
        func_0216D9A0(map);
        if (func_0216D454(a) == 0) {
            w->busy |= 1;
            func_0216DB04(a);
        }
        b = 0;
        if (b != 0 && func_0216DA5C(b) == 1) {
            w->busy |= 4;
            func_0216DB04(b);
        }
        (*seq)++;
        break;
    case 1:
        map = func_02188C7C(field);
        a = func_0216DEE0(map);
        func_0216DE54(map, 0x30);
        if ((w->busy & 1) && func_0216D454(a) == 1) {
            func_0216DAF8(a);
            w->busy &= ~1;
        }
        if (w->busy & 4) {
            b = 0;
            if (func_0216DA5C(b) == 0) {
                func_0216DAF8(b);
                w->busy &= ~4;
            }
        }
        if (w->busy & 2) {
            c = func_0216DE54(map, 0x30);
            if (func_0216DA5C(c) == 0) {
                func_0216DAF8(c);
                w->busy &= ~2;
            }
        }
        if (w->busy == 0)
            (*seq)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}


void *func_02161824(void *a, void *b) { void *t; u32 *p; t=func_020122C0(a,0,func_02161724,0x10); p=func_020124E8(t); p[0]=(u32)a; p[1]=(u32)b; p[2]=(u32)func_020120F4(a); return t; }



int func_02161850(void *a0, int *state, Obj *o)
{
    void *t;

    t = func_02188C7C(o->f04);
    switch (*state) {
    case 0:
        t = func_02161938(t, o->f0c);
        if (t == 0)
            return 1;
        func_02161964((int)o, (int)func_02197D3C(t, o->f10));
        *state = *state + 1;
        break;
    case 1:
        if (func_02161984((int)o) == 0)
            return 1;
        break;
    }
    return 0;
}



/*
 * Allocator with callback, then a sub-init call and link fields.
 */
void *func_021618A0(void *p, int a1, int a2, int a3)
{
    void *r0v = func_020122C0(p, 0, func_02161850, 0x34);
    char *r4 = func_020124E8(r0v);

    func_02161950(r4);
    ((struct Obj05855 *)r4)->f0 = p;
    ((struct Obj05855 *)r4)->f4 = a1;
    ((struct Obj05855 *)r4)->f8 = (int)func_020120F4(p);
    ((struct Obj05855 *)r4)->fC = a2;
    ((struct Obj05855 *)r4)->f10 = a3;
    return r0v;
}



void *func_021618E0(void *a, void *b)
{
    const char *s;

    switch (func_0216D5F8(func_021A3074(func_02188CB4(b)))) {
    case 0:
        s = d_02171404;
        break;
    case 1:
        s = d_021713FC;
        break;
    case 2:
        s = d_021713F4;
        break;
    case 3:
        s = d_021713EC;
        break;
    }
    return func_021618A0(a, (int)b, 0xFF, (int)s);
}

/*
 * file:     btlv_effvm_p84.c
 * unit:     yes
 * function: func_02201DA0, func_02201DB4, func_02201E04, func_02201F98
 * address:  0x02201DA0
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
 *   func_0204AEF4  0x0204AEF4  arm
 *   func_021F86E0  0x021F86E0  thumb  ov094
 *   func_021F86D4  0x021F86D4  thumb  ov094
 *   func_0202173C  0x0202173C  thumb
 *   func_02030734 0x02030734 arm
 *   func_0207C768 0x0207C768 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021F918C 0x021F918C thumb ov094
 *   d_0220AE88 0x0220AE88 data ov094 a1
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_0204B404  0x0204B404  arm
 */
#include "../../matched/include/Obj07895.h"

struct Obj;
struct Vec2;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

typedef signed short s16;

typedef signed char s8;

typedef struct { int x, y, z; } Vec;

typedef struct { void *owner; Vec start; int idx, mode; Vec a, b, delta; int n1, n2, zero, s2, s3; } Job;

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

extern u32 func_0204B878(void *obj, u16 v);
extern int func_0204AEF4(u32 idx, u32 alternate);
extern int func_021F86E0(void);
extern void *func_021F86D4(void);
extern int func_0202173C(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_0207C768(u32 a, u32 b);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021F918C(const Vec *, const Vec *, Vec *, int);
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
extern int func_021F9260(void *m, int *out);
extern void func_021F89BC(void *p);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
u32 func_02201DA0(char *p, int i, int v);
void func_02201DB4(char *base, int idx, u8 b, u8 c, s8 step, u16 d);
void func_02201E04(char *o, int idx, u32 mode, Vec *v, Vec *w, int s1, int s2, int s3, void (*f1)(void *, void *), void (*f2)(void *));
void func_02201F98(void *a, Obj *o);
extern char d_0220AE88[];


u32 func_02201DA0(char *p, int i, int v)
{
    return func_0204B878(*(void **)(p + i * 16 + 8), (u16)v);
}


void func_02201DB4(char *base, int idx, u8 b, u8 c, s8 step, u16 d)
{
    u16 m = 1 << (((u32)func_0204AEF4((u32)(*(void **)(base + idx * 16 + 0x10)), (int)0) & 0x3FF) >> 5);
    void *p = (void *)func_021F86E0();

    func_0202173C(p, 4, m, step, b, c, d, func_021F86D4());
}

static inline int Round(int x)
{
    if (x > 0) return _ffix(_fadd(0.5f, _fflt(x << 12)));
    else return _ffix(_fsub(_fflt(x << 12), 0.5f));
}

void func_02201E04(char *o, int idx, u32 mode, Vec *v, Vec *w, int s1, int s2, int s3,
                   void (*f1)(void *, void *), void (*f2)(void *))
{
    Job *p;
    p = func_02030734((u16)((((struct Obj07895 *)o)->f80 & 0x7fff) | 0x8000), 0x50, 0, d_0220AE88, 0x197);
    p->owner = o;
    p->idx = idx;
    p->start.x = v->x;
    p->start.y = v->y;
    p->start.z = v->z;
    p->mode = mode;
    p->n1 = s1;
    p->n2 = s1;
    p->zero = 0;
    p->s2 = s2;
    p->s3 = s3 * 2;
    p->a.x = v->x;
    p->a.y = v->y;
    p->a.z = v->z;
    p->b.x = w->x;
    p->b.y = w->y;
    p->b.z = w->z;
    switch (mode) {
    case 1:
        func_021F918C(&p->a, w, &p->delta, Round(s1));
        break;
    case 3:
        p->n2 *= 2;
        p->s3 *= 2;
    case 2:
        p->delta.x = func_0207C768(w->x, Round(s1));
        p->delta.y = func_0207C768(w->y, Round(s1));
        p->delta.z = func_0207C768(w->z, Round(s1));
        break;
    case 0:
    default:
        break;
    }
    func_021F896C(func_02030DA8(((struct Obj07895 *)o)->f0, f1, p, 0), f2, 0);
}


void func_02201F98(void *a, Obj *o)
{
    Ent *t = o->tbl;
    int r = func_021F9260(o->mover, &o->x);
    short v[2];

    v[0] = o->x >> 12;
    v[1] = o->y >> 12;
    func_0204B404(t[o->idx].h, (const struct Vec2 *)v, 0);
    if (r == 1)
        func_021F89BC(a);
}

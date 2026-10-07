/*
 * file:     btlv_bg_p05.c
 * unit:     yes
 * function: func_0220985C, func_0220986C, func_022099E8, func_02209A40, func_02209A54
 * address:  0x0220985C
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
 *   func_02030734 0x02030734 arm
 *   func_0207C768 0x0207C768 arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021F896C 0x021F896C thumb ov094
 *   func_021F918C 0x021F918C thumb ov094
 *   d_0220AEF0 0x0220AEF0 data ov094 a1
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_02209784  0x02209784  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_02030EE8  0x02030EE8  arm
 *   func_02040618  0x02040618  arm
 */
#include "../../matched/include/Obj13628.h"

struct S02030EE8;
typedef struct {
    char pad[4];
    unsigned int f : 1;
} S985C;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int x, y, z; } Vec;

typedef struct { void *owner; Vec start; int mode; Vec a, b, delta; int n1, n2, zero, s2, s3; } Job;

typedef unsigned char u8;

typedef struct {
    void *w;                /* 0x00 */
    int x;                  /* 0x04 */
    int y;                  /* 0x08 */
    int pad0c;
    int mv[4];              /* 0x10 */
    int dx;                 /* 0x20 */
    int dy;                 /* 0x24 */
    char pad28[0x38 - 0x28];
    int n;                  /* 0x38 */
} S;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_0207C768(u32, u32);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern void func_021F918C(const Vec *, const Vec *, Vec *, int);
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
extern int func_021F9260(void *m, int *out);
extern void func_02209784(void *w, int x, int y);
extern void func_021F89BC(void *h);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
unsigned int func_0220985C(S985C *p);
void func_0220986C(char *o, u32 mode, Vec *v, Vec *w, int s1, int s2, int s3, void (*f1)(void *, void *));
void func_022099E8(void *h, S *s);
void func_02209A40(void *h);
void func_02209A54(void *h);
extern char d_0220AEF0[];


/*
 * lane O10 candidate
 */
unsigned int func_0220985C(S985C *p)
{
    return p->f != 0;
}

static inline int Round(int x)
{
    if (x > 0) return _ffix(_fadd(0.5f, _fflt(x << 12)));
    else return _ffix(_fsub(_fflt(x << 12), 0.5f));
}

/*
 * lever: matched twin 02201E04 with its unused idx slot removed; this
 *   caller registers fixed callback 02209A40, not a ninth parameter.
 */
void func_0220986C(char *o, u32 mode, Vec *v, Vec *w, int s1, int s2, int s3,
                   void (*f1)(void *, void *))
{
    Job *p;
    p = func_02030734(((struct Obj13628 *)o)->f8, 0x4c, 0, d_0220AEF0, 0xb8);
    p->owner = o;
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
    func_021F896C(func_02030DA8(((struct Obj13628 *)o)->f0, f1, p, 0), func_02209A40, 0);
}


void func_022099E8(void *h, S *s)
{
    void *w = s->w;
    int done;

    if (s->mv[0] == 4) {
        s->x += s->dx;
        s->y += s->dy;
        if (s->n == 0) {
            done = 1;
        } else {
            s->n--;
            done = 0;
        }
    } else {
        done = func_021F9260(s->mv, &s->x);
    }
    func_02209784(w, s->x >> 12, s->y >> 12);
    if (done == 1)
        func_021F89BC(h);
}


void func_02209A40(void *h)
{
    int *w = *((int **)func_02030EE8(h));
    w[1] &= ~1;
}


/*
 * Task callback passed to func_020056A0 by func_02209784 (leaf of that
 * caller: its pool word 0x02209A55 names this unlabelled Thumb function).
 */
void func_02209A54(void *h)
{
    int *p = (int *)func_02030EE8(h);

    func_02040618(3, 0, p[0]);
    func_02040618(3, 3, p[1]);
    func_021F89BC(h);
}

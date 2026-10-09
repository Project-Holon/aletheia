/*
 * file:     btlv_bg.c
 * unit:     yes
 * function: func_02209224, func_022092E8, func_02209318, func_02209458, func_022094BC, func_02209500, func_02209540, func_02209744, func_0220975C, func_0220977C, func_02209784, func_022097CC, func_0220985C, func_0220986C, func_022099E8, func_02209A40, func_02209A54
 * address:  0x02209224
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
 *   func_02030734  0x02030734  arm
 *   d_0220AEE0     0x0220AEE0  data  ov094
 *   func_020490F4  0x020490F4  arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_021F86E0  0x021F86E0  thumb  ov094
 *   func_0204AEF4  0x0204AEF4  arm
 *   func_020216D4  0x020216D4  thumb
 *   func_02049238  0x02049238  arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_020870D0 0x020870D0 arm
 *   func_021F86D4 0x021F86D4 thumb ov094
 *   func_02030DA8 0x02030DA8 arm
 *   d_0220ABC0 0x0220ABC0 data a4
 *   d_0220ABC8 0x0220ABC8 data a4
 *   d_0220ABE0 0x0220ABE0 data a4
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_0204B22C  0x0204B22C  arm
 *   _ll_udiv       0x0209C00C  arm
 *   d_0220ABB8  0x0220ABB8  data  a4
 *   d_0220AEF0     0x0220AEF0  data  ov094
 *   func_020307B0  0x020307B0  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_021F896C  0x021F896C  thumb  ov094
 *   func_020407E8  0x020407E8  arm
 *   func_02040804  0x02040804  arm
 *   func_0207C768 0x0207C768 arm
 *   func_021F918C 0x021F918C thumb ov094
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   func_021F9260  0x021F9260  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 *   func_02030EE8  0x02030EE8  arm
 *   func_02040618  0x02040618  arm
 */
#include "../../matched/include/Obj13628.h"

struct PalAnmSlot;
struct Bank;
struct Obj;
struct Node;
struct Timer;
struct S02030EE8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int h0;                 /* 0x00 */
    int h4;                 /* 0x04 */
    char pad08[0x40 - 0x08];
    int h40;                /* 0x40 */
    int h44;                /* 0x44 */
    int h48;                /* 0x48 */
    char pad4c[0x74 - 0x4c];
    u16 heap;               /* 0x74 */
} W_02209224;

typedef signed int     s32;

typedef struct {
    int h0;
    int h4;
    char pad08[0x40 - 0x08];
    int h40;
    int h44;
    int h48;
} W_022092E8;

typedef unsigned long long u64;

typedef short s16;

typedef struct { s16 x, y, z, rest; } Pos;

typedef struct { int v[2]; } Pair_02209224;

typedef struct { int v[6]; } Six;

typedef struct { int v[2][6]; } Twelve;

typedef struct { u32 h[7]; } Entry;

typedef struct {
    u32 h[2]; Entry e[2]; u32 obj40, obj44, obj48;
    int left[2]; u64 time[2]; int state[2]; void *task;
    char pad70[4]; u16 heap;
} Work;

typedef struct {
    int f[7];
} Row;

typedef struct {
    Row r[2];
    char pad[0x6c - 0x38];
    void *m6c;
    void *m70;
} W;

typedef struct {
    int h[2];
    char pad8[0x4c - 8];
    int x4c[2];
    u64 t[2];
    int x64[2];
} W_022094BC;

typedef struct {
    int h[2];
    char pad8[0x4c - 8];
    int x4c[2];
    u64 t[2];
} W_02209500;

typedef struct Digits { void *icon; void *m10; void *m1; void *colon; void *s10; void *s1; void *pad; } Digits;

typedef struct Timer {
    int pad0;
    int pad4;
    Digits d[2];
    int pad40[3];
    int limit[2];
    u64 start[2];
    int base[2];
} Timer;

typedef enum { B_FALSE, B_TRUE } Bool;

typedef struct Pair_022094BC { int v[2]; } Pair_022094BC;

typedef struct {
    void *f0;
    int f4;
    u16 f8;
} W_0220975C;

typedef struct {
    char pad[8];
    u16 heap;               /* 0x08 */
} W_02209784;

typedef struct { int x, y, z; } Vec;

typedef struct {
    void *f0;
    u32 b0 : 1;
    u32 rest : 31;
} O;

typedef struct {
    char pad[4];
    unsigned int f : 1;
} S985C;

typedef struct { void *owner; Vec start; int mode; Vec a, b, delta; int n1, n2, zero, s2, s3; } Job;

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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(u32 id, u32 heap);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern int func_021F86E0(void);
extern int func_0204AEF4(u32 idx, u32 alternate);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_02049238(void * h);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern u32 func_020307B0(void *p);
extern struct Obj *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B92C(struct Obj *p, u32 v);
extern u64 func_020870D0(void);
extern void *func_021F86D4(void);
extern void *func_02030DA8(void *, void (*)(void *, void *), void *, u32);
extern void func_0204B3B4(struct Obj *p);
extern void func_02030EAC(struct Node *n);
extern void func_0204B22C(struct Bank *bank, u32 mode);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void *func_020056A0(void (*cb)(void *), void *ctx, int pri);
extern void func_021F896C(void *h, void (*cb)(void *), int arg);
extern u32 func_020407E8(u32 layer);
extern u32 func_02040804(u32 layer);
extern u32 func_0207C768(u32, u32);
extern void func_021F918C(const Vec *, const Vec *, Vec *, int);
extern float _fflt(int);
extern float _fadd(float, float);
extern float _fsub(float, float);
extern int _ffix(float);
extern int func_021F9260(void *m, int *out);
extern void func_021F89BC(void *h);
extern u32 func_02030EE8(struct S02030EE8 *p);
extern void func_02040618(u32 layer, u32 a, u32 b);
W_02209224 *func_02209224(u16 heap);
void func_022092E8(W_022092E8 *w);
void func_02209318(Work *m, int a, int b);
void func_02209458(W *w);
void func_022094BC(u8 *p, int i, int a, int b);
int func_02209500(W_02209500 *w, int i);
void func_02209540(Timer *p, int idx);
void func_02209744(int unused, int x);
W_0220975C *func_0220975C(void *a, u16 heap);
void func_0220977C(void *p);
void func_02209784(W_02209784 *w, u32 a, u32 b);
void func_022097CC(O *o, int a, u32 mode, int x, int y, int s1, int s2, int s3);
unsigned int func_0220985C(S985C *p);
void func_0220986C(char *o, u32 mode, Vec *v, Vec *w, int s1, int s2, int s3, void (*f1)(void *, void *));
void func_022099E8(void *h, void *arg);
void func_02209A40(void *h);
void func_02209A54(void *h);
extern char d_0220AEE0[];
extern const Pair_02209224 d_0220ABC0;
extern const Six d_0220ABC8;
extern const Twelve d_0220ABE0;
extern const Pair_022094BC d_0220ABB8;
extern char d_0220AEF0[];






/*
 * Lever: the `lsls #15 / lsrs #16` argument is `(u16)(v >> 1)`; `& 0x7fff`
 * or `& 0x1ffff` forms pool the mask and shift the registers.
 */
W_02209224 *func_02209224(u16 heap)
{
    W_02209224 *w;
    void *a;
    void *s;

    w = func_02030734(heap, 0x78, 1, d_0220AEE0, 0x81);
    w->heap = heap;
    a = func_020490F4(0xb, (u16)((w->heap & 0x7fff) | 0x8000));
    w->h0 = (int)func_0204B100(6, 0, w->heap);
    w->h4 = (int)func_0204B100(6, 0, w->heap);
    w->h40 = func_0204A6C8(a, 0x7a, 0, 0, w->heap);
    w->h44 = func_0204AF28(a, 0x7b, 0x7c, w->heap);
    w->h48 = func_0204ABF0(a, 0xa2, 0, 0xe0, w->heap);
    s = (void *)func_021F86E0();
    func_020216D4(s, 2, (u16)(func_0204AEF4(w->h48, 0) >> 1), 0x20);
    func_02049238(a);
    return w;
}






void func_022092E8(W_022092E8 *w)
{
    func_02209458((W *)w);
    func_0204A8D4(w->h40);
    func_0204AFD8(w->h44);
    func_0204ADA4(w->h48);
    func_0204B1CC((struct Bank *)w->h0);
    func_0204B1CC((struct Bank *)w->h4);
    func_020307B0(w);
}





/*
 * lever: y is a full int, narrowed by assignment to pos.y; s16 y sinks
 *   its home store and swaps it with the explicit handle-offset spill.
 *   Aggregate locals are declared icons, values, pos, types in that order.
 */
void func_02209318(Work *m, int a, int b)
{
    Six icons;
    Twelve values;
    Pos pos = {0, 0, 0, 0};
    Pair_02209224 types;
    int y;
    int off;
    int i, j;
    int *row;
    icons = d_0220ABC8;
    types = d_0220ABC0;
    values = d_0220ABE0;
    for (i = 0; i < 2; i++) {
        if ((i == 0 && a != 0) || (i == 1 && b != 0)) {
            off = i * 4;
            y = types.v[i];
            row = values.v[i];
            for (j = 0; j < 6; j++) {
                pos.x = icons.v[j];
                pos.y = y;
                pos.z = row[j];
                m->e[i].h[j] = (u32)func_0204B294((void *)*(u32 *)((char *)m + off), m->obj40, m->obj48, m->obj44, &pos, 0, m->heap);
                func_0204B92C((struct Obj *)m->e[i].h[j], 1);
            }
        }
    }
    if (a > 5999) a = 5999;
    if (b > 5999) b = 5999;
    m->left[0] = a;
    m->left[1] = b;
    m->time[1] = func_020870D0();
    m->time[0] = m->time[1];
    func_022094BC((u8 *)m, 0, 0, 0);
    func_022094BC((u8 *)m, 1, 0, 0);
    m->task = func_02030DA8(func_021F86D4(), (void (*)(void *, void *))func_02209744, m, 0);
}






void func_02209458(W *w)
{
    int i;
    int j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 6; j++) {
            if (w->r[i].f[j + 2] != 0) {
                func_0204B3B4((struct Obj *)w->r[i].f[j + 2]);
                w->r[i].f[j + 2] = 0;
            }
        }
    }
    if (w->m6c != 0) {
        func_02030EAC(w->m6c);
        w->m6c = 0;
    }
    if (w->m70 != 0) {
        func_02030EAC(w->m70);
        w->m70 = 0;
    }
}





void func_022094BC(u8 *p, int i, int a, int b)
{
    W_022094BC *w = (W_022094BC *)p;

    if (*(int *)(p + i * 0x1c + 8) != 0) {
        if (a == 1 && b == 1) {
            w->t[i] = func_020870D0();
            w->x64[i] = 0;
            func_02209540((struct Timer *)w, i);
        }
        func_0204B22C((struct Bank *)w->h[i], a);
    }
}





int func_02209500(W_02209500 *w, int i)
{
    u64 d;

    d = func_020870D0() - w->t[i];
    d = (d << 6) / 33514000ULL;
    return w->x4c[i] - (int)d <= 0;
}





/*
 * note: the 0/1 icon offset is an enum-constant ternary (an int spelling flips the bne polarity).
 */
void func_02209540(Timer *p, int idx)
{
    Pair_022094BC tbl = d_0220ABB8;
    int icon = idx == 0 ? B_FALSE : B_TRUE;
    int r = p->limit[idx] - (int)(((func_020870D0() - p->start[idx]) * 64) / 33514000);
    int min, sec, m10, m1, s10, s1;
    if (p->d[idx].icon == 0)
        return;
    if (r < 0)
        r = 0;
    min = r / 60;
    sec = r % 60;
    m10 = min / 10;
    m1 = min % 10;
    s10 = sec / 10;
    s1 = sec % 10;
    if (r == tbl.v[idx])
        p->base[idx] = 13;
    func_0204B878(p->d[idx].icon, icon + p->base[idx]);
    if (m10 == 0) {
        func_0204B3DC(p->d[idx].m10, 0);
    } else {
        func_0204B3DC(p->d[idx].m10, 1);
        func_0204B878(p->d[idx].m10, m10 + 3 + p->base[idx]);
    }
    if (m10 == 0 && m1 == 0) {
        func_0204B3DC(p->d[idx].m1, 0);
        func_0204B3DC(p->d[idx].colon, 0);
    } else {
        func_0204B3DC(p->d[idx].m1, 1);
        func_0204B3DC(p->d[idx].colon, 1);
        func_0204B878(p->d[idx].m1, m1 + 3 + p->base[idx]);
        func_0204B878(p->d[idx].colon, p->base[idx] + 2);
    }
    if (m10 == 0 && m1 == 0 && s10 == 0) {
        func_0204B3DC(p->d[idx].s10, 0);
    } else {
        func_0204B3DC(p->d[idx].s10, 1);
        func_0204B878(p->d[idx].s10, s10 + 3 + p->base[idx]);
    }
    func_0204B878(p->d[idx].s1, s1 + 3 + p->base[idx]);
}





/*
 * lane O10 candidate
 */
void func_02209744(int unused, int x)
{
    func_02209540((struct Timer *)x, 0);
    func_02209540((struct Timer *)x, 1);
}




W_0220975C *func_0220975C(void *a, u16 heap)
{
    W_0220975C *w = func_02030734(heap, 0xc, 1, d_0220AEF0, 0x48);
    w->f0 = a;
    w->f8 = heap;
    return w;
}




void func_0220977C(void *p)
{
    func_020307B0(p);
}




void func_02209784(W_02209784 *w, u32 a, u32 b)
{
    u32 *o;

    o = func_02030734((u16)((w->heap & 0x7fff) | 0x8000), 8, 0, d_0220AEF0, 0x67);
    o[0] = a;
    o[1] = b;
    func_021F896C(func_020056A0(func_02209A54, o, 0), 0, 0);
}




void func_022097CC(O *o, int a, u32 mode, int x, int y, int s1, int s2, int s3)
{
    Vec w;
    Vec v;

    v.x = x << 12;
    v.y = y << 12;
    v.z = 0;
    w.x = func_020407E8(3) << 12;
    w.y = func_02040804(3) << 12;
    w.z = 0;
    if (mode == 4 && (a & 1))
        v.x *= -1;
    if (mode == 1) {
        v.x += w.x;
        v.y += w.y;
        v.z += w.z;
    }
    func_0220986C((char *)o, mode, &w, &v, s1, s2, s3, func_022099E8);
    o->b0 = 1;
}



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



void func_022099E8(void *h, void *arg)
{
    S *s = (S *)arg;
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

/*
 * file:     event_field_proclink_p12.c
 * unit:     yes
 * function: func_02161938, func_02161950, func_02161964, func_02161984, func_021619B8, func_02161AC0, func_02161B1C, func_02161B74, func_02161B90, func_02161BF8, func_02161C84
 * address:  0x02161938
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
 *   func_0216DE54 0x0216DE54 thumb ov010
 *   func_0216DE94 0x0216DE94 thumb ov010
 *   func_02197DA0  0x02197DA0  thumb
 *   func_02197DAC  0x02197DAC  thumb
 *   d_0217140C     0x0217140C  data
 *   _ll_mul        0x0209C054  arm
 *   FX_Div         0x0207C768  arm
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_02197D3C  0x02197D3C  thumb  ov021
 *   d_02171404     0x02171404  data  a1
 *   d_021713FC     0x021713FC  data  a1
 *   d_021713F4     0x021713F4  data  a1
 *   d_021713EC     0x021713EC  data  a1
 *   func_02082BCC  0x02082BCC  arm
 *   func_02012138  0x02012138  thumb
 *   func_02161CDC  0x02161CDC  thumb  ov010
 *   func_02161D18  0x02161D18  thumb  ov010
 *   func_0216570C  0x0216570C  thumb  ov010
 *   func_02012144  0x02012144  thumb
 *   func_0201213C  0x0201213C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   d_021BFB3C     0x021BFB3C  data  ov203
 *   ov203_id       0x000000CB  data
 *   func_020120F4  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 */
#include "../../matched/include/Obj12046.h"
#include "../../matched/include/Obj09160.h"

struct Actor;
struct Ctx;
struct Desc;
struct HopWork;
struct Obj;
struct Obj00020;
struct Comm;
struct IcaAnime;
struct Sub0200852CObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef short s16;

typedef int s32;

typedef long long s64;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct HopWork {
    void *owner;        /* 0x00 */
    void *obj;          /* 0x04 */
    s16 t;              /* 0x08 */
    u8 pad0A[2];
    VecFx32 start;      /* 0x0C */
    VecFx32 delta;      /* 0x18 */
} HopWork;

typedef struct Tri {
    u32 w[3];
} Tri;

typedef struct Node_02161938 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 pad08[4];
    Tri f0c;            /* 0x0C */
    u8 f18[12];         /* 0x18 */
} Node_02161938;

typedef struct Node_02161B90 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 f08[0x1C];       /* 0x08 */
} Node_02161B90;

typedef struct Obj {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 f08[0x18];       /* 0x08 */
    u32 f20;            /* 0x20 */
} Obj;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
    u8 d;
    u8 e;
    u8 f;
    u8 g : 7;
    u8 h : 1;
} S;

extern void *func_0216DE54(void *, unsigned int);
extern void *func_0216DE94(void *, unsigned int);
extern int func_02197DA0();
extern int func_02197DAC();
extern fx32 FX_Div(fx32 numer, fx32 denom);
extern void func_0216D89C(void *obj, const VecFx32 *pos);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern u16 func_0216D5F8(void *obj);
extern void func_0216E014(void *a, int *p, int b);
extern void func_020061E4(u32 se);
extern void func_021AC528(u32 a, u32 b);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188CD0(u8 *p);
extern void func_0207CA00(void *a, void *b, void *c);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern void *func_0216D4B4(char *p);
extern int func_02197D3C(void *a, const char *b);
extern void func_02082BCC(void *p, int v, int n);
extern unsigned int func_02012138(const struct Ctx *p);
extern void func_02161CDC(void *a, void *b, u8 c, u8 d);
extern void func_02161D18(int a, int b, u8 c, u8 d);
extern void func_0216570C(void);
extern u8 func_02012144(const struct Ctx *p);
extern void func_0201213C(struct Ctx *p, u32 v);
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
void func_02161938(void *p, unsigned int id);
void func_02161950(char *p);
int func_02161964(int a0, int a1);
int func_02161984(int a0);
int func_021619B8(void *task, u32 *seq, HopWork *w);
void *func_02161AC0(void *p, void *a1, Tri *t, void *a3);
int func_02161B1C(void *a);
int func_02161B74(int a0);
void *func_02161B90(void *p, void *a1, int kind, int sub, int flag);
int func_02161BF8(void *a0, int *state, Obj *o);
void func_02161C84(S *s, int a, int b, u8 d, u32 c, u8 e, u8 f, u8 g);
extern const fx32 d_0217140C[];
extern const char d_02171404[];
extern const char d_021713FC[];
extern const char d_021713F4[];
extern const char d_021713EC[];
extern u8 d_021BFB3C[];
extern u8 ov203_id[];


void func_02161938(void *p, unsigned int id) { if (id == 0xf2) func_0216DE54(p, 0x30); else if (id != 0xf1) func_0216DE94(p, id); }


void func_02161950(char *p)
{
    int i = 0;
    int zero = i;
    for (; i < 8; i++)
        *(int *)(p + 0x14 + i * 4) = zero;
}





int func_02161964(int a0, int a1)
{
    int a2;
    int a3;
    int t4;

t4 = 0;
loc_02161968:
a2 = t4 << 2;
a3 = a0 + a2;
a2 = ((struct Obj12046 *)a3)->f14;
    if (a2 != 0) goto loc_02161978;
loc_02161972:
((struct Obj12046 *)a3)->f14 = a1;
    return a0;
loc_02161978:
t4 = t4 + 1;
    if (t4 < 8) goto loc_02161968;
loc_0216197E:
    return a0;}



int func_02161984(int a0)
{
    int t4;
    int t5;
    int t6;
    int t7;

t6 = a0 + 0;
t7 = 0;
t4 = 0;
loc_0216198C:
a0 = t4 << 2;
t5 = t6 + a0;
a0 = ((struct Obj09160 *)t5)->f14;
    if (a0 == 0) goto loc_021619AC;
loc_02161996:
    a0 = func_02197DA0(a0);
loc_0216199A:
    if (a0 != 1) goto loc_021619AA;
loc_0216199E:
a0 = ((struct Obj09160 *)t5)->f14;
    a0 = func_02197DAC(a0);
loc_021619A4:
a0 = 0;
((struct Obj09160 *)t5)->f14 = a0;
    goto loc_021619AC;
loc_021619AA:
t7 = 1;
loc_021619AC:
t4 = t4 + 1;
    if (t4 < 8) goto loc_0216198C;
loc_021619B2:
a0 = t7 + 0;
    return a0;}



static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}



/*
 * Hop-and-land movement of a field object: state 0 follows the arc table
 * d_0217140C while sliding along (dx, dz) over 15 frames, state 1 drops
 * it 8.0 per frame onto start + delta, then snaps it there, plays the
 * landing sound and answers done.
 *
 * Levers (2026-09-28 tree_ov010_4): the frame test as `t > 15u` (cmp #15;
 * bls on the ldrsh), and the landing height read into a local before the
 * drop is computed.
 */
int func_021619B8(void *task, u32 *seq, HopWork *w)
{
    VecFx32 pos;
    fx32 y;
    fx32 floor;
    int done;

    done = 0;
    switch (*seq) {
    case 0:
        pos = w->start;
        pos.y += d_0217140C[w->t];
        w->t += 2;
        pos.x += FX_Div(FX_Mul(w->delta.x, w->t << 12), 15 << 12);
        pos.z += FX_Div(FX_Mul(w->delta.z, w->t << 12), 15 << 12);
        func_0216D89C(w->obj, &pos);
        if (w->t > 15u)
            (*seq)++;
        break;
    case 1:
        func_0216D88C(w->obj, &pos);
        floor = w->start.y + w->delta.y;
        y = pos.y - 0x8000;
        if (y > floor) {
            pos.y = y;
            func_0216D89C(w->obj, &pos);
        } else {
            pos.y = floor;
            done = 1;
            pos.x = w->start.x + w->delta.x;
            pos.z = w->start.z + w->delta.z;
            func_0216E014(w->obj, (int *)(&pos), func_0216D5F8(w->obj));
            func_020061E4(0x67B);
            func_021AC528((u32)w->obj, (u32)w->owner);
        }
        break;
    }
    return done;
}



void *func_02161AC0(void *p, void *a1, Tri *t, void *a3)
{
    void *h;
    Node_02161938 *n;

    h = func_020122C0(p, 0, func_021619B8, 0x24);
    n = func_020124E8(h);
    n->f04 = a1;
    n->f00 = (void *)func_02188CD0(func_0201210C(p));
    n->f0c = *t;
    func_0207CA00(a3, t, n->f18);
    func_020061E4(0x55E);
    return h;
}



int func_02161B1C(void *a)
{
    const char *s;
    void *p;

    p = func_021A3074(func_02188CB4(a));
    switch (func_0216D5F8(p)) {
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
    func_0216D4B4(p);
    return func_02197D3C(p, s);
}



int func_02161B74(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_02197DA0(a0);
loc_02161B7C:
    if (a0 != 1) goto loc_02161B8A;
loc_02161B80:
a0 = t4 + 0;
    a0 = func_02197DAC(a0);
loc_02161B86:
a0 = 1;
    return a0;
loc_02161B8A:
a0 = 0;
    return a0;}




void *func_02161B90(void *p, void *a1, int kind, int sub, int flag)
{
    void *h;
    Node_02161B90 *n;

    h = func_020122C0(p, a1, func_02161BF8, 0x24);
    n = func_020124E8(h);
    func_02082BCC(n, 0, 0x24);
    n->f00 = p;
    n->f04 = (void *)func_02012138(p);
    if (flag != 0)
        func_02161CDC(n->f08, p, kind, sub);
    else
        func_02161D18((int)n->f08, (int)p, kind, sub);
    if (kind == 3)
        func_0216570C();
    return h;
}




int func_02161BF8(void *a0, int *state, Obj *o)
{
    switch (*state) {
    case 0:
        o->f20 = func_02012144(o->f00);
        func_0201213C(o->f00, 1);
        if (func_02026454(o->f04) == 0) {
            *state = *state + 2;
        } else {
            func_02026400(o->f04);
            *state = *state + 1;
        }
        break;
    case 1:
        if (func_02026454(o->f04) == 0)
            *state = *state + 1;
        break;
    case 2:
        func_020120B4(o->f00, (u32)ov203_id, d_021BFB3C, o->f08);
        *state = *state + 1;
        break;
    case 3:
        if (func_020120F0(o->f00) == 0) {
            func_0201213C(o->f00, o->f20);
            return 1;
        }
        break;
    }
    return 0;
}



void func_02161C84(S *s, int a, int b, u8 d, u32 c, u8 e, u8 f, u8 g)
{
    func_02082BCC(s, 0, 0x18);
    s->a = a;
    s->b = b;
    s->d = d;
    s->c = c;
    s->e = e;
    s->f = f;
    s->g = g;
    s->h = (u8)(int)func_02008550((const struct Sub0200852CObj *)((int)func_02012944(func_020120F4((const struct Ctx *)a))));
}

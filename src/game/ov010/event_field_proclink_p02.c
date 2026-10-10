/*
 * file:     event_field_proclink_p02.c
 * unit:     yes
 * function: func_02161724, func_02161824, func_02161850, func_021618A0, func_021618E0, func_02161938, func_02161950, func_02161964, func_02161984, func_021619B8, func_02161AC0, func_02161B1C, func_02161B74, func_02161B90, func_02161BF8, func_02161C84, func_02161CDC, func_02161D18, func_02161D64, func_02161D98, func_02161DC4
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
 *   func_02197D3C  0x02197D3C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   d_02171404     0x02171404  data  a1
 *   d_021713FC     0x021713FC  data  a1
 *   d_021713F4     0x021713F4  data  a1
 *   d_021713EC     0x021713EC  data  a1
 *   func_0216DE94 0x0216DE94 thumb ov010
 *   func_02197DA0  0x02197DA0  thumb
 *   func_02197DAC  0x02197DAC  thumb
 *   d_0217140C     0x0217140C  data
 *   _ll_mul        0x0209C054  arm
 *   FX_Div         0x0207C768  arm
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216E014  0x0216E014  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_021AC528  0x021AC528  thumb  ov021
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CD0  0x02188CD0  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_02012138  0x02012138  thumb
 *   func_0216570C  0x0216570C  thumb  ov010
 *   func_02012144  0x02012144  thumb
 *   func_0201213C  0x0201213C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   d_021BFB3C     0x021BFB3C  data  ov203
 *   ov203_id       0x000000CB  data
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0203F4CC 0x0203F4CC arm
 *   func_0202E888 0x0202E888 thumb
 *   func_02012984 0x02012984 thumb
 *   func_02169100 0x02169100 thumb ov010
 *   func_02169110 0x02169110 thumb ov010
 *   func_02013A80  0x02013A80  thumb
 *   func_02161E78 0x02161E78 thumb ov010
 *   func_02161ECC  0x02161ECC  thumb
 */
#include "../../matched/include/Obj05855.h"
#include "../../matched/include/Obj12046.h"
#include "../../matched/include/Obj09160.h"
#include "../../matched/include/Obj12047.h"
#include "../../matched/include/Obj12329.h"

struct AnimWork;
struct Ctx;
struct Desc;
struct Obj_02161724;
struct Obj00020;
struct Actor;
struct HopWork;
struct Comm;
struct IcaAnime;
struct Sub0200852CObj;
struct RtcTime;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct AnimWork {
    u32 f00;
    void *field;        /* 0x04 */
    u32 f08;
    u8 busy;            /* 0x0C */
} AnimWork;

typedef struct Obj_02161724 {
    u8 pad00[4];
    void *f04;          /* 0x04 */
    u8 pad08[4];
    u16 f0c;            /* 0x0C */
    u8 pad0e[2];
    void *f10;          /* 0x10 */
} Obj_02161724;

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

typedef struct Obj_02161938 {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 f08[0x18];       /* 0x08 */
    u32 f20;            /* 0x20 */
} Obj_02161938;

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

typedef struct { u32 hour, minute, second; } RtcTime;

extern void *func_02188C7C(u8 *p);
extern void *func_0216DEE0(void *map);
extern void *func_0216DE54(void *map, u32 kind);
extern void func_0216D9A0(void *map);
extern int func_0216D454(void *obj);
extern char *func_0216DB04(void *a0);
extern int func_0216DA5C(void *obj);
extern void func_0216DAF8(void *obj);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj_02161724 *p);
extern void *func_020120F4(const struct Ctx *p);
extern int func_02197D3C(void *a, const char *b);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern u16 func_0216D5F8(void *p);
extern void *func_0216DE94(void *, unsigned int);
extern int func_02197DA0();
extern int func_02197DAC();
extern fx32 FX_Div(fx32 numer, fx32 denom);
extern void func_0216D89C(void *obj, const VecFx32 *pos);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_0216E014(void *a, int *p, int b);
extern void func_020061E4(u32 se);
extern void func_021AC528(u32 a, u32 b);
extern void *func_0201210C(const struct Ctx *p);
extern u32 func_02188CD0(u8 *p);
extern void func_0207CA00(void *a, void *b, void *c);
extern void *func_0216D4B4(char *p);
extern void func_02082BCC(void *p, int v, int n);
extern unsigned int func_02012138(const struct Ctx *p);
extern void func_0216570C(void);
extern u8 func_02012144(const struct Ctx *p);
extern void func_0201213C(struct Ctx *p, u32 v);
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_0203F4CC(struct RtcTime *time);
extern u8 func_0202E888(void);
extern u8 func_02012984(const struct BigObj *p);
extern int func_02169100(int);
extern int func_02169110(int);
extern int func_02013A80();
extern void func_02161E78(void *a0);
extern int func_02161ECC(char *);
int func_02161724(void *task, u32 *seq, AnimWork *w);
void *func_02161824(void *a, void *b);
int func_02161850(void *a0, int *state, Obj_02161724 *o);
void *func_021618A0(void *p, int a1, int a2, int a3);
void *func_021618E0(void *a, void *b);
void *func_02161938(void *p, unsigned int id);
void func_02161950(char *p);
int func_02161964(int a0, int a1);
int func_02161984(int a0);
int func_021619B8(void *task, u32 *seq, HopWork *w);
void *func_02161AC0(void *p, void *a1, Tri *t, void *a3);
int func_02161B1C(void *a);
int func_02161B74(int a0);
void *func_02161B90(void *p, void *a1, int kind, int sub, int flag);
int func_02161BF8(void *a0, int *state, Obj_02161938 *o);
void func_02161C84(S *s, int a, int b, u8 d, u32 c, u8 e, u8 f, u8 g);
void func_02161CDC(S *s, int a, u8 b, u8 d);
void func_02161D18(int a, int b, u8 c, u8 d);
int func_02161D64(int a0);
void func_02161D98(char *p);
char *func_02161DC4(char *p, int id, unsigned mode);
extern const char d_02171404[];
extern const char d_021713FC[];
extern const char d_021713F4[];
extern const char d_021713EC[];
extern const fx32 d_0217140C[];
extern u8 d_021BFB3C[];
extern u8 ov203_id[];





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






int func_02161850(void *a0, int *state, Obj_02161724 *o)
{
    void *t;

    t = func_02188C7C(o->f04);
    switch (*state) {
    case 0:
        t = func_02161938(t, o->f0c);
        if (t == 0)
            return 1;
        func_02161964((int)o, func_02197D3C(t, (const char *)o->f10));
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





void *func_02161938(void *p, unsigned int id) { if (id == 0xf2) return func_0216DE54(p, 0x30); else if (id != 0xf1) return func_0216DE94(p, id); return p; }





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
        func_02161CDC((S *)n->f08, (int)p, kind, sub);
    else
        func_02161D18((int)n->f08, (int)p, kind, sub);
    if (kind == 3)
        func_0216570C();
    return h;
}







int func_02161BF8(void *a0, int *state, Obj_02161938 *o)
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


void func_02161CDC(S *s, int a, u8 b, u8 d)
{
    RtcTime time;
    u8 day;
    func_0203F4CC((struct RtcTime *)(&time));
    day = func_0202E888();
    func_02161C84(s, a, b, d, 0, time.hour, time.minute, day);
}


/*
 * Padding: two zero alignment bytes after the 74-byte function.
 * Lever: c and d are u8, as in matched caller ov010_func_02161B90.c;
 * this puts the c home store before r0 is assigned b for the first call.
 */
void func_02161D18(int a, int b, u8 c, u8 d)
{
    int r4 = (int)func_020120F4((const struct Ctx *)b);
    int r6 = func_02169100(r4);
    int r7 = func_02169110(r4);
    u8 r0 = func_02012984((const struct BigObj *)r4);
    func_02161C84((S *)a, b, c, d, 0, (u8)r6, (u8)r7, r0);
}



int func_02161D64(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj12047 *)t4)->f2;
    if (a0 != 1) goto loc_02161D7E;
loc_02161D6E:
a0 = 0;
a1 = 1;
    a0 = func_02013A80(a0, a1);
loc_02161D76:
a0 = 1;
a1 = 1;
    a0 = func_02013A80(a0, a1);
loc_02161D7E:
a0 = ((struct Obj12047 *)t4)->f2;
    if (a0 != 0) goto loc_02161D94;
loc_02161D84:
a0 = 0;
a1 = 0;
    a0 = func_02013A80(a0, a1);
loc_02161D8C:
a0 = 1;
a1 = 0;
    a0 = func_02013A80(a0, a1);
loc_02161D94:
    return a0;}


void func_02161D98(char *p)
{
    int i;
    char *b;
    char *a;
    ((struct Obj12329 *)p)->f0 = 0;
    ((struct Obj12329 *)p)->f2 = 2;
    a = p + 8;
    b = p + 0xF8;
    for (i = 0; i < 10; i++) {
        func_02161E78((unsigned char *)(a + i * 24));
        func_02161E78((unsigned char *)(b + i * 24));
    }
}



char *func_02161DC4(char *p, int id, unsigned mode)
{
    int i;
    char *b;
    char *a;
    unsigned m1;

    m1 = mode - 1;
    a = p + 8;
    i = 0;
    b = p + 0xF8;

    for (; i < 10; i++) {
        if (mode == 0 || mode == 2) {
            if (func_02161ECC(a + i * 0x18) != 0 && (u8)p[i * 0x18 + 9] == id)
                return p + 8 + i * 0x18;
        }
        if (m1 <= 1) {
            if (func_02161ECC(b + i * 0x18) != 0 && (u8)p[i * 0x18 + 0xF9] == id)
                return p + 0xF8 + i * 0x18;
        }
    }
    return 0;
}

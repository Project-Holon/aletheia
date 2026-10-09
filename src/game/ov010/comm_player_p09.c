/*
 * file:     comm_player_p09.c
 * unit:     yes
 * function: func_0216A560, func_0216A594, func_0216A5C4, func_0216A5FC, func_0216A634, func_0216A674, func_0216A6B4, func_0216A6EC, func_0216A72C, func_0216A774, func_0216A7A0, func_0216A838, func_0216A884, func_0216A8F0, func_0216AAE4, func_0216ABD8, func_0216AC40, func_0216AC90
 * address:  0x0216A560
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
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_02168CF4  0x02168CF4  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021D0AB8  0x021D0AB8  thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_02008C58 0x02008C58 thumb
 *   func_02008E68 0x02008E68 thumb
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02008E78  0x02008E78  thumb
 *   func_021D0BE4  0x021D0BE4  thumb  ov021
 *   func_021D0DB0  0x021D0DB0  thumb  ov021
 *   func_021D0FE0  0x021D0FE0  thumb
 *   func_021D0FE8  0x021D0FE8  thumb  ov021
 *   func_02168E5C  0x02168E5C  thumb  ov010
 *   func_021D1028  0x021D1028  thumb
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   FX_SinCosTable_  0x020A1B38  data
 *   _ll_mul          0x0209C054  arm
 *   _u32_div_f       0x0209C2B0  arm
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_0216AED0  0x0216AED0  thumb  ov010
 *   func_0216AF1C  0x0216AF1C  thumb  ov010
 *   func_0216AF74  0x0216AF74  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_021664CC  0x021664CC  thumb  ov010
 *   func_0217C37C  0x0217C37C  thumb  ov018
 *   func_020307B0  0x020307B0  arm
 *   func_0200E0B0  0x0200E0B0  thumb
 *   func_0217C294  0x0217C294  thumb  ov018
 *   func_0200E18C  0x0200E18C  thumb
 *   func_0216AF3C  0x0216AF3C  thumb  ov010
 */
#include "../../matched/include/Obj17757.h"
#include "../../matched/include/Obj17758.h"
#include "../../matched/include/Obj17760.h"

struct Ctx;
struct Big;
struct Sub02008C20Obj;
struct Desc;
struct Obj;
struct Actor;
struct VecFx32;
struct Orbit;
struct Blk37;
struct LinkRecord;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} Vec3;

typedef struct {
    int f0;
    u16 f4;
    u16 f6;
    void *f8;
    Vec3 v;
} S_0216A7A0;

typedef struct {
    int f0;
    u16 f4;
    u16 f6;
    int f8;
    Vec3 v;
} S_0216A838;

typedef short s16;

typedef int s32;

typedef long long s64;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Orbit {
    u32 count;          /* 0x00 */
    void *obj;          /* 0x04 */
    VecFx32 pos;        /* 0x08 */
} Orbit;

typedef struct {
    u32 lo : 6;
    u32 mid : 12;
    u32 hi : 6;
    u32 rest : 8;
} Bits;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F50(void *base);
extern void *func_02168CF4();
extern int func_0215897C();
extern unsigned int func_02159B10(void *, void *);
extern int func_021D0AB8();
extern void *func_02012EBC(struct Big *p);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern void func_02008E68(struct Sub02008C20Obj *obj, u32 value);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u8 func_02008E78(struct Sub02008C20Obj *obj);
extern void *func_021D0BE4(void *a, u8 *b, u16 *c);
extern void func_021D0DB0(u32 a, u8 *w, u16 *outRank, u16 *outScore);
extern int func_021D0FE0();
extern void *func_021D0FE8(void *a, int unused, int c);
extern int func_02168E5C(int a, int b, int c);
extern int func_021D1028();
extern void *func_0215A5E4(void *a0);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C7C(unsigned char *p);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void *func_0216D568(void *p, u32 v);
extern void func_0216D89C();
extern void *func_0200CA1C(void *a);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017988(void *mon, u16 form);
extern void func_0200CFA0(struct Blk37 *p, void *m);
extern void *func_0216AED0(void *p, u32 id);
extern int func_0216AF1C();
extern struct Desc *func_0216AF74(int a0, int a1, int a2, int a3, u16 *a4, u16 a5);
extern u32 func_02012138(const struct Ctx *p);
extern u16 func_0215A5CC(void *a0);
extern struct LinkRecord *func_021664CC(u16 heap, void *sys, u32 *start);
extern void func_0217C37C();
extern u32 func_020307B0(void *p);
extern void *func_0200E0B0(void *p);
extern int func_0217C294(char *a0);
extern int func_0200E18C();
extern void func_0216AF3C(int a0);
int func_0216A560(int a0, int a1);
int func_0216A594(int a0, int a1);
int func_0216A5C4(void *a,void *b);
int func_0216A5FC(int a0, int a1);
int func_0216A634(int a0, int a1);
int func_0216A674(int a0, int a1);
int func_0216A6B4(int a0, int a1);
int func_0216A6EC(int a0, int a1);
int func_0216A72C(int a0, int a1);
int func_0216A774(int a0, int a1);
int func_0216A7A0(int a0, int a1);
int func_0216A838(int a0, int a1, S_0216A838 *p);
int func_0216A884(int a0, int a1);
int func_0216A8F0(void *unused, u32 *mode, Orbit *o);
void func_0216AAE4(void *sys, void *party, int season);
int func_0216ABD8(int a0, int a1);
int func_0216AC40(int a0, int a1);
int func_0216AC90(int a0, int a1);
extern const s16 FX_SinCosTable_[];




/*
 * blocked:  listing 52 compiled 50
 */
int func_0216A560(int a0, int a1)
{
    int t4;
    void *p;
    void *task;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A56A:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A572:
    p = func_020120F4((const struct Ctx *)v1);
loc_0216A578:
    v2 = func_02012F50(p);
loc_0216A57C:
a1 = ((struct Obj17757 *)((char *)v2))->f0;
    task = func_02168CF4(v1, a1);
loc_0216A586:
    a0 = func_0215897C(v0, task);
loc_0216A58E:
a0 = 1;
    return a0;}




/*
 * blocked:
 */
int func_0216A594(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;
    void *v2;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A5A0:
a0 = t6 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A5A6:
    p = func_020120F4((const struct Ctx *)v1);
loc_0216A5AA:
    v2 = func_02012F50(p);
loc_0216A5AE:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216A5B8:
a1 = a0 + 0;
a0 = ((struct Obj17758 *)((char *)v2))->f0;
    a0 = func_021D0AB8(a0, a1);
loc_0216A5C0:
a0 = 0;
    return a0;}



int func_0216A5C4(void *a,void *b) { void *sys; u32 n; func_0215A5F4(b); sys=func_020120F4(func_0215A5DC(b)); n=func_02159B10(a,b); func_02008E68(func_02008C58(func_02012EBC(sys)),(u8)n); return 0; }




int func_0216A5FC(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    void *p;
    struct Sub02008C20Obj *obj;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A608:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A60E:
    t6 = func_020120F4((const struct Ctx *)v1);
loc_0216A612:
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216A61C:
    p = func_02012EBC(t6);
loc_0216A624:
    obj = func_02008C58(p);
loc_0216A628:
    a0 = func_02008E78(obj);
loc_0216A62C:
*q = a0;
a0 = 0;
    return a0;}




int func_0216A634(int a0, int a1)
{
    void *r7;
    void *l0;
    int *r4;

    r7 = func_0215A5F4((void *)a1);
    l0 = func_0215A5DC((void *)a1);
    r4 = (int *)func_02012F50(func_020120F4((const struct Ctx *)l0));
    func_0215897C(r7, func_021D0BE4((void *)l0, (u8 *)*r4, func_02159AE8((void *)a0, (void *)a1)));
    return 1;
}




int func_0216A674(int a0, int a1)
{
    void *r7;
    int *r6;
    u16 *l0;

    func_0215A5F4((void *)a1);
    r7 = func_0215A5DC((void *)a1);
    r6 = (int *)func_02012F50(func_020120F4((const struct Ctx *)r7));
    l0 = func_02159AE8((void *)a0, (void *)a1);
    func_021D0DB0((u32)r7, (u8 *)(*r6), l0, func_02159AE8((void *)a0, (void *)a1));
    return 0;
}




/*
 * blocked:  listing 56 compiled 54
 */
int func_0216A6B4(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    u16 *q;
    void *v0;
    void *v1;
    void *v2;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A6C0:
a0 = t6 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A6C6:
    p = func_020120F4((const struct Ctx *)v1);
loc_0216A6CC:
    v2 = func_02012F50(p);
loc_0216A6D0:
a0 = t5 + 0;
a1 = t6 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216A6DA:
a1 = ((struct Obj17760 *)((char *)v2))->f0;
    a0 = func_021D0FE0(v1, a1);
loc_0216A6E4:
*q = a0;
a0 = 0;
    return a0;}




int func_0216A6EC(int a0, int a1)
{
    void *r7;
    void *l0;
    int *r4;

    r7 = func_0215A5F4((void *)a1);
    l0 = func_0215A5DC((void *)a1);
    r4 = (int *)func_02012F50(func_020120F4((const struct Ctx *)l0));
    func_0215897C(r7, func_021D0FE8((void *)l0, *r4, func_02159B10((void *)a0, (void *)a1)));
    return 1;
}




int func_0216A72C(int a0, int a1)
{
    void *r6;
    void *r7;
    int l0;

    r6 = func_0215A5F4((void *)a1);
    r7 = func_0215A5DC((void *)a1);
    func_02012F50(func_020120F4((const struct Ctx *)r7));
    l0 = func_02159B10((void *)a0, (void *)a1);
    func_0215897C(r6, (void *)func_02168E5C((int)r7, l0, func_02159B10((void *)a0, (void *)a1)));
    return 1;
}




int func_0216A774(int a0, int a1)
{
    int t4;
    int t5;
    u16 *q;
    void *v0;
    void *v1;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = t4 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A780:
a0 = t4 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A786:
a0 = t5 + 0;
a1 = t4 + 0;
    q = func_02159AE8((void *)a0, (void *)a1);
loc_0216A790:
    a0 = func_021D1028(v1);
loc_0216A798:
*q = a0;
a0 = 0;
    return a0;}




int func_0216A7A0(int a0, int a1)
{
    void *l0;
    void *r6;
    int l4;
    int r7;
    int r5;
    struct Desc *l8;
    void *obj;
    S_0216A7A0 *r4;

    func_0215A5E4((void *)a1);
    l0 = func_0215A5F4((void *)a1);
    r6 = func_0215A5DC((void *)a1);
    l4 = func_02159B10((void *)a0, (void *)a1);
    r7 = func_02159B10((void *)a0, (void *)a1);
    r5 = func_02159B10((void *)a0, (void *)a1);
    l8 = func_020122C0((void *)r6, 0, (void *)func_0216A838, 0x18);
    r4 = func_020124E8((struct Obj *)l8);
    r4->f4 = r5;
    r4->f6 = 0;
    obj = func_0216DE94((void *)func_02188C7C(func_0201210C((void *)r6)), l4);
    func_0216D88C(obj, (struct VecFx32 *)&r4->v);
    r4->f8 = obj;
    func_0216D568(obj, 0x8000);
    r4->f0 = (r7 << 15) - r4->v.b;
    func_0215897C(l0, l8);
    return 1;
}




int func_0216A838(int a0, int a1, S_0216A838 *p)
{
    Vec3 loc;

    p->f6 = p->f6 + 1;
    loc = p->v;
    loc.b += (p->f0 * p->f6) / p->f4;
    func_0216D89C(p->f8, &loc);
    if (p->f6 >= p->f4) {
        return 1;
    }
    return 0;
}




int func_0216A884(int a0, int a1)
{
    void *l0;
    void *r4;
    int r6;
    struct Desc *r7;
    void *m;
    int *r5;

    func_0215A5E4((void *)a1);
    l0 = func_0215A5F4((void *)a1);
    r4 = func_0215A5DC((void *)a1);
    r6 = func_02159B10((void *)a0, (void *)a1);
    r7 = func_020122C0((void *)r4, 0, (void *)func_0216A8F0, 0x14);
    r5 = func_020124E8((struct Obj *)r7);
    r5[0] = 0;
    m = func_0216DE94((void *)func_02188C7C(func_0201210C((void *)r4)), r6);
    func_0216D88C((const struct Actor *)m, (struct VecFx32 *)(r5 + 2));
    ((void **)r5)[1] = m;
    func_0215897C(l0, r7);
    return 1;
}




static inline fx32 FX_Mul(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}





/*
 * Three-phase orbit step: spiral out over 110 frames, circle at radius 3
 * for 80, spiral in for 80, returning 1 when done. FX_Mul must be the
 * inline function with the table value first (the macro, or the radius
 * first, puts the radius in r0:r1 and spills its sign word: 368 out).
 */
int func_0216A8F0(void *unused, u32 *mode, Orbit *o)
{
    VecFx32 pos;
    u32 cnt;
    s32 idx;
    fx32 r;

    pos = o->pos;
    cnt = ++o->count;
    switch (*mode) {
    case 0:
        idx = (cnt << 17) / 110;
        if (idx >= 0x10000)
            idx %= 0x10000;
        idx = (idx >> 4) * 2;
        r = (cnt * 3 << 16) / 110;
        pos.x += FX_Mul(FX_SinCosTable_[idx + 1], r);
        pos.z += FX_Mul(FX_SinCosTable_[idx], r);
        func_0216D89C(o->obj, &pos);
        if (o->count >= 110) {
            o->count = 0;
            *mode = 1;
        }
        break;
    case 1:
        idx = (cnt << 16) / 80;
        if (idx >= 0x10000)
            idx %= 0x10000;
        idx = (idx >> 4) * 2;
        pos.x += FX_Mul(FX_SinCosTable_[idx + 1], 0x30000);
        pos.z += FX_Mul(FX_SinCosTable_[idx], 0x30000);
        func_0216D89C(o->obj, &pos);
        if (o->count >= 80) {
            o->count = 0;
            *mode = 2;
        }
        break;
    case 2:
        idx = (cnt << 16) / 80;
        if (idx >= 0x10000)
            idx %= 0x10000;
        idx = (idx >> 4) * 2;
        r = ((80 - cnt) * 3 << 16) / 80;
        pos.x += FX_Mul(FX_SinCosTable_[idx + 1], r);
        pos.z += FX_Mul(FX_SinCosTable_[idx], r);
        func_0216D89C(o->obj, &pos);
        if (o->count >= 80)
            return 1;
        break;
    }
    return 0;
}




/*
 * Season change: walks every mon of a party and sets the form (field 0x6F)
 * of species 585 and 586 to the season index, registering each species once
 * with func_0200CFA0 when one of its members actually changed.
 */
void func_0216AAE4(void *sys, void *party, int season)
{
    u32 dex;
    int i;
    int n;
    int formA;
    int formB;
    int doneA;
    int doneB;

    dex = (u32)func_0200CA1C(sys);
    doneA = 0;
    doneB = 0;

    switch (season) {
    case 0:
        formA = 0;
        formB = 0;
        break;
    case 1:
        formA = 1;
        formB = 1;
        break;
    case 2:
        formA = 2;
        formB = 2;
        break;
    case 3:
        formA = 3;
        formB = 3;
        break;
    default:
        formA = 0;
        formB = 0;
        break;
    }

    n = func_0201AA18(party);
    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);
        int species = func_02017E1C(mon, 5, 0);
        int form = func_02017E1C(mon, 0x6F, 0);

        if (species == 585 && form != formA) {
            func_02017988(mon, formA);
            if (!doneA) {
                func_0200CFA0((struct Blk37 *)dex, mon);
                doneA = 1;
            }
        } else if (species == 586 && form != formB) {
            func_02017988(mon, formB);
            if (!doneB) {
                func_0200CFA0((struct Blk37 *)dex, mon);
                doneB = 1;
            }
        }
    }
}



int func_0216ABD8(int a0, int a1)
{
    int buf;
    int *pb;
    int k;
    u16 *p;
    int q;
    void *s;
    void *t;
    void *r;

    pb = &buf;
    k = func_02159B10((void *)a0, (void *)a1);
    p = func_02159AE8((void *)a0, (void *)a1);
    r = func_0216AED0((void *)a1, k);
    if (r != 0) {
        q = func_0216AF1C(a1, r, 4, pb);
        if (q != 0) {
            s = func_0215A5F4((void *)a1);
            t = func_0215A5DC((void *)a1);
            func_0215897C(s, func_0216AF74((int)t, (int)func_0201210C((void *)t), q, *pb, p, 4));
        }
    }
    return 1;
}



int func_0216AC40(int a0, int a1)
{
    void *w;
    void *h;
    u8 *e;
    int key;

    w = func_0215A5DC((void *)a1);
    h = func_0201210C((void *)w);
    func_02012138(w);
    e = (u8 *)func_021664CC(func_0215A5CC((void *)a1), w, (u32 *)(&key));
    if (e != 0) {
        func_0217C37C(h, key, e, ((Bits *)(e + 0x50))->lo, ((Bits *)(e + 0x50))->hi);
        func_020307B0(e);
    }
    return 0;
}



/*
 * Unblocked by matching func_0217C294 (ov018, EXACT; itself unblocked by
 * func_0216D63C): the +0026 call site now attests as `matched`.
 */
int func_0216AC90(int a0, int a1)
{
    int t4;
    int t5;
    void *t6;
    void *w;
    void *r;

t5 = a1 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216AC98:
t4 = a0 + 0;
a0 = t5 + 0;
    w = func_0215A5E4((void *)a0);
loc_0216ACA0:
    w = func_02012EBC(w);
loc_0216ACA4:
    t6 = func_0200E0B0(w);
loc_0216ACA8:
a0 = t5 + 0;
a1 = t4 + 0;
    r = func_0216AED0((void *)a0, a1);
loc_0216ACB2:
    if (r == 0) goto loc_0216ACC8;
loc_0216ACB6:
    a0 = func_0217C294(r);
loc_0216ACBA:
a1 = a0 + 0;
    a0 = func_0200E18C(t6, a1);
loc_0216ACC2:
a0 = t5 + 0;
    func_0216AF3C(a0);
loc_0216ACC8:
a0 = 0;
    return a0;}

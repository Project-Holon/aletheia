/*
 * file:     eventdata_system_p08.c
 * unit:     yes
 * function: func_02162C54, func_02162C84, func_02162CE8, func_02162D2C, func_02162D90, func_02162E00, func_02162E48, func_02162E9C, func_02162ECC, func_02162F0C, func_02162F74, func_02162FC8, func_02163010, func_02163028
 * address:  0x02162C54
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
 *   func_02162AA4  0x02162AA4  thumb  ov010
 *   func_0201441C 0x0201441C thumb
 *   func_0207C768 0x0207C768 arm
 *   func_0216D6F4  0x0216D6F4  thumb  ov010
 *   func_0219B414  0x0219B414  thumb  ov021
 *   func_0216D548  0x0216D548  thumb  ov010
 *   func_0216DA20  0x0216DA20  thumb  ov010
 *   func_021630F4  0x021630F4  thumb  ov010
 *   func_0216310C  0x0216310C  thumb  ov010
 *   func_02163130  0x02163130  thumb  ov010
 *   func_0216D57C  0x0216D57C  thumb  ov010
 *   func_02197EB4  0x02197EB4  thumb  ov021
 *   func_0216DB10  0x0216DB10  thumb  ov010
 *   func_02163090  0x02163090  thumb  ov010
 *   func_0219B41C  0x0219B41C  thumb  ov021
 *   func_0216D708  0x0216D708  thumb  ov010
 *   func_02163154  0x02163154  thumb  ov010
 *   func_02163188  0x02163188  thumb  ov010
 */
#include "../../matched/include/Obj18972.h"
#include "../../matched/include/Obj01639.h"
#include "../../matched/include/Obj04156.h"
#include "../../matched/include/Obj05891.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16_02162C54;

typedef unsigned int u32;

typedef short s16_02162C84;

struct Sub {
    s16_02162C84 f0;
    s16_02162C84 f2;
    s16_02162C84 f4;
    u16 f6;
    u16 f8;
};

struct Box {
    u16 pad0[4];
    struct Sub s;
};

typedef signed short   s16_02162CE8;

typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef struct {
    s16_02162CE8 x;
    s16_02162CE8 y;
    s16_02162CE8 z;
    u16 w;
    u16 h;
} Box_02162CE8;

typedef struct {
    u8 pad[8];
    Box_02162CE8 box;
} Obj;

typedef short s16_02162D2C;

struct Sub_02162D2C { s16_02162D2C f0, f2, f4; u16 f6, f8; };

struct Box_02162D2C { u16 pad0[3]; u16 f6; struct Sub_02162D2C s; };

typedef short s16_02162D90;

struct Sub_02162D90 { u16 f0; u16 f2; s16_02162D90 f4; u16 f6; u16 f8; u16 fa; };

struct Box_02162D90 { u16 pad0[4]; struct Sub_02162D90 s; };

struct Out { u16 f0; u8 f2; u8 f3; s16_02162D90 f4; u16 f6; };

typedef short s16_02162E00;

struct Sub_02162E00 {
    u16 f0;
    u16 f2;
    s16_02162E00 f4;
    u16 f6;
    u16 f8;
};

struct Box_02162E00 {
    u16 pad0[3];
    u16 f6;
    struct Sub_02162E00 s;
};

struct Q {
    u16 f0;
    u16 pad2;
    s16_02162E00 f4;
    u16 f6;
};

typedef int s32;

typedef s32 fx32;

typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct TrigPos {
    s32 x;              /* 0x08 */
    s32 z;              /* 0x0C */
    s32 y;              /* 0x10 */
} TrigPos;

typedef struct Trigger_02162E48 {
    u16 id;             /* 0x00 */
    u16 kind2;          /* 0x02 */
    u16 kind;           /* 0x04 */
    u16 mode;           /* 0x06 */
    TrigPos pos;        /* 0x08 */
} Trigger_02162E48;

typedef short s16_02162E9C;

typedef struct TrigCell {
    u16 a;              /* 0x08 */
    u16 b;              /* 0x0A */
    s16_02162E9C c;              /* 0x0C */
} TrigCell;

typedef struct Trigger_02162E9C {
    u16 id;             /* 0x00 */
    u16 kind2;          /* 0x02 */
    u16 kind;           /* 0x04 */
    u16 mode;           /* 0x06 */
    TrigCell cell;      /* 0x08 */
} Trigger_02162E9C;

typedef struct CellKey {
    u16 a;              /* 0x00 */
    u16 pad02;
    s16_02162E9C c;              /* 0x04 */
    u16 b;              /* 0x06 */
} CellKey;

typedef short s16_02162ECC;

typedef short s16_02162F0C;

typedef short s16_02162FC8;

extern u16 func_02162AA4(int q, int m, int a, int b, u16 n);
void func_02162C84(struct Box *b, int q, int *out);
extern u8 func_0201441C(int m);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_0216D6F4(void *a0);
extern int func_0219B414(int a);
extern u32 *func_0216D548(u32 *p, u32 v);
int func_02162D2C(const struct Box_02162D2C *b, const int *pos);
void func_02162D90(const struct Box_02162D90 *b, int q, struct Out *o);
int func_02162E00(struct Box_02162E00 *b, struct Q *q);
int func_02162E48(Trigger_02162E48 *t, const VecFx32 *pos);
int func_02162E9C(Trigger_02162E9C *t, const CellKey *k);
void func_02162ECC(const char *p, int *out);
int func_02162F0C(char *p, int *v);
int func_02162F74(char *p, int *v);
int func_02162FC8(char *p, u16 *v);
int func_02163010(u32 *a0, int a1);
/* * Unlabelled leaf (push {r3, r4} with no lr), reached through the ov010 * tail-call thunk func_02162A64. Blocker of ov061 func_021F388C. * The const on both pointers keeps the first ldrsh ahead of the base * copy; the lsrs needs the u32 casts. */ void func_02162CE8(const Obj *p, V3 *out);
extern int func_0216DA20(void *p, unsigned int v);
extern void func_021630F4();
extern void func_0216310C(char *p);
extern void func_02163130(char *p);
extern unsigned int func_0216D57C(void *p, unsigned int v);
extern void func_02197EB4(u32 a);
extern int func_0216DB10(void *a0);
extern int func_02163090();
extern int func_0219B41C();
extern void func_0216D708(void *a0);
extern void func_02163154(char *p);
extern void func_02163188(char *p);
/* * lever: case 0 falls through into default at the final shared return. */ int func_02162C54(u8 *p);
void func_02163028(void *a);



/*
 * lever: case 0 falls through into default at the final shared return.
 */
int func_02162C54(u8 *p)
{
    switch (p[4]) {
    case 1: return 0;
    case 2: return 1;
    case 3: return 2;
    case 4: return 3;
    case 0:
    default: return 1;
    }
}




void func_02162C84(struct Box *b, int q, int *out)
{
    struct Sub *s = &b->s;
    int m = func_02162C54((u8 *)b);
    out[0] = b->s.f0 << 12;
    out[1] = s->f2 << 12;
    out[2] = s->f4 << 12;
    if (s->f6 > 1) {
        out[0] += func_02162AA4(q, m, 0, 0, s->f6) << 16;
    } else if (s->f8 > 1) {
        out[2] += func_02162AA4(q, m, 0, 0, s->f8) << 16;
    }
}



/*
 * Unlabelled leaf (push {r3, r4} with no lr), reached through the ov010
 * tail-call thunk func_02162A64.  Blocker of ov061 func_021F388C.
 * The const on both pointers keeps the first ldrsh ahead of the base
 * copy; the lsrs needs the u32 casts.
 */
void func_02162CE8(const Obj *p, V3 *out)
{
    const Box_02162CE8 *b = &p->box;

    out->a = b->x << 12;
    out->b = b->y << 12;
    out->c = b->z << 12;
    if (b->w > 1) {
        out->a += ((u32)b->w >> 1) << 16;
    } else if (b->h > 1) {
        out->c += ((u32)b->h >> 1) << 16;
    }
}


/*
 * following: two-byte alignment padding at 02162D8E.
 * lever: assign the Sub pointer before the position loads; signed x0 has
 * the field's s16 width. Bounded permuter first closed this spelling.
 */
int func_02162D2C(const struct Box_02162D2C *b, const int *pos)
{
    const struct Sub_02162D2C *s;
    s16_02162D2C x0;
    int z;
    int y;
    int x;
    if ((int)(b->f6 == 1)) return 0;
    s = &b->s;
    x = pos[0] >> 12;
    y = pos[1] >> 12;
    z = pos[2] >> 12;
    x0 = b->s.f0;
    if (x0 <= x && x0 + (s->f6 - 1) * 16 >= x
        && s->f2 - 2 <= y && s->f2 + 2 >= y
        && s->f4 <= z && s->f4 + (s->f8 - 1) * 16 >= z)
        return 1;
    return 0;
}

/*
 * lever: const source pointer schedules fa between the signed load and output store.
 * following: two-byte alignment padding at 0x02162DFE.
 */
void func_02162D90(const struct Box_02162D90 *b, int q, struct Out *o)
{
    const struct Sub_02162D90 *s = &b->s;
    int m = func_02162C54((u8 *)b);
    u16 fa;
    o->f0 = b->s.f0;
    o->f2 = 1;
    o->f3 = func_0201441C(m);
    o->f4 = s->f4;
    fa = s->fa;
    o->f6 = s->f2;
    if (s->f8 > 1) {
        o->f4 = o->f4 + (s16_02162D90)func_02162AA4(q, m, 1, fa, s->f8);
    } else if (s->f6 > 1) {
        o->f6 = o->f6 + func_02162AA4(q, m, 1, fa, s->f6);
    }
}


int func_02162E00(struct Box_02162E00 *b, struct Q *q)
{
    struct Sub_02162E00 *s;
    if (b->f6 == 0)
        return 0;
    s = &b->s;
    if (s->f0 == q->f0 && s->f2 <= q->f6 && s->f2 + s->f6 > q->f6
        && s->f4 <= q->f4 && s->f4 + s->f8 > q->f4)
        return 1;
    return 0;
}


/*
 * Position trigger test: an entry of mode 0 matches when the grid cell of
 * pos equals (x, z) and its height is within 2 of the entry's.
 */
int func_02162E48(Trigger_02162E48 *t, const VecFx32 *pos)
{
    s32 gx;
    s32 gy;
    s32 gz;
    TrigPos *p;

    if (t->mode == 1)
        return 0;
    p = &t->pos;
    gz = (pos->z >> 4) / 4096;
    gy = pos->y >> 12;
    gx = (pos->x >> 4) / 4096;
    if (p->x == gx && p->z == gz && p->y - 2 <= gy && p->y + 2 > gy)
        return 1;
    return 0;
}


/*
 * Map-cell trigger test: an entry of mode 1 matches the three location
 * halfwords of p.
 */
int func_02162E9C(Trigger_02162E9C *t, const CellKey *k)
{
    TrigCell *c;

    if (t->mode == 0)
        return 0;
    c = &t->cell;
    if (c->a == k->a && c->b == k->b && c->c == k->c)
        return 1;
    return 0;
}

/*
 * lever: const source pointer hoists the last halfword load before the output store.
 */
void func_02162ECC(const char *p, int *out)
{
    const u16 *q = (const u16 *)(p + 10);
    int y, x, z;
    z = func_0207C768(q[3] << 16, 0x2000);
    z = ((unsigned)q[1] << 16) + z;
    y = ((const s16_02162ECC *)q)[4] << 12;
    x = func_0207C768(q[2] << 16, 0x2000);
    out[2] = z;
    out[0] = ((unsigned)((struct Obj18972 *)p)->fA << 16) + x;
    out[1] = y;
}


int func_02162F0C(char *p, int *v)
{
    u16 *q;
    int x, y, z;

    if (((struct Obj01639 *)p)->f8 == 1) {
        return 0;
    }
    q = (u16 *)(p + 10);
    x = (v[0] >> 4) / 0x1000;
    z = (v[2] >> 4) / 0x1000;
    y = v[1] >> 12;
    if (((struct Obj01639 *)p)->fA <= x && ((struct Obj01639 *)p)->fA + q[2] > x
        && q[1] <= z && q[1] + q[3] > z
        && ((s16_02162F0C *)q)[4] - 2 <= y && ((s16_02162F0C *)q)[4] + 2 > y) {
        return 1;
    }
    return 0;
}


int func_02162F74(char *p, int *v)
{
    u16 *q;
    int x, z;

    if (((struct Obj04156 *)p)->f8 == 1) {
        return 0;
    }
    q = (u16 *)(p + 10);
    x = (v[0] >> 4) / 0x1000;
    z = (v[2] >> 4) / 0x1000;
    if (((struct Obj04156 *)p)->fA <= x && ((struct Obj04156 *)p)->fA + q[2] > x
        && q[1] <= z && q[1] + q[3] > z) {
        return 1;
    }
    return 0;
}


int func_02162FC8(char *p, u16 *v)
{
    u16 *q;

    if (((struct Obj05891 *)p)->f8 == 0) {
        return 0;
    }
    q = (u16 *)(p + 10);
    if (((struct Obj05891 *)p)->fA == v[0] && q[1] <= v[3] && q[1] + q[3] > v[3]
        && ((s16_02162FC8 *)q)[2] <= ((s16_02162FC8 *)v)[2] && ((s16_02162FC8 *)q)[2] + q[4] > ((s16_02162FC8 *)v)[2]) {
        return 1;
    }
    return 0;
}


/*
 * Unblocked by the recursive MATCH unblocker: the +000A call targets
 * 0x0219B414, a labelless Thumb tail-call thunk in ov021 now matched in
 * src/matched/ov021_func_0219B414.c, so the site attests as `matched`.
 */
int func_02163010(u32 *a0, int a1)
{
    int t4;

t4 = (int)(a0 + 0);
    func_0216D6F4((void *)a0);
loc_02163018:
a0 = (u32 *)(t4 + 0);
    a0 = (u32 *)func_0219B414((int)a0);
loc_0216301E:
a0 = (u32 *)(t4 + 0);
a1 = 2;
    a0 = (u32 *)func_0216D548(a0, a1);
loc_02163026:
    return (int)a0;}


void func_02163028(void *a)
{
    int t = 2;

    if (func_0216DA20((void *)a, t) == 0) {
        func_021630F4(a);
        func_0216310C((char *)a);
        func_02163130((char *)a);
        if (func_0216D57C(a, t << 8) != 0) {
            func_02197EB4((u32)a);
        } else if (func_0216DB10((void *)a) == 0) {
            if (func_02163090(a) == 1) {
                if (func_0219B41C(a) == 0) {
                    func_0216D708((void *)a);
                }
            }
        }
        func_02163154((char *)a);
        func_02163188((char *)a);
    }
}

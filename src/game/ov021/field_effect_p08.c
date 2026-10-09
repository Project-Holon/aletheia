/*
 * file:     field_effect_p08.c
 * unit:     yes
 * function: func_021AAABC, func_021AAAF0, func_021AAB1C, func_021AAB48, func_021AAB54, func_021AAB74, func_021AABC4, func_021AABEC, func_021AABF4
 * address:  0x021AAABC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012A38  0x02012A38  thumb
 *   func_021ADB4C  0x021ADB4C  thumb
 *   func_021ADB5C  0x021ADB5C  thumb
 *   func_02188C9C  0x02188C9C  thumb
 *   func_021AAFC0  0x021AAFC0  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_02005728  0x02005728  thumb
 *   d_021D8E76     0x021D8E76  data  a1
 */
#include "../../matched/include/Obj19848.h"
#include "../../matched/include/Obj19849.h"
#include "../../matched/include/Obj18073.h"

struct BigObj;
struct Obj00020;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u8 pad[0xd];
    u8 lo : 4;
    u8 mid : 2;
    u8 hi : 2;
} Sub;

typedef struct {
    u8 pad[0x10];
    Sub sub;
} T_021AAABC;

typedef struct {
    char pad[0x5b4];
    int f5b4;
} D_021AAABC;

typedef struct {
    int pad[2];
    int f8;
    int fc;
    D_021AAABC *f10;
} S_021AAABC;

typedef unsigned int   u32;

typedef struct {
    u8 pad[0x1d];
    u8 lo : 4;
    u8 mid : 2;
    u8 hi : 2;
} T_021AAAF0;

typedef struct {
    u8 pad[0x10];
    Sub sub;
} T;

typedef struct Ent {
    unsigned short id;
    short x;
    short y;
    short z;
    unsigned long w;
    unsigned char b;
    unsigned char flags : 4;
    unsigned char f4 : 2;
    unsigned char f6 : 2;
} Ent;

typedef struct Self {
    void *ctx;
    char pad04[4];
    void *obj;
} Self;

typedef struct {
    char pad[0x5b8];
    u16 a;
} D_021AAB74;

typedef struct {
    int pad[3];
    u32 fc;
} S_021AAB74;

typedef signed int     s32;

typedef signed char    s8;

typedef signed short   s16;

struct Mon {
    u8 pad00[7];
    u8 lo : 7;
    u8 b7 : 1;
};

struct Ctx {
    void *f00;
    int f04;
    void *f08;
    struct Mon *f0C;
};

struct Area {
    s16 x;
    s16 y;
    s16 mx;
    s16 my;
    s16 bx;
    s16 by;
    u16 ox;
    u16 oy;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
};

extern T_021AAABC *func_02012A38(int a);
extern void func_021ADB4C(u32 a, int v);
extern void func_021ADB5C(int a, int b);
extern u16 func_02188C9C(u8 *p);
extern void func_021AAFC0(Self *self, int a, Ent *e);
extern u32 func_02082BCC(void *p, int v, unsigned long n);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_021A3074(u8 *p);
extern int func_0216D83C(void *o);
extern int func_0216D86C(void *o);
extern u32 func_02005728(u32 v);
void func_021AAABC(S_021AAABC *s);
void func_021AAAF0(S_021AAABC *s, int b);
void func_021AAB1C(S_021AAABC *s, int b);
u16 func_021AAB48(char *p);
void func_021AAB54(S_021AAABC *s);
void func_021AAB74(Self *self, int a);
int func_021AABC4(S_021AAB74 *s, D_021AAB74 *d);
void func_021AABEC(u8 *p);
void func_021AABF4(struct Ctx *ctx, void *unused, struct Area *a);
extern const s8 d_021D8E76[][4];




void func_021AAABC(S_021AAABC *s)
{
    Sub *b = &func_02012A38(s->f8)->sub;
    if (b->lo) {
        b->hi = 1;
        if (s->f10->f5b4 != 0) {
            func_021ADB4C(s->f10->f5b4, 1);
        }
    }
}





void func_021AAAF0(S_021AAABC *s, int b)
{
    T_021AAAF0 *t = (T_021AAAF0 *)func_02012A38((int)((const struct BigObj *)s->f8));
    D_021AAABC *d = s->f10;
    if (t->lo && d->f5b4 != 0) {
        func_021ADB4C(d->f5b4, b);
    }
}





void func_021AAB1C(S_021AAABC *s, int b)
{
    T_021AAAF0 *t = (T_021AAAF0 *)func_02012A38((int)((const struct BigObj *)s->f8));
    D_021AAABC *d = s->f10;
    if (t->lo && d->f5b4 != 0) {
        func_021ADB5C(d->f5b4, b);
    }
}




u16 func_021AAB48(char *p)
{
    return ((struct Obj19849 *)(*(char * *)&((struct Obj19848 *)p)->f10))->f5BC;
}




void func_021AAB54(S_021AAABC *s)
{
    Sub *b = &func_02012A38(s->f8)->sub;
    if (b->lo) {
        b->mid = 1;
    }
}



void func_021AAB74(Self *self, int a)
{
    Ent *e = (Ent *)((u32)func_02012A38((int)self->obj) + 0x10);
    unsigned short id;

    if (e->flags == 0 || e->f4 == 0)
        return;
    e->f4 = 0;
    id = func_02188C9C(self->ctx);
    if (id != e->id || e->f6 != 0)
        func_02082BCC(e, 0, 0x10);
    else
        func_021AAFC0(self, a, e);
}



int func_021AABC4(S_021AAB74 *s, D_021AAB74 *d)
{
    u32 *c = &s->fc;
    if (*c < 0xffffffff) {
        (*c)++;
    }
    if (*c >= d->a) {
        return 1;
    }
    return 0;
}



/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_021AABEC(u8 *p)
{
    ((struct Obj18073 *)p)->fC = 0;
}



/*
 * Addresses are Black-image addresses.
 */
void func_021AABF4(struct Ctx *ctx, void *unused, struct Area *a)
{
    void *o = func_021A3074(func_02188CB4(ctx->f00));
    const s8 *t;
    s16 x0;
    s16 x1;
    s16 y0;
    s16 y1;

    a->x = func_0216D83C(o);
    a->y = func_0216D86C(o);
    a->mx = a->x % 32;
    a->my = a->y % 32;
    a->bx = a->x / 32;
    a->by = a->y / 32;
    a->ox = a->x - a->mx;
    a->oy = a->y - a->my;
    if (ctx->f0C->lo != 2)
        t = d_021D8E76[func_02005728(4) + 1];
    else
        t = d_021D8E76[0];
    x0 = a->mx + t[0];
    if (x0 < 0)
        x0 = 0;
    x1 = a->mx + t[1];
    if (x1 >= 32)
        x1 = 31;
    y0 = a->my + t[2];
    if (y0 < 0)
        y0 = 0;
    y1 = a->my + t[3];
    if (y1 >= 32)
        y1 = 31;
    a->x0 = x0 + a->ox;
    a->x1 = x1 + a->ox;
    a->y0 = y0 + a->oy;
    a->y1 = y1 + a->oy;
}

/*
 * file:     field_place_name_p06.c
 * unit:     yes
 * function: func_021BD430, func_021BD474, func_021BD47C, func_021BD484, func_021BD554, func_021BD57C, func_021BD588, func_021BD5D4, func_021BD5F8, func_021BD604, func_021BD648, func_021BD6C0, func_021BD704, func_021BD734, func_021BD7A8, func_021BD7E0, func_021BD874, func_021BD8C0
 * address:  0x021BD430
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
 *   func_021BD394  0x021BD394  thumb  ov021
 *   _fdiv          0x0209CE10  arm
 *   _fadd          0x0209C95C  arm
 *   _fmul  0x0209C77C  arm
 *   _fsub  0x0209CB8C  arm
 *   _ffix  0x0209C494  arm
 *   _fneq  0x0209BCD0  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021BD2C8  0x021BD2C8  thumb  ov021
 *   func_02045A98  0x02045A98  arm
 *   func_020457B0  0x020457B0  arm
 *   func_02045994  0x02045994  arm
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_020257D0  0x020257D0  thumb
 *   func_02045808  0x02045808  arm
 *   func_021BD304  0x021BD304  thumb  ov021
 *   func_02025774  0x02025774  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_0201D42C  0x0201D42C  thumb
 *   d_021D9BB0     0x021D9BB0  data  ov021  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021BD94C  0x021BD94C  thumb  ov021
 *   func_021BD988  0x021BD988  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_021A7E3C  0x021A7E3C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021BD96C  0x021BD96C  thumb  ov021
 *   func_02161B1C  0x02161B1C  thumb  ov010
 *   func_02161B74  0x02161B74  thumb  ov010
 *   func_021BFE00  0x021BFE00  thumb  ov021
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_0218F0F8  0x0218F0F8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BD904  0x021BD904  thumb  ov021
 *   func_021BD93C  0x021BD93C  thumb  ov021
 *   func_02029E08  0x02029E08  thumb
 *   func_02029DFC  0x02029DFC  thumb
 */
#include "../../matched/include/Obj18232.h"
#include "../../matched/include/Obj18234.h"
#include "../../matched/include/Obj02719.h"
#include "../../matched/include/Obj18235.h"
#include "../../matched/include/Obj20132.h"
#include "../../matched/include/Obj12883.h"
#include "../../matched/include/Obj03588.h"
#include "../../matched/include/Obj12889.h"

struct CharBuf;
struct Obj;
struct U16Vec;
struct Strbuf;
struct StrObj;
struct Desc;
struct Args;
struct Evt;
typedef struct {
    char pad00[4];
    float f04;
    char pad08[4];
    float f0c;
    char pad10[4];
    float f14;
    char pad18[4];
    float f1c;
    char pad20[0xc];
    int f2c;
} T;

typedef struct {
    char pad00[0x10];
    T t;
} S;

typedef struct {
    char pad[0x44];
    int f44;
} Obj_021BD474;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    float f0;
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    float f24;
    int f28;
    int f2C;
} Sub;

typedef struct {
    float f0;
    float f4;
    float f8;
    float fC;
    Sub s;
} Obj_021BD484;

typedef struct {
    int x, y;
} V2;

typedef struct {
    int a, b, c, d, e, f;
    V2 g;
} Src;

typedef struct {
    char pad[0x10];
    int a, b, c, d;
    char pad2[8];
    int e, f;
    V2 g;
} Obj_021BD554;

typedef short s16;

typedef struct {
    float f0;
    float f4;
} Q;

typedef struct {
    char pad[0xC];
    void *fC;
} Obj_021BD5D4;

typedef struct {
    void *f[6];
} Tbl;

typedef struct {
    int f00;
    void *f04;
    char pad08[8];
    unsigned int f10;
} Arg;

typedef struct {
    int f00;
    int f04;
    Arg *f08;
} Work;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0C;
} Cfg;

typedef struct {
    u32 f00;
    u32 f04;
    Cfg *cfg;
} Ctx;

typedef struct {
    char pad[8];
    void *f8;
    char pad2[0x14];
    u16 h20;
    char pad3[0x23];
    u8 b45;
    char pad4[2];
    int f48;
} Inner_021BD904;

typedef struct {
    char pad[8];
    Inner_021BD904 *f8;
} Obj_021BD93C;

typedef struct {
    char pad[4];
    void *f4;
    char pad2[0x44];
    int f4C;
} Inner_021BD96C;

typedef struct {
    char pad[8];
    Inner_021BD96C *f8;
} Obj_021BD96C;

typedef struct {
    u32 x0;
    u32 x4;
    u8 pad8[0x10];
    u16 h18;
    u8 pad1a[6];
    u16 h20;
} Ent;

typedef struct {
    u32 x0;
    u32 x4;
    Ent *e;
} Obj_021BD904;

extern int func_021BD394(void *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern u16 func_021BD2C8(u8 *p);
extern u16 func_02045A98(void);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *a, const u16 *b, u32 c);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_020257D0(struct Obj *o);
extern void func_02045808(struct U16Vec *vec);
extern u8 *func_021BD304(u8 *p);
extern void func_0202590C(void *a, int b, int c);
extern void func_02025774(u8 *g, unsigned int a);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_021BD94C(Obj_021BD93C *p);
extern void func_021BD988(u32 *, u32);
extern void func_020061E4(u32);
extern void *func_021A7E3C(struct Args *a);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_021BD96C(Obj_021BD96C *p, void *b);
extern int func_02161B1C(void *a);
extern int func_02161B74(int a0);
extern void *func_021BFE00(int a0, void *p, int a2);
extern void *func_02188C58(void *p);
extern int func_0218F0F8(u8 *a);
extern u32 func_0218F0E8(u8 *a);
extern void func_0218F0A8(u8 *a);
extern void func_0218EC54(u8 *p);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BD904(Obj_021BD904 *o);
extern int func_021BD93C(u32 *);
extern int func_02029E08(int a0, int a1);
extern void *func_02029DFC(const void *p);
void func_021BD430(S *p);
void func_021BD474(Obj_021BD474 *p);
void func_021BD47C(u8 *p);
void func_021BD484(Obj_021BD484 *obj);
void func_021BD554(Obj_021BD554 *p, Src *s);
void func_021BD57C(u8 *p);
void func_021BD588(u32 *p);
void func_021BD5D4(Obj_021BD5D4 *p);
void func_021BD5F8(void *p, unsigned int a);
void func_021BD604(u32 a, u16 b, u32 c, u8 *d, u8 *e);
void *func_021BD648(Arg *p);
u32 func_021BD6C0(u32 a, int *st, u32 *ctx);
int func_021BD704(u32 a, int *st, u32 *ctx);
u32 func_021BD734(u32 a, int *st, u32 *ctx);
int func_021BD7A8(void *task, u32 *state, Ctx *ctx);
u32 func_021BD7E0(u32 a, int *st, u32 *ctx);
u32 func_021BD874(u32 a, int *st, u32 *ctx);
u32 func_021BD8C0(u32 *ctx);
extern Tbl d_021D9BB0;



void func_021BD430(S *p)
{
    T *q;

    if (func_021BD394(p) == 1) {
        return;
    }
    q = &p->t;
    q->f04 = q->f04 + (q->f0c + q->f14 / 2.0f);
    q->f0c = q->f0c + q->f14;
    q->f2c = q->f2c - 1;
    if (q->f2c == 0) {
        q->f04 = q->f1c;
    }
}




void func_021BD474(Obj_021BD474 *p)
{
    p->f44 = 1;
}




void func_021BD47C(u8 *p)
{
    ((struct Obj18232 *)p)->f44 = 0;
}




void func_021BD484(Obj_021BD484 *obj)
{
    float dx;
    float dy;
    Sub *s;

    s = &obj->s;
    dx = s->f18 - obj->s.f0;
    dy = s->f1C - s->f4;

    if (dx != 0.0f) {
        s->f10 = (s->f20 * s->f20 - s->f8 * s->f8) / (2.0f * dx);
    }
    if (dy != 0.0f) {
        s->f14 = (s->f24 * s->f24 - s->fC * s->fC) / (2.0f * dy);
    }
    if (s->f10 != 0.0f) {
        s->f28 = (s->f20 - s->f8) / s->f10;
    }
    if (s->f14 != 0.0f) {
        s->f2C = (s->f24 - s->fC) / s->f14;
    }
}






void func_021BD554(Obj_021BD554 *p, Src *s)
{
    p->a = s->a;
    p->b = s->b;
    p->c = s->c;
    p->d = s->d;
    p->e = s->e;
    p->f = s->f;
    p->g = s->g;
    func_021BD484((Obj_021BD484 *)p);
}






/*
 * Tail call on the word at +8 with a zero second argument.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD57C(u8 *p)
{
    func_02043B5C((struct CharBuf *)(((struct Obj18234 *)p)->f8), 0);
}






void func_021BD588(u32 *p)
{
    u16 buf[2];
    u32 h;

    buf[0] = func_021BD2C8((u8 *)p);
    buf[1] = func_02045A98();
    h = (u32)func_020457B0(2, ((struct Obj02719 *)p)->f0);
    func_02045994((struct Strbuf *)h, buf, 2);
    func_0201C7D0((void *)p[2], 0, 0, (void *)h, (void *)p[1], 0x440);
    func_020257D0((struct Obj *)p[3]);
    func_02045808((struct U16Vec *)h);
}






void func_021BD5D4(Obj_021BD5D4 *p)
{
    Q *q = (Q *)func_021BD304((u8 *)p);
    int x = (int)q->f0;
    int y = (int)q->f4;

    func_0202590C(p->fC, x, y);
}






/*
 * Tail-call thunk: the object's word at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void func_021BD5F8(void *p, unsigned int a)
{
func_02025774((u8 *)((struct Obj18235 *)p)->fC, a);
}






void func_021BD604(u32 a, u16 b, u32 c, u8 *d, u8 *e)
{
    u16 buf[2];
    u32 h;

    buf[0] = b;
    buf[1] = func_02045A98();
    h = (u32)func_020457B0(2, c);
    func_02045994((struct Strbuf *)h, buf, 2);
    *d = func_0201D304((struct StrObj *)h, a, 0);
    *e = func_0201D42C((struct StrObj *)h, (void *)a);
    func_02045808((struct U16Vec *)h);
}






void *func_021BD648(Arg *p)
{
    Tbl t = d_021D9BB0;
    int i;
    void *task;
    Work *w;

    switch (p->f10) {
    case 0:
        i = 0;
        break;
    case 1:
        i = 0;
        break;
    case 2:
        i = 2;
        break;
    case 3:
        i = 1;
        break;
    case 4:
        i = 2;
        break;
    case 5:
        i = 3;
        break;
    case 6:
        i = 5;
        break;
    default:
        i = 4;
        break;
    }
    task = func_020122C0(p->f04, (void *)p->f00, t.f[i], 12);
    w = func_020124E8(task);
    w->f04 = 0;
    w->f08 = p;
    return task;
}






/*
 * Addresses are Black-image addresses.
 */
u32 func_021BD6C0(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];

    switch (*st) {
    case 0:
        func_021BD94C((Obj_021BD93C *)ctx);
        if (((struct Obj20132 *)p)->f38 != 2)
            func_020061E4(0x559);
        func_021BD988(ctx, a);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}






int func_021BD704(u32 a, int *st, u32 *ctx)
{
    u32 p = ctx[2];

    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, func_021A7E3C((struct Args *)p));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}






u32 func_021BD734(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 x = ((struct Obj12883 *)p)->fC;

    switch (*st) {
    case 0:
        if (func_021BD8C0(ctx))
            func_021BD96C((Obj_021BD96C *)ctx, (void *)a);
        else
            func_021BD94C((Obj_021BD93C *)ctx);
        ctx[1] = func_02161B1C((void *)x);
        (*st)++;
        break;
    case 1:
        if (func_02161B74(ctx[1])) {
            if (((struct Obj12883 *)p)->f38 != 2)
                func_020061E4(0x559);
            func_021BD988(ctx, a);
            (*st)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}





int func_021BD7A8(void *task, u32 *state, Ctx *ctx)
{
    Cfg *cfg = ctx->cfg;
    u32 x = cfg->f04;
    u32 y = cfg->f0C;

    switch (*state) {
    case 0:
        func_02012374(task, func_021BFE00(0, (void *)x, y));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}





u32 func_021BD7E0(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 h = (u32)func_02188C58((void *)(*(u32 *)&((struct Obj03588 *)p)->fC));

    switch (*st) {
    case 0:
        if (func_0218F0F8((u8 *)h) && func_0218F0E8((u8 *)h)) {
            func_0218F0A8((u8 *)h);
            *st = 1;
        } else {
            *st = 2;
        }
        return 0x21;
    case 1:
        if (!func_0218F0F8((u8 *)h)) {
            *st = 2;
            return 0x21;
        }
        if (func_0218F0E8((u8 *)h))
            break;
        func_0218EC54((u8 *)h);
        *st = 2;
        return 0x21;
    case 2:
        func_02012374((struct Evt *)a, func_021A7E3C((struct Args *)((u32)p)));
        *st = 3;
        return 0x21;
    case 3:
        return 1;
    }
    return 0;
}





u32 func_021BD874(u32 a, int *st, u32 *ctx)
{
    u32 *p = (u32 *)ctx[2];
    u32 x = p[1];
    u32 y = p[3];

    switch (*st) {
    case 0:
        func_021BD94C((Obj_021BD93C *)ctx);
        func_020061E4(0x737);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE8D4((void *)x, y, 2, 0));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}



u32 func_021BD8C0(u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 q = ((struct Obj12889 *)p)->f8;

    if (!func_021BD904((Obj_021BD904 *)ctx))
        return 0;
    if (func_02029E08(q, ((struct Obj12889 *)p)->f20))
        return 0;
    if (func_021BD93C(ctx) == 1 && (u32)func_02029DFC((const void *)q) == 0x3F4)
        return 0;
    return 1;
}

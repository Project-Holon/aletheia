/*
 * file:     event_field_proclink_p04.c
 * unit:     yes
 * function: func_0215EF60, func_0215EFCC, func_0215EFF4, func_0215F060, func_0215F088, func_0215F0B8, func_0215F0E8, func_0215F104
 * address:  0x0215EF60
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
 *   func_020120F4  0x020120F4  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02158780  0x02158780  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_021587B0  0x021587B0  thumb  ov010
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02013FFC 0x02013FFC thumb
 *   d_02171258 0x02171258 data a4
 *   d_02171200 0x02171200 data a4
 *   d_02171254 0x02171254 data a4
 *   d_021711FC 0x021711FC data a4
 */
#include "../../matched/include/Obj02057.h"
#include "../../matched/include/Obj17701.h"

struct BigObj;
struct Ctx;
struct C;
struct Desc;
struct Obj;
struct Pair;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct C {
    u8 pad00[8];
    void *f8;
    u16 fc;
};

typedef struct Pair { u32 a, b; } Pair;

extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_0201210C(const struct Ctx *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02158780(void *a, u32 id, u32 b, u32 c, u32 d);
extern int func_02159058(int a, int b, int c, int d, u16 e);
extern int func_021587B0(int a0, int a1, int a2, int a3);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02013FFC(u32 id);
int func_0215EF60(void *a, int *st, struct C *c);
void *func_0215EFCC(void *p, void *ctx);
int func_0215EFF4(void *a, int *st, struct C *c);
void *func_0215F060(void *p, void *ctx);
int func_0215F088(u16 *p, int i);
int func_0215F0B8(u16 *p, int i);
void func_0215F0E8(u32 *out, const Pair *in, u32 *ctx);
int func_0215F104(int a0, int a1);
extern int d_02171258[];
extern int d_02171200[];
extern int d_02171254[];
extern int d_021711FC[];


int func_0215EF60(void *a, int *st, struct C *c)
{
    u32 h;
    u32 x;
    void *t;

    func_0201296C(func_020120F4(c->f8));
    x = func_02188C84(func_0201210C(c->f8));
    switch (*st) {
    case 0:
        h = c->fc;
        t = func_02158780(a, 0x271e, 0, 0, x);
        func_02159058((int)t, h, 0, 0, 0);
        *st = *st + 1;
        break;
    case 1:
        func_021587B0((int)a, 0x28e3, 0, 0);
        break;
    }
    return 0;
}

void *func_0215EFCC(void *p, void *ctx)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)ctx)->f8, 0, (void *)func_0215EF60, 20);
    func_0215F0E8(func_020124E8(task), p, ctx);
    return task;
}


int func_0215EFF4(void *a, int *st, struct C *c)
{
    u32 h;
    u32 x;
    void *t;

    func_0201296C(func_020120F4(c->f8));
    x = func_02188C84(func_0201210C(c->f8));
    switch (*st) {
    case 0:
        h = c->fc;
        t = func_02158780(a, 0x271d, 0, 0, x);
        func_02159058((int)t, h, 0, 0, 0);
        *st = *st + 1;
        break;
    case 1:
        func_021587B0((int)a, 0x28e2, 0, 0);
        break;
    }
    return 0;
}

void *func_0215F060(void *p, void *ctx)
{
    void *task;
    task = func_020122C0(((struct Obj02057 *)ctx)->f8, 0, (void *)func_0215EFF4, 20);
    func_0215F0E8(func_020124E8(task), p, ctx);
    return task;
}

int func_0215F088(u16 *p, int i)
{
    if (i >= 11) return 0;
    if (func_02013FFC(*p)) return *(int *)((u32)d_02171258 + ((u32)i << 3));
    return *(int *)((u32)d_02171200 + ((u32)i << 3));
}

int func_0215F0B8(u16 *p, int i)
{
    if (i >= 11) return 0;
    if (func_02013FFC(*p)) return *(int *)((u32)d_02171254 + ((u32)i << 3));
    return *(int *)((u32)d_021711FC + ((u32)i << 3));
}

void func_0215F0E8(u32 *out, const Pair *in, u32 *ctx) { out[0] = 0x19740205; out[1] = ctx[3]; *(Pair *)(out+3) = *in; out[2] = ctx[2]; }




int func_0215F104(int a0, int a1)
{
    int a2;
    int a3;

a3 = ((struct Obj17701 *)a0)->f2;
a2 = 1;
a2 = a2 << a1;
a1 = a3 + 0;
a0 = 1;
    if ((a1 & a2) != 0) goto loc_0215F114;
loc_0215F112:
a0 = 0;
loc_0215F114:
    return a0;}

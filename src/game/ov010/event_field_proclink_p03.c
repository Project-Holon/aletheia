/*
 * file:     event_field_proclink_p03.c
 * unit:     yes
 * function: func_0215EF60, func_0215EFCC, func_0215EFF4, func_0215F060, func_0215F088, func_0215F0B8, func_0215F0E8, func_0215F104, func_0215F118, func_0215F168, func_0215F1C8, func_0215F214, func_0215F228, func_0215F238, func_0215F280
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
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020142E8  0x020142E8  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_02189734  0x02189734  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   d_0217294C     0x0217294C  data  ov010  a4
 *   func_020113D0  0x020113D0  thumb
 *   func_0202EB44  0x0202EB44  thumb
 *   func_020121CC  0x020121CC  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_0201213C  0x0201213C  thumb
 *   func_02159144  0x02159144  thumb  ov010
 *   func_02159168   0x02159168  thumb  ov010
 */
#include "../../matched/include/Obj02057.h"
#include "../../matched/include/Obj17701.h"
#include "../../matched/include/Obj00005.h"
#include "../../matched/include/Obj17702.h"
#include "../../matched/include/Obj17703.h"

struct BigObj;
struct Ctx;
struct C;
struct Desc;
struct Obj;
struct Pair;
struct IcaAnime;
struct Comm;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct C {
    u8 pad00[8];
    void *f8;
    u16 fc;
};

typedef struct Pair { u32 a, b; } Pair;

typedef struct Area {
    u16 x;              /* 0x00 */
    u16 z;              /* 0x02 */
    u16 w;              /* 0x04 */
    u16 h;              /* 0x06 */
} Area;

typedef signed int     s32;

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
extern void *func_02188C80(void *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_02158FB4(void *p);
extern int func_02189734();
extern int func_020307B0();
extern u16 *func_02159AE8(void *a, void *b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_020113D0(char *p, int val);
extern int func_0202EB44();
/* * Inside test of (x, z) against an Area's half extents, refused when the * flag is already set in the field's save block. */ int func_0215F118(const Area *a, u16 x, u16 z, u32 flag, void *field);
int func_0215F168(int a0, int a1);
int func_0215F1C8(void *a, void *b);
/* * blocked: listing 20 compiled 18 */ int func_0215F214(int a0, int a1);
extern u32 func_020121CC(struct IcaAnime *p);
extern u32 func_02026454(void *obj);
extern void func_02026400(struct Comm *p);
extern void func_0201213C(struct Ctx *p, u32 v);
extern void func_02159144(int v);
int func_0215F228(int a0, int a1);
int func_0215F238(void *a, void *b);
extern void func_02159168(int);
int func_0215F280(void *a0, void *a1);
extern int d_02171258[];
extern int d_02171200[];
extern int d_02171254[];
extern int d_021711FC[];
extern const char d_0217294C[];





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



/*
 * Inside test of (x, z) against an Area's half extents, refused when the
 * flag is already set in the field's save block.
 */
int func_0215F118(const Area *a, u16 x, u16 z, u32 flag, void *field)
{
    int dx;
    int dz;

    if (func_020142E8((void *)func_0201296C(func_020120F4(func_02188C80(field))), flag) != 0)
        return 0;
    dx = a->x - x;
    dz = a->z - z;
    if (dx < 0)
        dx = -dx;
    if (dx < a->w) {
        if (dz < 0)
            dz = -dz;
        if (dz < a->h)
            return 1;
    }
    return 0;
}



int func_0215F168(int a0, int a1)
{
    int t4;
    int t6;
    void *p;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215F172:
a0 = t4 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_0215F17A:
    a0 = func_02012138(v0);
loc_0215F182:
t6 = a0 + 0;
    v2 = func_0201210C(v0);
loc_0215F18A:
    p = func_02158FB4(v1);
loc_0215F190:
t4 = ((struct Obj17702 *)((char *)p))->f0;
a0 = t6 + 0;
    a0 = func_02189734(a0);
loc_0215F198:
    if (a0 == 0) goto loc_0215F1A6;
loc_0215F19C:
    if (a0 == 1) goto loc_0215F1AA;
loc_0215F1A0:
    if (a0 == 2) goto loc_0215F1B4;
loc_0215F1A4:
    goto loc_0215F1C4;
loc_0215F1A6:
a0 = 0;
    return a0;
loc_0215F1AA:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0215F1B0:
a0 = 1;
    return a0;
loc_0215F1B4:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
a1 = 2;
*(u16 *)&((struct Obj00005 *)((char *)a0))->f0 = a1;
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0215F1C0:
a0 = 1;
    return a0;
loc_0215F1C4:
a0 = 0;
    return a0;}



int func_0215F1C8(void *a, void *b)
{
    void **slot;
    u16 *w;
    void **p;

    slot = func_02158FB4(func_0215A5F4(b));
    w = func_02159AE8(a, b);
    p = func_02030734(4, 4, 1, d_0217294C, 0x63);
    *slot = p;
    *p = w;
    *w = 0;
    func_020113D0(a, (int)func_0215F168);
    return 1;
}



/*
 * blocked:  listing 20 compiled 18
 */
int func_0215F214(int a0, int a1)
{    unsigned short *v0;

    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215F21A:
    a0 = func_0202EB44();
loc_0215F220:
((struct Obj17703 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}



int func_0215F228(int a0, int a1)
{
    void *v0;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215F230:
    a0 = func_020121CC(v0);
loc_0215F234:
a0 = 1;
    return a0;}



int func_0215F238(void *a, void *b)
{
    void *t;
    void *s;

    t = func_0215A5DC(b);
    s = (void *)func_02012138(t);
    switch (func_02026454(s)) {
    case 1:
    case 2:
    case 5:
        func_02026400(s);
        break;
    case 0:
    case 3:
    case 4:
        break;
    }
    func_0201213C(t, 1);
    func_02159144(0xb);
    return 1;
}


/*
 * Frame teardown on the handle the overlay index returned, then the
 * overlay's own mode setter.
 */
int func_0215F280(void *a0, void *a1)
{
    void *p = func_0215A5DC(a1);

    func_0201213C(p, 0);
    func_020121CC(p);
    func_02159168(0xB);

    return 1;
}

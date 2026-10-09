/*
 * file:     field_place_name_p10.c
 * unit:     yes
 * function: func_021BE068, func_021BE148, func_021BE158, func_021BE17C, func_021BE180, func_021BE184, func_021BE194, func_021BE1A0, func_021BE1B0, func_021BE1C4, func_021BE1DC, func_021BE218
 * address:  0x021BE068
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
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A7B08  0x021A7B08  thumb  ov021
 *   func_021A3038  0x021A3038  thumb  ov021
 *   func_0218FEA4  0x0218FEA4  thumb  ov021
 *   func_0218FE78  0x0218FE78  thumb  ov021
 *   func_0218FEC0  0x0218FEC0  thumb  ov021
 *   func_02048F4C  0x02048F4C  arm
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_0218EC90  0x0218EC90  thumb  ov021
 *   func_0218E104  0x0218E104  thumb  ov021
 *   func_0218EC60  0x0218EC60  thumb  ov021
 *   func_02162370  0x02162370  thumb
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3AC  0x0200B3AC  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   d_021D9D98     0x021D9D98  data  a4
 *   d_021D9CBC     0x021D9CBC  data  a4
 *   func_02034A5C  0x02034A5C  arm
 *   d_021D9BE0     0x021D9BE0  data  ov021  a4
 */
#include "../../matched/include/Obj18253.h"
#include "../../matched/include/Obj18254.h"
#include "../../matched/include/Obj18255.h"
#include "../../matched/include/Obj18256.h"
#include "../../matched/include/Obj09202.h"
#include "../../matched/include/Obj18257.h"

struct Obj00020;
struct V3;
struct VecFx32;
struct Big;
struct Ctx;
struct Rec94;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec;

typedef struct {
    u16 f04;
    u16 f06;
    int f08;
    Vec pos;
    Vec rot;
} In;

typedef struct {
    u32 f00;
    In  in;
    u8  sub[0x20];
    int f44;
    int f48;
} S;

typedef struct {
    u32 obj;
    u32 f04;
    S   s;
    u32 f54;
    u32 pad58[4];
    u32 f68;
    u32 f6C;
} A;

typedef struct {
    int f00, f04, f08, f0C, f10;
    Vec v1;
    Vec v2;
    int f2C, f30, f34, f38, f3C;
} Rec;

typedef signed short   s16;

typedef signed char    s8;

typedef struct {
    char pad[0x58];
    Vec v58;
} Obj;

typedef signed int     s32;

extern void *func_02188CB4(struct Obj00020 *p);
extern u16 func_021A3050(u8 *p);
extern void func_021A7B08(int a, struct V3 *b);
extern void func_021A3038(unsigned char *t, struct VecFx32 *v);
extern void func_0218FEA4(u32 p);
extern void func_0218FE78(u32 a, void *dst);
extern void func_0218FEC0(u8 *o);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void func_0218E104(u8 *a, u32 b);
extern void func_0218EC54(u8 *p);
extern int func_0218EC60(u32 a);
extern u32 func_0218EC90(u32, u32);
extern u32 func_02162370(u32);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32 func_0200B3AC(struct Rec94 *p);
extern int func_02034AC4(int);
extern void func_02034A5C(int handle);
void func_021BE068(A *a);
void func_021BE148(u32 a, int b);
int func_021BE158(u32 a, u32 b);
u32 func_021BE17C(u8 *p);
u8 *func_021BE180(u8 *p);
void func_021BE184(Obj *p, const Vec *v);
int func_021BE194(u32 a);
int func_021BE1A0(u32 a);
int func_021BE1B0(u32 a);
int func_021BE1C4(u32 a);
void func_021BE1DC(void *arg);
void func_021BE218(void *arg);
extern void *d_021D9D98[];



static inline void vset(Vec *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}



/*
 * Twin of func_021BDFB0 with the pose block at a+0xC instead of a+0x2C.
 * A function-scope In pointer is what keeps the else-arm copy's
 * destination as (s+4)+8 in a fresh register; &s->in.pos folds to s+0xC.
 * The two rot/pos Vec writes are VEC_Set-style inline setters (arguments
 * evaluated right to left). The EXACT* is the 2-byte pad after the pop.
 */
void func_021BE068(A *a)
{
    Vec v;
    Rec rec;
    void *t;
    S *s = &a->s;
    u8 *sub = s->sub;
    In *in = &s->in;
    u32 h = func_021BE17C((u8 *)a);

    t = func_02188CB4((struct Obj00020 *)a->obj);
    func_021A3050(t);
    func_021BE148((u32)(&rec), func_021BE194((u32)a));
    s->f48 = rec.f3C;
    s->f44 = rec.f38;
    a->f68 = rec.f30;
    a->f6C = rec.f34;
    if (a->f6C == 0)
        return;
    if (func_021BE1B0((u32)a) != 0)
        func_021A7B08(a->obj, (struct V3 *)(&v));
    else
        func_021A3038(t, (struct VecFx32 *)&v);
    if (s->f44 != 0 && func_021BE1B0((u32)a) != 0)
        func_021BE158(h, (u32)(&v));
    func_0218FEA4(a->f54);
    func_0218FE78(a->f04, sub);
    s->f00 = rec.f2C;
    in->f04 = rec.f04;
    in->f06 = rec.f08;
    in->f08 = rec.f0C << 12;
    vset(&in->rot, rec.v2.x << 12, rec.v2.y << 12, rec.v2.z << 12);
    if (rec.f10 != 0) {
        vset(&in->pos, rec.v1.x << 12, rec.v1.y << 12, rec.v1.z << 12);
    } else {
        in->pos = v;
    }
    if (a->f6C != 0)
        func_0218FEC0((u8 *)a->f54);
}




void func_021BE148(u32 a, int b)
{
    func_02048F4C((void *)a, 0xb3, b - 7);
}




int func_021BE158(u32 a, u32 b)
{
func_0218EC54((u8 *)a);
func_0218EC90(a, b);
func_0218E104((u8 *)a, 0);
return func_0218EC60(a);
}




u32 func_021BE17C(u8 *p)
{
    return ((struct Obj18253 *)p)->f4;
}




/*
 * Returns the object pointer advanced by 0x58 bytes.
 */
u8 *func_021BE180(u8 *p)
{
    return p + 0x58;
}



void func_021BE184(Obj *p, const Vec *v)
{
    p->v58 = *v;
}



/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BE194(u32 a)
{
return ((struct Obj18254 *)((u8 *)(func_021BE180((u8 *)a))))->f0;
}



/*
 * Promoted from src/pending/: the blocker this file named is filed.
 * func_02162370 (0x02162370) is a matched manifest entry, so the `matched`
 * class attests the bl site here and every concrete byte plus every
 * relocation field reproduces.
 *
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021BE1A0(u32 a)
{
return func_02162370(((struct Obj18255 *)((u8 *)(func_021BE180((u8 *)a))))->f0);
}



int func_021BE1B0(u32 a)
{
if (((struct Obj18256 *)((u8 *)(func_021BE180((u8 *)a))))->f8 == 0) {
    return 1;
}
return 0;
}



int func_021BE1C4(u32 a)
{
if (((struct Obj18257 *)((u8 *)(func_021BE180((u8 *)a))))->f4 == 0) {
    return ((struct Obj09202 *)((u8 *)(a)))->f68;
}
return ((struct Obj09202 *)((u8 *)(a)))->f6C;
}


extern void (*d_021D9CBC[])(void *);



void func_021BE1DC(void *arg)
{
    int i;

    i = func_0200B3AC((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(arg))));
    if (i != -1) {
        if (d_021D9D98[i] != 0) {
            func_02034AC4((int)d_021D9D98[i]);
        }
        d_021D9CBC[i](arg);
    }
}



extern void (*d_021D9BE0[])(void *);



void func_021BE218(void *arg)
{
    int i;

    i = func_0200B3AC((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80(arg))));
    if (i != -1) {
        if (d_021D9BE0[i] != 0) {
            d_021D9BE0[i](arg);
        }
        if (d_021D9D98[i] != 0) {
            func_02034A5C((int)d_021D9D98[i]);
        }
    }
}

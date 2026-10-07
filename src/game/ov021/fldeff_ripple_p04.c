/*
 * file:     fldeff_ripple_p04.c
 * unit:     yes
 * function: func_021C3B0C, func_021C3B2C, func_021C3BB0, func_021C3BCC, func_021C3BD4, func_021C3C04, func_021C3C30, func_021C3C5C, func_021C3C78, func_021C3C88, func_021C3D1C, func_021C3DA8, func_021C3DE4, func_021C3E38, func_021C3E64
 * address:  0x021C3B0C
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
 *   func_02017E1C  0x02017E1C  thumb
 *   d_021DA960     0x021DA960  data  ov021  a4
 *   func_02005728  0x02005728  thumb  ov021
 *   func_021C452C  0x021C452C  thumb  ov021
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   d_021DA930     0x021DA930  data  ov021  a4
 */
#include "../../matched/include/Obj00358.h"
#include "../../matched/include/Obj18303.h"
#include "../../matched/include/Obj09211.h"

struct Personal;
typedef unsigned int u32;

typedef struct { u32 a, b, c; } E;

typedef struct { E e[12]; } T;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

typedef struct { u32 v[6]; } T6;

typedef struct {
    u32 f0[0x16];
    u32 a[6];
    u32 b[6];
    u32 n;
} S;

extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern u32 func_02005728(u32 v);
extern u8 func_021C452C(u32 a, u32 b, u32 c, u32 d);
extern void *func_0201ADE4(u32 a, int b, u32 heap);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);
void func_021C3B0C(void *a, u32 *out);
void func_021C3B2C(u32 *p, u32 *q);
int func_021C3BB0(u32 a);
int func_021C3BCC(u32 a, u32 b);
void func_021C3BD4(void *a, u32 *out);
void func_021C3C04(void *a, u32 *out);
void func_021C3C30(void *a, u32 *out);
int func_021C3C5C(u32 a);
void func_021C3C78(void *a, u32 *out);
void func_021C3C88(u32 *p, u32 *q);
void func_021C3D1C(u32 *p, u32 *q, u32 d);
void func_021C3DA8(void **p, u32 *out);
void func_021C3DE4(u32 *a, u32 *p, u32 heap);
void func_021C3E38(u32 *p, u32 heap);
void func_021C3E64(u32 *p, S *q);
extern T d_021DA960;
extern const T6 d_021DA930;


/*
 * Manaphy parents produce Phione.
 */
void func_021C3B0C(void *a, u32 *out)
{
    if (func_02017E1C((void *)func_021C3BB0((u32)a), 5, 0) == 0x1EA)
        *out = 0x1E9;
}


void func_021C3B2C(u32 *p, u32 *q)
{
    T t = d_021DA960;
    int i;
    u32 r5, r3;
    u32 x = func_021C3BB0((u32)p);

    i = 0;
    func_02017E1C((void *)x, 5, 0);
    func_02017E1C((void *)x, 6, 0);
    r5 = func_02017E1C((void *)p[0], 6, 0);
    r3 = func_02017E1C((void *)p[1], 6, 0);
    for (; i < 12; i++) {
        if (*q == t.e[i].a && r5 != t.e[i].b && r3 != t.e[i].b) {
            *q = t.e[i].c;
            return;
        }
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C3BB0(u32 a)
{
if (func_02017E1C(((struct Obj00358 *)((u8 *)(a)))->f4, 5, 0) == 132) {
    return *(u32 *)&((struct Obj00358 *)((u8 *)(a)))->f0;
}
return *(u32 *)&((struct Obj00358 *)((u8 *)(a)))->f4;
}


int func_021C3BCC(u32 a, u32 b)
{
((struct Obj18303 *)((u8 *)(b)))->f4 = 0;
return 0;
}


/*
 * Copies the parent's form for species 0x1A6..0x1A7.
 */
void func_021C3BD4(void *a, u32 *out)
{
    void *mon = (void *)func_021C3C5C((u32)a);
    u32 sp = func_02017E1C(mon, 5, 0);

    if (sp - 0x1A6 <= 1)
        out[1] = func_02017E1C(mon, 0x6F, 0);
}


/*
 * Copies the parent's form for species 0x19C..0x19D.
 */
void func_021C3C04(void *a, u32 *out)
{
    void *mon = (void *)func_021C3C5C((u32)a);
    u32 sp = func_02017E1C(mon, 5, 0);

    if (sp - 0x19C <= 1)
        out[1] = func_02017E1C(mon, 0x6F, 0);
}


/*
 * Copies the parent's form for species 0x226.
 */
void func_021C3C30(void *a, u32 *out)
{
    void *mon = (void *)func_021C3C5C((u32)a);
    u32 sp = func_02017E1C(mon, 5, 0);

    if (sp == 0x226)
        out[1] = func_02017E1C(mon, 0x6F, 0);
}


int func_021C3C5C(u32 a)
{
if (func_02017E1C(((struct Obj09211 *)((u8 *)(a)))->f4, 5, 0) == 132) {
    return ((struct Obj09211 *)((u8 *)(a)))->f0;
}
return *(u32 *)&((struct Obj09211 *)((u8 *)(a)))->f4;
}


/*
 * Rolls the offspring nature (EXACT*: pad).
 */
void func_021C3C78(void *a, u32 *out)
{
    out[3] = func_02005728(0x19);
}


void func_021C3C88(u32 *p, u32 *q)
{
    int x, y;
    u32 s0, s1;

    x = 0;
    if (func_02017E1C((void *)p[0], 6, 0) == 0xe5)
        x = 1;
    y = 0;
    if (func_02017E1C((void *)p[1], 6, 0) == 0xe5)
        y = 1;
    s0 = func_02017E1C((void *)p[0], 0x70, 0);
    s1 = func_02017E1C((void *)p[1], 0x70, 0);
    if (x || y) {
        if (func_02005728(2) == 0)
            return;
    }
    if (x && y) {
        if (func_02005728(2) == 0) {
            q[3] = s0;
            q[0x14] = 1;
        } else {
            q[3] = s1;
            q[0x15] = 1;
        }
    } else if (x) {
        q[3] = s0;
        q[0x14] = 1;
    } else if (y) {
        q[3] = s1;
        q[0x15] = 1;
    }
}


void func_021C3D1C(u32 *p, u32 *q, u32 d)
{
    u32 a = func_02017E1C((void *)p[1], 5, 0);
    u32 b = func_02017E1C((void *)p[1], 0x6f, 0);
    u32 c = func_02017E1C((void *)p[1], 0xa, 0);
    u32 k = (u32)func_021C452C((u16)a, (u16)b, (u16)c, d);
    u32 r = func_02005728(100);

    switch (k) {
    default:
    case 0:
        if (r < 0x50)
            q[0x13] = 0;
        else
            q[0x13] = 1;
        return;
    case 1:
        if (r < 0x14)
            q[0x13] = 0;
        else
            q[0x13] = 1;
        return;
    case 2:
        if (r < 0x14)
            q[0x13] = 0;
        else if (r < 0x28)
            q[0x13] = 1;
        else
            q[0x13] = 2;
        return;
    }
}


/*
 * Sets the +0x4C flag by coin flip when a parent is species 0x84 (EXACT*: pad).
 */
void func_021C3DA8(void **p, u32 *out)
{
    u32 a = func_02017E1C(p[0], 5, 0);
    u32 b = func_02017E1C(p[1], 5, 0);

    if (a == 0x84 || b == 0x84) {
        if (func_02005728(2) == 0)
            out[19] = 0;
        else
            out[19] = 1;
    }
}


void func_021C3DE4(u32 *a, u32 *p, u32 heap)
{
    u32 s[3];
    u32 x = (u32)func_0201ADE4((u16)p[0], (u16)p[1], heap);

    s[0] = func_0201AE1C((const struct Personal *)x, 0x1a);
    s[1] = func_0201AE1C((const struct Personal *)x, 0x1b);
    s[2] = func_0201AE1C((const struct Personal *)x, 0x1c);
    func_0201AE14((void *)x);
    if (p[0x13] < 2) {
        p[4] = s[p[0x13]];
        if (p[4] == 0)
            p[4] = s[0];
    }
}


/*
 * Reads personal-data field 0x15 for the species/form pair (EXACT*: pad).
 */
void func_021C3E38(u32 *p, u32 heap)
{
    void *h = func_0201ADE4((u16)p[0], (u16)p[1], heap);
    u32 v = func_0201AE1C(h, 0x15);

    func_0201AE14(h);
    p[5] = v;
}


/*
 * The flag array at q+0x58 must be a struct member (q->a[ia]); spelled
 * q[0x16 + ia] the compiler folds 0x16 into the index and spills it.
 */
void func_021C3E64(u32 *p, S *q)
{
    T6 t;
    int fa;
    int fb;
    int ia;
    int ib;
    u32 a;
    u32 b;
    int i;

    fa = 0;
    fb = 0;
    a = func_02017E1C((void *)p[0], 6, 0);
    b = func_02017E1C((void *)p[1], 6, 0);
    t = d_021DA930;
    for (i = 0; i < 6; i++) {
        if (a == t.v[i]) {
            fa = 1;
            ia = i;
            break;
        }
    }
    for (i = 0; i < 6; i++) {
        if (b == t.v[i]) {
            fb = 1;
            ib = i;
            break;
        }
    }
    if (fa && fb) {
        if (func_02005728(2) == 0) {
            q->a[ia] = 1;
            q->n++;
        } else {
            q->b[ib] = 1;
            q->n++;
        }
    } else if (fa) {
        q->a[ia] = 1;
        q->n++;
    } else if (fb) {
        q->b[ib] = 1;
        q->n++;
    }
}

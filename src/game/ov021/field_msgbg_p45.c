/*
 * file:     field_msgbg_p45.c
 * unit:     yes
 * function: func_0218FD88, func_0218FDD4, func_0218FDF0, func_0218FE40
 * address:  0x0218FD88
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
 *   _s32_div_f  0x0209C0A4  arm
 */
#include "../../matched/include/Obj01491.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct { int x, y, z; } Vec3;

void func_0218FD88(Vec3 *p, Vec3 *q, u16 n, u16 d, Vec3 *out);
int func_0218FDD4(int *p, int *q, int n, int d);
u16 func_0218FDF0(u16 *a, u16 *b, s32 d, s32 n);
void func_0218FE40(u8 *a);


/*
 * n and d are u16 (the caller passes u16 fields): with int parameters the
 * scheduler hoists the third call's pointer bumps above the store of out->y.
 */
void func_0218FD88(Vec3 *p, Vec3 *q, u16 n, u16 d, Vec3 *out)
{
    if (n == 0)
        *out = *q;
    out->x = func_0218FDD4(&p->x, &q->x, n, d);
    out->y = func_0218FDD4(&p->y, &q->y, n, d);
    out->z = func_0218FDD4(&p->z, &q->z, n, d);
}


int func_0218FDD4(int *p, int *q, int n, int d)
{
    int x0 = *p;
    int x1 = *q;
    int diff;
    if (n == d)
        return x1;
    diff = x1 - x0;
    return x0 + diff * d / n;
}


/*
 * Addresses are Black-image addresses.
 */
u16 func_0218FDF0(u16 *a, u16 *b, s32 d, s32 n)
{
    u16 x, delta, rem;
    if (d == 0)
        return *b;
    x = *a;
    delta = *b - x;
    rem = 0x10000 - delta;
    if (delta <= rem)
        return x + (u16)(delta * n / d);
    return x - (u16)(rem * n / d);
}


void func_0218FE40(u8 *a)
{
    ((struct Obj01491 *)a)->f1AC = 0;
    ((struct Obj01491 *)a)->f1A8 = 0;
}

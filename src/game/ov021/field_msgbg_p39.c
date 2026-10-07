/*
 * file:     field_msgbg_p39.c
 * unit:     yes
 * function: func_0218EC30, func_0218EC54, func_0218EC5C, func_0218EC60, func_0218EC68, func_0218EC7C, func_0218EC90, func_0218ECB4, func_0218ECC4, func_0218ECD4, func_0218ECE4, func_0218ECF4, func_0218ED04, func_0218ED14, func_0218ED20, func_0218ED2C, func_0218ED34, func_0218ED3C, func_0218ED40, func_0218ED48, func_0218ED50, func_0218ED54, func_0218ED58, func_0218ED5C, func_0218ED64, func_0218ED9C, func_0218EEFC, func_0218EFD4
 * address:  0x0218EC30
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
 *   func_02048B20  0x02048B20  arm
 *   func_02048B0C  0x02048B0C  arm
 *   func_0218E610  0x0218E610  thumb  ov021
 *   FX_SinCosTable_  0x020A1B38  data
 *   _s32_div_f     0x0209C0A4  arm
 *   func_0218F050  0x0218F050  thumb ov021
 *   d_021DDA28  0x021DDA28  data  a4
 */
#include "../../matched/include/Obj01653.h"
#include "../../matched/include/Obj17907.h"
#include "../../matched/include/Obj17908.h"
#include "../../matched/include/Obj19562.h"
#include "../../matched/include/Obj19563.h"
#include "../../matched/include/Obj19564.h"
#include "../../matched/include/Obj19565.h"
#include "../../matched/include/Obj17909.h"
#include "../../matched/include/Obj17910.h"
#include "../../matched/include/Obj17911.h"
#include "../../matched/include/Obj17912.h"
#include "../../matched/include/Obj17913.h"
#include "../../matched/include/Obj17914.h"
#include "../../matched/include/Obj05979.h"
#include "../../matched/include/Obj12593.h"
#include "../../matched/include/Obj04202.h"
#include "../../matched/include/Obj19566.h"
#include "../../matched/include/Obj19567.h"

struct Light;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16;

typedef signed int     s32;

typedef struct { u32 a, b, c; } Vec3_0218EC30;

typedef struct { u32 a, b, c; } Vec3_0218EC90;

typedef struct { u32 a, b, c; } Vec3_0218ECB4;

typedef struct { u32 a, b, c; } Vec3_0218ECC4;

typedef struct { u32 a, b, c; } Vec3_0218ECD4;

typedef struct { u32 a, b, c; } Vec3_0218ECE4;

typedef struct { u32 a, b, c; } Vec3_0218ECF4;

typedef struct Vec_0218ED04 {
    int x, y, z;
} Vec_0218ED04;

typedef struct {
    int x;
    int y;
    int z;
} Vec_0218ED9C;

typedef struct {
    int n;
    int rd;
    int wr;
    int delay;
    int full;
    int keepX;
    int keepY;
    int keepZ;
    Vec_0218ED9C *a;
    Vec_0218ED9C *b;
    int on;
    int hold;
} Delay;

typedef struct { int x, y, z; } Vec3_0218EEFC;

typedef struct {
    int count;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 flag1;
    u32 flag2;
    u32 flag4;
    Vec3_0218EEFC *bufA;
    Vec3_0218EEFC *bufB;
    u32 unk28;
    u32 unk2C;
} Track;

extern void func_02048B60(struct Light *l, const u32 *in);
extern void func_02048B6C(struct Light *l, const u32 *in);
extern void func_02048B20(u32 a, u32 b);
extern void func_02048B0C(u32 h, void *out);
extern u32 func_0218E610(u32, u32, u32, u32);
extern void func_02048B80(struct Light *l, u32 v);
extern void func_02048B94(struct Light *l, u32 v);
extern int func_0218F050(u32 a);
extern void *func_02030734(u16 heap, u32 size, u32 flag, const void *file, u32 line);
extern u32 func_020307B0(void *p);
void func_0218EC30(u8 *a, const Vec3_0218EC30 *p);
void func_0218EC54(u8 *p);
u32 func_0218EC5C(u8 *p);
int func_0218EC60(u32 a);
void func_0218EC68(u8 *a, u32 first, ...);
void func_0218EC7C(u8 *a, u32 first, ...);
void func_0218EC90(u8 *a, const Vec3_0218EC90 *p);
void func_0218ECB4(u8 *a, Vec3_0218ECB4 *out);
void func_0218ECC4(u8 *a, Vec3_0218ECC4 *out);
void func_0218ECD4(u8 *a, const Vec3_0218ECD4 *p);
void func_0218ECE4(u8 *a, Vec3_0218ECE4 *out);
void func_0218ECF4(u8 *a, const Vec3_0218ECF4 *p);
void func_0218ED04(u8 *p, const Vec_0218ED04 *v);
void func_0218ED14(u8 *p, u32 q);
void func_0218ED20(void *p, void *out);
u16 func_0218ED2C(u8 *p);
void func_0218ED34(u8 *p, u16 v);
u8 *func_0218ED3C(u8 *p);
u16 func_0218ED40(u8 *p);
void func_0218ED48(u8 *p, u32 v);
u8 *func_0218ED50(u8 *p);
u32 func_0218ED54(u8 *p);
void func_0218ED58(u8 *p, u32 v);
int func_0218ED5C(u32 a, u32 b, u32 c, u32 d);
void func_0218ED64(u8 *a, u16 angle);
void func_0218ED9C(Delay *d, Vec_0218ED9C *inA, Vec_0218ED9C *inB, Vec_0218ED9C *outA, Vec_0218ED9C *outB);
void func_0218EEFC(int n, u32 x, u32 flags, u32 heap, void *a);
void func_0218EFD4(u8 *a);
extern s16 FX_SinCosTable_[];
extern const char d_021DDA28[];


void func_0218EC30(u8 *a, const Vec3_0218EC30 *p)
{
    *(const Vec3_0218EC30 * *)&((struct Obj01653 *)a)->f1C = p;
    *(Vec3_0218EC30 *)(a + 0x6c) = *p;
    *(Vec3_0218EC30 *)(a + 0x48) = *p;
}


/*
 * Pattern-generated from the ov021 family.
 *
 * Addresses are Black-image addresses.
 */
void func_0218EC54(u8 *p)
{
    ((struct Obj17907 *)p)->f1C = 0;
}


/*
 * Loads the 32-bit word at byte +0x1c of the object.
 */
u32 func_0218EC5C(u8 *p)
{
    return ((struct Obj17908 *)p)->f1C;
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_0218EC60(u32 a)
{
*(u32 *)&((struct Obj01653 *)((u8 *)(a)))->f1C = ((struct Obj01653 *)((u8 *)(a)))->f18;
return a;
}


void func_0218EC68(u8 *a, u32 first, ...)
{
    func_02048B60((struct Light *)(((struct Obj19562 *)a)->fC), &first);
}


void func_0218EC7C(u8 *a, u32 first, ...)
{
    func_02048B6C((struct Light *)(((struct Obj19563 *)a)->fC), &first);
}


void func_0218EC90(u8 *a, const Vec3_0218EC90 *p)
{
    *(Vec3_0218EC90 *)(a + 0x48) = *p;
    *(Vec3_0218EC90 *)(a + 0x6c) = *p;
}


void func_0218ECB4(u8 *a, Vec3_0218ECB4 *out)
{
    *out = *(Vec3_0218ECB4 *)(a + 0x48);
}


void func_0218ECC4(u8 *a, Vec3_0218ECC4 *out)
{
    *out = *(Vec3_0218ECC4 *)(a + 0x60);
}


void func_0218ECD4(u8 *a, const Vec3_0218ECD4 *p)
{
    *(Vec3_0218ECD4 *)(a + 0x60) = *p;
}


void func_0218ECE4(u8 *a, Vec3_0218ECE4 *out)
{
    *out = *(Vec3_0218ECE4 *)(a + 0x24);
}


void func_0218ECF4(u8 *a, const Vec3_0218ECF4 *p)
{
    *(Vec3_0218ECF4 *)(a + 0x24) = *p;
}


/*
 * Unlabelled leaf: copies a 12-byte vector into field 0x30 (setter twin of
 * func_0218ECF4 at 0x24). Blocker leaf of func_021D2D7C.
 */
void func_0218ED04(u8 *p, const Vec_0218ED04 *v)
{
    *(Vec_0218ED04 *)(p + 0x30) = *v;
}


/*
 * Unlabelled tail-call leaf: forwards field 0xc and the second argument.
 */
void func_0218ED14(u8 *p, u32 q)
{
    func_02048B20(((struct Obj19564 *)p)->fC, q);
}


/*
 * Unlabelled tail-call leaf: forwards the handle at +0xc to func_02048B0C.
 * Filed as the only unmatched callee of ov056 func_021F392C.
 */
void func_0218ED20(void *p, void *out)
{
    func_02048B0C(((struct Obj19565 *)p)->fC, out);
}


/*
 * Loads the halfword at byte +0x78 of the object.
 */
u16 func_0218ED2C(u8 *p)
{
    return ((struct Obj17909 *)p)->f78;
}


/*
 * Field setter at +0x78 through a displaced pointer.
 *
 * Addresses are Black-image addresses.
 */
void func_0218ED34(u8 *p, u16 v)
{
    ((struct Obj17910 *)p)->f78 = v;
}


/*
 * Returns the object pointer advanced by 0x84 bytes.
 */
u8 *func_0218ED3C(u8 *p)
{
    return p + 0x84;
}


/*
 * Loads the halfword at byte +0x7a of the object.
 */
u16 func_0218ED40(u8 *p)
{
    return ((struct Obj17911 *)p)->f7A;
}


/*
 * Field setter at +0x7a through a displaced pointer.
 *
 * Addresses are Black-image addresses.
 */
void func_0218ED48(u8 *p, u32 v)
{
    ((struct Obj17912 *)p)->f7A = v;
}


/*
 * Returns the object pointer advanced by 0x82 bytes.
 */
u8 *func_0218ED50(u8 *p)
{
    return p + 0x82;
}


/*
 * Loads the 32-bit word at byte +0x7c of the object.
 */
u32 func_0218ED54(u8 *p)
{
    return ((struct Obj17913 *)p)->f7C;
}


void func_0218ED58(u8 *p, u32 v)
{
    ((struct Obj17914 *)p)->f7C = v;
}


int func_0218ED5C(u32 a, u32 b, u32 c, u32 d)
{
return func_0218E610(a, b, c, d);
}


void func_0218ED64(u8 *a, u16 angle)
{
    ((struct Obj05979 *)a)->f80 = angle;
    func_02048B80((struct Light *)(((struct Obj05979 *)a)->fC), FX_SinCosTable_[(((struct Obj05979 *)a)->f80 >> 4) * 2]);
    func_02048B94((struct Light *)(((struct Obj05979 *)a)->fC), FX_SinCosTable_[(((struct Obj05979 *)a)->f80 >> 4) * 2 + 1]);
}


void func_0218ED9C(Delay *d, Vec_0218ED9C *inA, Vec_0218ED9C *inB, Vec_0218ED9C *outA, Vec_0218ED9C *outB)
{
    int rd;
    int wr;

    if (d == 0) {
        *outA = *inA;
        *outB = *inB;
        return;
    }
    if (d->on == 0) {
        *outA = *inA;
        *outB = *inB;
        return;
    }
    rd = d->rd;
    wr = d->wr;
    if (d->hold == 0) {
        d->a[wr] = *inA;
        d->b[wr] = *inB;
        wr = (wr + 1) % d->n;
    }
    if (d->full != 0) {
        *outA = d->a[rd];
        *outB = d->b[rd];
    } else {
        *outA = d->a[d->delay];
        *outB = d->b[d->delay];
        if (rd == d->delay)
            d->full = 1;
    }
    if (d->hold != 0) {
        if (rd != wr) {
            rd = (rd + 1) % d->n;
            if (rd == wr)
                func_0218F050((u32)d);
        }
    } else {
        rd = (rd + 1) % d->n;
    }
    d->rd = rd;
    d->wr = wr;
    if (d->keepX == 0) {
        outA->x = inA->x;
        outB->x = inB->x;
    }
    if (d->keepY == 0) {
        outA->y = inA->y;
        outB->y = inB->y;
    }
    if (d->keepZ == 0) {
        outA->z = inA->z;
        outB->z = inB->z;
    }
}


/*
 * The fifth (stack) parameter is a void pointer reassigned to the address of
 * its +0xec slot before the store: the cast keeps it a live variable homed in
 * its own parameter slot (entry write-back, end adds/str).
 */
void func_0218EEFC(int n, u32 x, u32 flags, u32 heap, void *a)
{
    if (((struct Obj12593 *)a)->f1C != 0) {
        int i = 0;
        Track *t = func_02030734(heap, sizeof(Track), 0, d_021DDA28, 0x6aa);
        t->bufA = func_02030734(heap, n * sizeof(Vec3_0218EEFC), 0, d_021DDA28, 0x6ab);
        t->bufB = func_02030734(heap, n * sizeof(Vec3_0218EEFC), 0, d_021DDA28, 0x6ac);
        for (; i < n; i++) {
            Vec3_0218EEFC *v = &t->bufA[i];
            v->x = 0;
            v->y = 0;
            v->z = 0;
            v = &t->bufB[i];
            v->x = 0;
            v->y = 0;
            v->z = 0;
        }
        t->count = n;
        t->unk0C = x;
        t->unk10 = 0;
        t->unk04 = 0;
        t->unk08 = x;
        t->flag1 = 0;
        t->flag2 = 0;
        t->flag4 = 0;
        if (flags & 1)
            t->flag1 = 1;
        if (flags & 2)
            t->flag2 = 1;
        if (flags & 4)
            t->flag4 = 1;
        t->unk28 = 1;
        t->unk2C = 0;
        a = (u8 *)a + 0xec;
        *(Track * *)&((struct Obj12593 *)a)->f0 = t;
    }
}


void func_0218EFD4(u8 *a)
{
    if (*(u8 * *)&((struct Obj04202 *)a)->fEC != 0) {
        func_020307B0(((struct Obj19566 *)(*(u8 * *)&((struct Obj04202 *)a)->fEC))->f20);
        func_020307B0(((struct Obj19567 *)(*(u8 * *)&((struct Obj04202 *)a)->fEC))->f24);
        func_020307B0(((struct Obj04202 *)a)->fEC);
        ((struct Obj04202 *)a)->fEC = 0;
    }
}

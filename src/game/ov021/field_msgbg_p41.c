/*
 * file:     field_msgbg_p41.c
 * unit:     yes
 * function: func_0218F1BC, func_0218F1DC, func_0218F1FC, func_0218F310, func_0218F460, func_0218F780, func_0218F7D0
 * address:  0x0218F1BC
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
 *   d_021DDA18  0x021DDA18  data  ov021  a4
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   VEC_Subtract     0x0207CA00  arm
 *   VEC_Mag          0x0207CBD0  arm
 *   FX_Modf          0x0207D14C  arm
 *   VEC_Normalize    0x0207CCA4  arm
 *   VEC_CrossProduct 0x0207CAE8  arm
 *   VEC_DotProduct   0x0207CA68  arm
 *   FX_AcosIdx       0x0207D184  arm
 *   _ll_mul          0x0209C054  arm
 *   d_021D3E38       0x021D3E38  data   a4
 *   d_020A1B38       0x020A1B38  data   a2
 *   func_0218F18C  0x0218F18C  thumb  ov021
 */
#include "../../matched/include/Obj02371.h"
#include "../../matched/include/Obj07419.h"
#include "../../matched/include/Obj07420.h"

#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16_0218F1BC;

typedef signed int     s32;

typedef void (*Handler)(void *a, u32 b, u32 c);

typedef signed short   s16_0218F1DC;

typedef struct { int x, y, z; } V;

typedef struct {
    char pad00[8];
    int x0;
    int x1;
    int z0;
    int z1;
} Box;

typedef short s16_0218F310;

typedef struct {
    char pad00[8];
    int cx;
    int cz;
    int rmax;
    u16 amax;
    u16 amin;
} Ring;

typedef struct { u32 a, b, c; } V3;

extern void VEC_Subtract(V *a, V *b, V *o);
extern int VEC_Mag(V *a);
extern int FX_Modf(int x, int *ip);
extern void VEC_Normalize(V *a, V *o);
extern void VEC_CrossProduct(V *a, V *b, V *o);
extern int VEC_DotProduct(V *a, V *b);
extern u16 FX_AcosIdx(int x);
extern void func_0218F18C(u8 *s, u8 *d);
void func_0218F1BC(u32 *a, u32 b);
void func_0218F1DC(u32 *a, u32 b);
int func_0218F1FC(const Box *a, V *b, V *out);
int func_0218F310(const Ring *a, V *b, V *out);
int func_0218F460(Box *a, V *b, V *out);
void func_0218F780(u8 *s, u8 *d);
void func_0218F7D0(u8 *s, u8 *d);
extern Handler d_021DDA18[];
extern V d_021D3E38;
extern s16_0218F310 d_020A1B38[];


void func_0218F1BC(u32 *a, u32 b)
{
    if (a[1] == 0) {
        Handler fp = d_021DDA18[a[0]];
        if (fp != 0)
            fp(a, b, b);
    }
}


void func_0218F1DC(u32 *a, u32 b)
{
    if (a[1] == 1) {
        Handler fp = d_021DDA18[a[0]];
        if (fp != 0)
            fp(a, b, b);
    }
}


/*
 * Clamps a point into the box [+8,+0xc] x [+0x10,+0x14] (whole units,
 * converted to fx32); returns 1 when it moved.  Same box as func_0218F460.
 */
int func_0218F1FC(const Box *a, V *b, V *out)
{
    V p;
    int r;

    p = *b;
    r = 0;
    out->x = p.x;
    out->z = p.z;
    out->y = p.y;
    if (FX_F32_TO_FX32(a->x0) > p.x) {
        r = 1;
        out->x = FX_F32_TO_FX32(a->x0);
    } else if (a->x1 * 4096 < p.x) {
        r = 1;
        out->x = FX_F32_TO_FX32(a->x1);
    }
    if (a->z0 * 4096 > p.z) {
        r = 1;
        out->z = FX_F32_TO_FX32(a->z0);
    } else if (a->z1 * 4096 < p.z) {
        r = 1;
        out->z = FX_F32_TO_FX32(a->z1);
    }
    return r;
}


/*
 * Clamps a point to a ring sector around the centre at +8/+0xc: radius
 * capped at +0x10, angle clamped to [+0x16, +0x14]; returns 1 when clamped.
 * `const` on a lets the a->cz load schedule above the c.y = 0 store
 * (docs/idioms/a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer.md);
 * the table entry read into an s16 local puts it in r0:r1 of _ll_mul, and
 * `r = 1` repeated in both inner arms gives the cross-jumped clamp blocks.
 *
 * Addresses are Black-image addresses.
 */
int func_0218F310(const Ring *a, V *b, V *out)
{
    V k;
    V c;
    V d;
    V e;
    V n;
    V x;
    int m;
    int r;
    u16 ang;
    u16 lo, hi;
    int d1, d2;
    int i;
    s16_0218F310 s;

    k = d_021D3E38;
    c = *b;
    d = *b;
    out->x = b->x;
    out->y = b->y;
    out->z = b->z;
    e.x = a->cx;
    e.y = 0;
    r = 0;
    c.y = 0;
    e.z = a->cz;
    VEC_Subtract(&c, &e, &n);
    m = VEC_Mag(&n);
    if (FX_Modf(m, &m) > 0) {
        m += 0x1000;
    }
    VEC_Normalize(&n, &n);
    VEC_CrossProduct(&k, &n, &x);
    ang = FX_AcosIdx(VEC_DotProduct(&k, &n));
    if (x.y < 0) {
        ang = 0x10000 - ang;
    }
    if (m > a->rmax) {
        m = a->rmax;
        r = 1;
    }
    lo = a->amin;
    hi = a->amax;
    if (hi != lo) {
        if (hi > lo) {
            if (lo < ang && hi >= ang) {
                d1 = hi - ang;
                if (d1 < 0) d1 = -d1;
                d2 = lo - ang;
                if (d2 < 0) d2 = -d2;
                if (d2 > d1) {
                    ang = hi;
                    r = 1;
                } else {
                    ang = lo;
                    r = 1;
                }
            }
        } else if (hi > ang) {
            ang = hi;
            r = 1;
        } else if (lo < ang) {
            ang = lo;
            r = 1;
        }
    }
    if (r != 0) {
        i = (ang >> 4) * 2;
        s = d_020A1B38[i];
        out->x = e.x + (int)(((long long)s * m + 0x800) >> 12);
        s = d_020A1B38[i + 1];
        out->z = e.z + (int)(((long long)s * m + 0x800) >> 12);
        out->y = d.y;
    }
    return r;
}


/*
 * Pushes a point inside the box [+8,+0xc] x [+0x10,+0x14] (whole units,
 * converted to fx32) out through the nearest side; returns 1 when it moved.
 * Reading p.z directly (no named local) is what puts its CSE slot below the
 * a->x0 temp.
 *
 * Addresses are Black-image addresses.
 */
int func_0218F460(Box *a, V *b, V *out)
{
    V p;
    int r;
    int best;
    int side;

    p = *b;
    r = 0;
    out->x = p.x;
    out->z = p.z;
    out->y = p.y;
    if (FX_F32_TO_FX32(a->x0) < p.x && FX_F32_TO_FX32(a->x1) > p.x &&
        FX_F32_TO_FX32(a->z0) < p.z && FX_F32_TO_FX32(a->z1) > p.z) {
        r = 1;
        best = out->x - FX_F32_TO_FX32(a->x0);
        side = 0;
        if (best > FX_F32_TO_FX32(a->x1) - out->x) {
            best = FX_F32_TO_FX32(a->x1) - out->x;
            side = 1;
        }
        if (best > out->z - FX_F32_TO_FX32(a->z0)) {
            best = out->z - FX_F32_TO_FX32(a->z0);
            side = 2;
        }
        if (best > FX_F32_TO_FX32(a->z1) - out->z) {
            best = FX_F32_TO_FX32(a->z1) - out->z;
            side = 3;
        }
        switch (side) {
        case 0:
            out->x = FX_F32_TO_FX32(a->x0);
            break;
        case 1:
            out->x = FX_F32_TO_FX32(a->x1);
            break;
        case 2:
            out->z = FX_F32_TO_FX32(a->z0);
            break;
        case 3:
            out->z = FX_F32_TO_FX32(a->z1);
            break;
        }
    }
    return r;
}


/*
 * Addresses are Black-image addresses.
 */
void func_0218F780(u8 *s, u8 *d)
{
    *(V3 *)(d + 0)    = *(V3 *)(s + 0x24);
    *(V3 *)(d + 0xc)  = *(V3 *)(s + 0x48);
    ((struct Obj07419 *)d)->f24 = ((struct Obj02371 *)s)->f78;
    ((struct Obj07419 *)d)->f26 = ((struct Obj02371 *)s)->f7A;
    ((struct Obj07419 *)d)->f28 = ((struct Obj02371 *)s)->f7C;
    ((struct Obj07419 *)d)->f2C = ((struct Obj02371 *)s)->f80;
    *(V3 *)(d + 0x18) = *(V3 *)(s + 0x60);
}


void func_0218F7D0(u8 *s, u8 *d)
{
    *(V3 *)(d + 0) = *(V3 *)(s + 0x24);
    func_0218F18C(s, d + 0xc);
    ((struct Obj07420 *)d)->f24 = ((struct Obj02371 *)s)->f78;
    ((struct Obj07420 *)d)->f26 = ((struct Obj02371 *)s)->f7A;
    ((struct Obj07420 *)d)->f28 = ((struct Obj02371 *)s)->f7C;
    ((struct Obj07420 *)d)->f2C = ((struct Obj02371 *)s)->f80;
    *(V3 *)(d + 0x18) = *(V3 *)(s + 0x60);
}

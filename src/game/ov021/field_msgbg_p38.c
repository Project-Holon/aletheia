/*
 * file:     field_msgbg_p38.c
 * unit:     yes
 * function: func_0218E610, func_0218E674, func_0218E6A4, func_0218E6F0, func_0218E73C, func_0218E764, func_0218E7DC, func_0218EC2C
 * address:  0x0218E610
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
 *   func_0207CBD0  0x0207CBD0  arm
 *   func_0207CCA4  0x0207CCA4  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   func_0207CA00  0x0207CA00  arm
 *   func_0218E284  0x0218E284  thumb
 *   func_0218E298  0x0218E298  thumb
 *   func_0218E358  0x0218E358  thumb
 *   func_0218E404  0x0218E404  thumb
 *   func_0207CA68  0x0207CA68  arm
 *   d_021D3E2C     0x021D3E2C  data   ov021  a4
 *   _ll_mul        0x0209C054  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   d_020A1B38     0x020A1B38  data   a2
 */
#include "../../matched/include/Obj01848.h"
#include "../../matched/include/Obj00428.h"
#include "../../matched/include/Obj17906.h"

#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned short u16;

typedef struct { int x, y, z; } V;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef signed char    s8;

typedef signed short   s16_0218E674;

typedef signed int     s32;

typedef signed short   s16_0218E73C;

typedef short s16_0218E7DC;

typedef struct { s16_0218E7DC x, y, z; } VS;

extern int func_0207CBD0(void *a);
extern void func_0207CCA4(void *a, V *b);
extern int func_0207CFB8(int a, int b);
extern void func_0207CA00(void *a, void *b, void *c);
extern void func_0218E284(u8 *a);
extern int func_0218E298(u8 *a);
extern void func_0218E358(u8 *a);
extern void func_0218E404(u8 *a);
extern int func_0207CA68(V *a, V *b);
void func_0218E610(void *a, u16 *b, u16 *c, int *d);
void func_0218E674(u8 *a, u32 b);
void func_0218E6A4(u8 *a);
void func_0218E6F0(u8 *a);
void func_0218E73C(u8 *a);
void func_0218E764(u8 *a, void *b, void *c);
void func_0218E7DC(V *v, u16 h0, u16 h1, u16 *p0, u16 *p1);
u32 func_0218EC2C(u8 *p);
extern V d_021D3E2C;
extern s16_0218E7DC d_020A1B38[];


/*
 * Converts a vector to two 16-bit angles plus its length.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E610(void *a, u16 *b, u16 *c, int *d)
{
    V v;
    V w;
    u16 h[2];
    int len;

    len = func_0207CBD0(a);
    func_0207CCA4(a, &v);
    w.x = v.x;
    w.y = 0;
    w.z = v.z;
    h[1] = func_0207CFB8(v.y, func_0207CBD0(&w));
    h[0] = func_0207CFB8(v.x, v.z);
    func_0218E7DC(&v, h[0], h[1], h, &h[1]);
    *b = h[1];
    *c = h[0];
    *d = len;
}


void func_0218E674(u8 *a, u32 b)
{
    struct { u16 y, x; u32 z; } t;
    func_0218E610((void *)b, &t.x, &t.y, (int *)(&t.z));
    ((struct Obj01848 *)a)->f78 = t.x;
    ((struct Obj01848 *)a)->f7A = t.y;
    ((struct Obj01848 *)a)->f7C = t.z;
}


/*
 * Toggles a half-turn offset or converts a matrix pair to angles (mode 1).
 *
 * Addresses are Black-image addresses.
 */
void func_0218E6A4(u8 *a)
{
    u8 tmp[12];

    if (((struct Obj01848 *)a)->f14 == 1) {
        ((struct Obj01848 *)a)->f7A = ((struct Obj01848 *)a)->f7A + 0x8000;
        ((struct Obj01848 *)a)->f78 = ((struct Obj01848 *)a)->f78 + 0x8000;
    } else {
        func_0207CA00(a + 0x24, a + 0x54, tmp);
        func_0218E674(a, (u32)tmp);
    }
}


/*
 * Twin of func_0218E6A4 with mode 0 and the other matrix pair.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E6F0(u8 *a)
{
    u8 tmp[12];

    if (((struct Obj01848 *)a)->f14 == 0) {
        ((struct Obj01848 *)a)->f7A = ((struct Obj01848 *)a)->f7A + 0x8000;
        ((struct Obj01848 *)a)->f78 = ((struct Obj01848 *)a)->f78 + 0x8000;
    } else {
        func_0207CA00(a + 0x48, a + 0x3C, tmp);
        func_0218E674(a, (u32)tmp);
    }
}


void func_0218E73C(u8 *a)
{
    u32 s = ((struct Obj00428 *)a)->f14;
    if (s == 0) {
        func_0218E284(a);
        func_0218E358(a);
    } else if (s == 1) {
        func_0218E298(a);
        func_0218E404(a);
    }
}


/*
 * Derives two 16-bit angles from a matrix and stores them at +0x82/+0x84.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E764(u8 *a, void *b, void *c)
{
    V v;
    V k;
    V w;
    int r, t;
    int s;

    func_0207CA00(c, b, &v);
    func_0207CCA4(&v, &v);
    ((struct Obj00428 *)a)->f82 = func_0207CFB8(v.x, v.z);
    k = d_021D3E2C;
    r = func_0207CA68(&k, &v);
    w = v;
    s = 0;
    w.y = 0;
    func_0207CCA4(&w, &w);
    t = func_0207CA68(&w, &v);
    if (t != 0) {
        s = func_0207CFB8(r, t);
    }
    ((struct Obj00428 *)a)->f84 = s;
}


static inline int FXM(int a, int b)
{
    return (int)(((long long)a * b + 0x800) >> 12);
}


/*
 * Refines two 16-bit angles (yaw h0, pitch h1) toward a target vector: builds the unit
 * direction for the current angles and for yaw +/- one degree (0xb6), then nudges each
 * angle by a linear interpolation per quadrant. Writes the results to p0/p1.
 *
 * Addresses are Black-image addresses.
 */
void func_0218E7DC(V *v, u16 h0, u16 h1, u16 *p0, u16 *p1)
{
    VS c = {0, 0, 0};
    VS b = {0, 0, 0};
    VS a = {0, 0, 0};
    int c1;
    int sb, sa;
    int k0, k1, kb, ka;

    *p0 = h0;
    *p1 = h1;

    k0 = (h0 >> 4) * 2;
    k1 = (h1 >> 4) * 2;
    c1 = d_020A1B38[k1 + 1];
    c.x = FXM(d_020A1B38[k0], c1);
    c.y = d_020A1B38[k1];
    c.z = FXM(d_020A1B38[k0 + 1], c1);
    kb = ((h0 - 0xb6) >> 4) * 2;
    b.x = FXM(d_020A1B38[kb], c1);
    b.z = FXM(d_020A1B38[kb + 1], c1);
    sb = d_020A1B38[((h1 - 0xb6) >> 4) * 2];
    ka = ((h0 + 0xb6) >> 4) * 2;
    a.x = FXM(d_020A1B38[ka], c1);
    a.z = FXM(d_020A1B38[ka + 1], c1);
    sa = d_020A1B38[((h1 + 0xb6) >> 4) * 2];

    if (h0 < 0x4000) {
        if (c.x < v->x && c.z > v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 - (u16)(0xb6 * (v->x - c.x) / (b.x - c.x));
            } else {
                h0 = h0 - (u16)(0xb6 * (c.z - v->z) / (c.z - b.z));
            }
        } else if (c.x > v->x && c.z < v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 + (u16)(0xb6 * (c.x - v->x) / (c.x - a.x));
            } else {
                h0 = h0 + (u16)(0xb6 * (v->z - c.z) / (a.z - c.z));
            }
        }
    } else if (h0 < 0x8000) {
        if (c.x > v->x && c.z > v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 - (u16)(0xb6 * (c.x - v->x) / (c.x - b.x));
            } else {
                h0 = h0 - (u16)(0xb6 * (c.z - v->z) / (c.z - b.z));
            }
        } else if (c.x < v->x && c.z < v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 + (u16)(0xb6 * (v->x - c.x) / (a.x - c.x));
            } else {
                h0 = h0 + (u16)(0xb6 * (v->z - c.z) / (a.z - c.z));
            }
        }
    } else if (h0 < 0xC000) {
        if (c.x > v->x && c.z < v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 - (u16)(0xb6 * (c.x - v->x) / (c.x - b.x));
            } else {
                h0 = h0 - (u16)(0xb6 * (v->z - c.z) / (b.z - c.z));
            }
        } else if (c.x < v->x && c.z > v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 + (u16)(0xb6 * (v->x - c.x) / (a.x - c.x));
            } else {
                h0 = h0 + (u16)(0xb6 * (c.z - v->z) / (c.z - a.z));
            }
        }
    } else {
        if (c.x < v->x && c.z < v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 - (u16)(0xb6 * (v->x - c.x) / (b.x - c.x));
            } else {
                h0 = h0 - (u16)(0xb6 * (v->z - c.z) / (b.z - c.z));
            }
        } else if (c.x > v->x && c.z > v->z) {
            if (ABS(c.x - v->x) >= ABS(c.z - v->z)) {
                h0 = h0 + (u16)(0xb6 * (c.x - v->x) / (c.x - a.x));
            } else {
                h0 = h0 + (u16)(0xb6 * (c.z - v->z) / (c.z - a.z));
            }
        }
    }

    if (h1 < 0x4000) {
        if (c.y > v->y) {
            h1 = h1 - (u16)(0xb6 * (c.y - v->y) / (c.y - sb));
        } else if (c.y < v->y) {
            h1 = h1 + (u16)(0xb6 * (v->y - c.y) / (sa - c.y));
        }
    } else if (h1 >= 0xC000) {
        if (c.y > v->y) {
            h1 = h1 - (u16)(0xb6 * (c.y - v->y) / (c.y - sb));
        } else if (c.y < v->y) {
            h1 = h1 + (u16)(0xb6 * (v->y - c.y) / (sa - c.y));
        }
    }

    *p0 = h0;
    *p1 = h1;
}


/*
 * Loads the 32-bit word at byte +0xc of the object.
 */
u32 func_0218EC2C(u8 *p)
{
    return ((struct Obj17906 *)p)->fC;
}

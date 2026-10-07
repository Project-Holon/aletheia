/*
 * file:     unit_021EE740_p06.c
 * unit:     yes
 * function: func_021EF4D0, func_021EF58C, func_021EF614, func_021EF664, func_021EF830
 * address:  0x021EF4D0
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021A2640  0x021A2640  thumb  ov021
 *   func_021A21E0  0x021A21E0  thumb  ov021
 *   func_021A26C4  0x021A26C4  thumb  ov021
 *   func_020056EC  0x020056EC  thumb
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B954  0x0204B954  arm
 *   func_021A232C  0x021A232C  thumb  ov021
 *   func_021A2160  0x021A2160  thumb  ov021
 *   func_021A25BC  0x021A25BC  thumb  ov021
 *   func_021EF920  0x021EF920  thumb  ov026
 *   func_021EF950  0x021EF950  thumb  ov026
 *   _s32_div_f     0x0209C0A4  arm
 *   func_021A2170  0x021A2170  thumb  ov021
 *   func_021A2180  0x021A2180  thumb  ov021
 *   d_021EFD74     0x021EFD74  data  ov026  a4
 *   d_021EFD78     0x021EFD78  data  ov026  a4
 *   d_021EFD3C     0x021EFD3C  data  ov026  a4
 *   func_021A244C  0x021A244C  thumb  ov021
 *   func_021A2564  0x021A2564  thumb  ov021
 *   func_021A2190  0x021A2190  thumb  ov021
 *   func_021A21A0  0x021A21A0  thumb  ov021
 */
#include "../../matched/include/Obj00086.h"

struct Actor;
struct Obj;
typedef short s16_021EF4D0;

struct PtS { s16_021EF4D0 x; s16_021EF4D0 y; };

struct B { char pad[0x16]; s16_021EF4D0 vx; s16_021EF4D0 vy; };

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16_021EF58C;

typedef signed short   s16_021EF664;

typedef struct {
    int a;
    int b;
    int c;
} T3;

typedef signed short s16_021EF830;

typedef signed int     s32;

extern void func_021A2640(u8 *a, struct PtS *b);
extern void func_021A21E0(u32 *p);
extern int func_021A26C4(u32 a, u32 b);
extern u32 func_020056EC(u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *, u32);
extern void func_0204B954(struct Actor *a, u32 v);
extern void func_021A232C(u8 *p, int a, int b, int c, int d);
extern void func_021A2160(unsigned char *o, unsigned int v, int i);
extern void func_021A25BC(unsigned char *o, int arg);
extern void func_021A2170(unsigned char *o, unsigned int v, int i);
extern void func_021A2180(unsigned char *o, unsigned int v, int i);
extern void func_021EF920(u8 *a, s16_021EF664 *p, int b, int c);
extern void func_021EF950(int, s16_021EF664 *, int);
extern void func_021A244C(u8 *o, s32 *outX, s32 *outY);
extern void func_021A2564(int, int, int);
extern void func_021A2190(unsigned char *o, unsigned int v, int i);
extern void func_021A21A0(unsigned char *o, unsigned int v, int i);
void func_021EF4D0(void *a, const struct B *b, s16_021EF4D0 *c);
void func_021EF58C(int a, s16_021EF58C *b, s16_021EF58C *c, int d);
void func_021EF614(int a, u16 *p, int c, int d);
void func_021EF664(int a, s16_021EF664 *p, int b, int d);
void func_021EF830(int a, s16_021EF830 *p);
extern T3 d_021EFD74[];
extern T3 d_021EFD78[];
extern int d_021EFD3C[];

/*
 * note: 2026-10-05 (wD8 lane04): closed. b is a const pointer (the struct is for readability; a
 *   const char * with casts gives the same bytes, a non-const one does not): the c[1] store then does
 *   not kill the CSE of c[3] + b->vy, so c[5] reuses the kept sum. Both sums are written inline
 *   (c[0] + (s16)(c[2] + vx)) and repeated for c[4]/c[5].
 *   EXACT* = 186 bytes compiled vs a 188-byte listing extent (2 bytes of padding).
 */
void func_021EF4D0(void *a, const struct B *b, s16_021EF4D0 *c)
{
    struct PtS pt;
    s16_021EF4D0 vx;
    func_021A2640(a, &pt);
    vx = b->vx;
    if (vx != 0) {
        c[0] = c[0] + (s16_021EF4D0)(c[2] + vx);
        c[1] = c[1] + (s16_021EF4D0)(c[3] + b->vy);
        pt.x = c[0] / 8;
        pt.y = c[1] / 8;
        c[4] = c[2] + vx;
        c[5] = c[3] + b->vy;
    } else {
        c[0] = c[0] + c[4];
        c[1] = c[1] + c[5];
        pt.x = c[0] / 8;
        pt.y = c[1] / 8;
    }
    if (pt.x >= 0x100 || pt.y >= 0xc0) {
        func_021A21E0(a);
    } else {
        func_021A26C4((u32)a, (u32)(&pt));
    }
}


void func_021EF58C(int a, s16_021EF58C *b, s16_021EF58C *c, int d)
{
    u32 r;
    s16_021EF58C v[2];
    int one;

    r = func_020056EC(0);
    c[2] = r % 24 + 0x50;
    c[3] = r % 24 + 0xE;
    c[4] = c[2] + b[11];
    c[5] = c[3] + b[12];
    v[0] = (r & 7) - 8;
    v[1] = r % 160 - 16;
    func_021A26C4(a, (u32)v);
    c[0] = v[0] << 3;
    c[1] = v[1] << 3;
    func_0204B878((struct Obj *)d, 2);
    one = 1;
    func_0204B92C((struct Obj *)d, 1);
    func_0204B954((struct Actor *)d, one << 13);
}


void func_021EF614(int a, u16 *p, int c, int d)
{
    u32 r = func_020056EC(0);
    p[8] = 1;
    p[7] = r % 400 + 0x3C;
    p[6] = 0;
    if (d == 0) {
        func_021A232C((u8 *)a, 9, 0x7F80, 10, c);
        func_021A2160((unsigned char *)a, 0, 1);
        func_021A25BC((unsigned char *)a, 0x690);
    }
}


void func_021EF664(int a, s16_021EF664 *p, int b, int d)
{
    u32 r;
    int i;

    switch (p[8]) {
    case 0:
        break;
    case 1:
        p[6] = p[6] + 1;
        func_021EF920((u8 *)a, p, b, 0x71F);
        if (p[6] >= p[7]) {
            p[8] = 3;
            p[7] = 0x10;
            p[6] = 0;
            if (d == 0) {
                func_021A232C((u8 *)a, 9, 0x7F70, 10, b);
                func_021A25BC((unsigned char *)a, 0x720);
            }
        }
        break;
    case 2:
        p[6] = p[6] + 1;
        func_021EF920((u8 *)a, p, b, 0x71F);
        func_021EF950(a, p, b);
        if (p[6] >= p[7]) {
            p[8] = 4;
            p[7] = 0x10;
            p[6] = 0;
            if (d == 0) {
                func_021A2160((unsigned char *)a, 0, 1);
                func_021A2170((unsigned char *)a, 0x1000, 0);
                func_021A2180((unsigned char *)a, 0x1000, 0);
            }
        }
        break;
    case 3:
        p[6] = p[6] + 1;
        if (p[6] >= p[7]) {
            r = func_020056EC(0);
            p[8] = 2;
            p[7] = r % 400 + 0x3C;
            p[6] = 0;
            if (d == 0) {
                func_021A2160((unsigned char *)a, 1, 1);
                func_021A2170((unsigned char *)a, 0x800, 0);
                func_021A2180((unsigned char *)a, 0x1800, 0);
            }
        }
        break;
    case 4:
        p[6] = p[6] + 1;
        if (p[6] >= p[7]) {
            func_021EF614(a, (u16 *)p, b, d);
        }
        break;
    }
    switch (p[8]) {
    case 0:
        break;
    case 1:
        if (p[7] - p[6] >= 9) {
            p[11] = 0;
            p[12] = 0;
        } else {
            p[11] = 0xA0;
            p[12] = 0x10;
        }
        break;
    case 2:
        i = p[6] % 0x48 * 6 / 0x48;
        p[11] = d_021EFD74[i].a;
        p[12] = d_021EFD78[i].a;
        ((struct Obj00086 *)p)->f1C = d_021EFD3C[(p[6] % 0xE0u) * 14 / 0xE0u];
        break;
    case 3:
    case 4:
        p[11] = 0xA0;
        p[12] = 0x10;
        ((struct Obj00086 *)p)->f1C = 0x800;
        break;
    }
}


void func_021EF830(int a, s16_021EF830 *p)
{
    int x;
    int y;

    func_021A244C((u8 *)a, &x, &y);
    func_021A2564(a, x, y);
    if (p[11] != 0) {
        p[2] = (p[2] + 9) % 256;
        p[3] = (p[3] + 3) % 256;
        p[4] = (p[4] + 9) % 256;
        p[5] = (p[5] + 2) % 256;
    } else {
        p[2] = (p[2] + 3) % 256;
        p[3] = (p[3] + 8) % 256;
    }
    func_021A2190((unsigned char *)a, -(p[2] + x), 0);
    func_021A21A0((unsigned char *)a, y - p[3], 0);
    func_021A2190((unsigned char *)a, -(p[4] + x), 1);
    func_021A21A0((unsigned char *)a, y - p[5], 1);
    func_021A2170((unsigned char *)a, ((struct Obj00086 *)p)->f1C, 1);
    func_021A2180((unsigned char *)a, ((struct Obj00086 *)p)->f1C, 1);
}

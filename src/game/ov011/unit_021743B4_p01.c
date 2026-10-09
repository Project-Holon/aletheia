/*
 * file:     unit_021743B4_p01.c
 * unit:     yes
 * function: func_021743B4, func_021743E4, func_0217440C, func_0217443C, func_0217446C, func_0217449C, func_021744D0, func_02174514, func_0217456C, func_021745B0, func_021745F8, func_02174630, func_02174660, func_02174690, func_021746AC, func_021746EC, func_02174734, func_02174798, func_021747A8, func_021747E0, func_021747F4
 * address:  0x021743B4
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_0203D1E8 0x0203D1E8 arm
 *   func_021780FC 0x021780FC thumb ov014
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02012F20  0x02012F20  thumb
 *   func_02012B38  0x02012B38  thumb
 *   func_02014484  0x02014484  thumb
 *   func_0202E7E0  0x0202E7E0  thumb
 *   func_02012950  0x02012950  thumb
 *   func_0202E7C4  0x0202E7C4  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020266AC 0x020266AC thumb
 *   func_020127D0  0x020127D0  thumb
 *   func_021583EC  0x021583EC  thumb ov010
 *   func_021861F4  0x021861F4  thumb ov020
 *   func_02012800  0x02012800  thumb
 *   func_0203D578  0x0203D578  arm
 *   func_0203D4D0  0x0203D4D0  arm
 *   func_02161FF0  0x02161FF0  thumb ov010
 *   func_02162008  0x02162008  thumb ov010
 */
#include "../../matched/include/Obj12421.h"

struct Entry;
struct Link;
struct BigObj;
struct Rec44;
struct Sub02014444Obj;
struct Sub24;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char  u8;

typedef struct { u8 low : 4; u8 flags : 2; u8 high : 2; } F93F;

typedef struct F {
    unsigned char f0 : 1;
    unsigned char f1 : 7;
} F;

u32 func_02026478(void *obj);
int func_021736D8(void);
struct Entry *func_020399A8(void);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
void func_0203D1E8(u32 unused, void *arg);
void func_021780FC(u8 value);
u32 func_0203D3F8(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 func_0203D1A4(struct Link *p);
int func_02012F20(int a);
void *func_02012B38(const struct BigObj *p);
u8 func_02014484(struct Sub02014444Obj *o);
int func_0202E7E0(int a);
struct Rec44 *func_02012950(struct Sub24 *p, u32 i);
void func_0202E7C4(int a, int b, int c);
void func_02082D44(void *d, void *s, int n);
void func_020266AC(u32 a, u32 b, u32 c);
u8 *func_020127D0(u8 *o, u32 idx);
int func_021583EC(void *a0, int a1);
void func_021861F4(u16 *p, int x);
void func_02012800(u8 *obj, void *dst);
int func_0203D578(int a, int b);
u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
void func_02161FF0(u8 *p, int v);
void func_02162008(u8 *p, u16 v);
int func_021743B4(char *p);
void func_021743E4(int a, int b, void *c, signed char *p);
u32 func_0217440C(void);
void func_0217443C(int a, int b, void *c, signed char *p);
u32 func_0217446C(void);
void func_0217449C(int a, int b, u8 *c, u8 *p);
int func_021744D0(int a, int b, int c, ...);
void func_02174514(int a, int b, int *c, char *d);
int func_0217456C(int a, int b, int c, ...);
void func_021745B0(int a, int b, void *c, char *d);
int func_021745F8(u32 a, u32 b);
void func_02174630(int a, int b, u8 *c, u8 *p);
int func_02174660(int a, ...);
void func_02174690(int n, int b, int c, u8 *p);
int func_021746AC(char *a, int b);
void func_021746EC(int a, int b, void *c, char *d);
int func_02174734(char *p, int b, void *c);
void func_02174798(int a, int b, int c, u8 *p);
int func_021747A8(int a, int b);
void func_021747E0(int a, int b, int c, u8 *p);
int func_021747F4(int a, int b);



int func_021743B4(char *p)
{
    func_02026478((void *)(((int *)p)[1]));
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3A8((struct Entry *)((u32)func_020399A8()), 0x21d, 4, (u32)(p + 0x354));
}



void func_021743E4(int a, int b, void *c, signed char *p)
{
    p[0x93d]++;
    if (p[0x93c] == 0) {
        func_0203D1E8((u32)func_020399A8(), 0);
        func_021780FC(1);
    }
}



u32 func_0217440C(void)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), 0, 0x21e, 0, 0, 0, 0, 0);
}



void func_0217443C(int a, int b, void *c, signed char *p)
{
    p[0x93d]--;
    if (p[0x93d] == 0 && p[0x93c] == 0) {
        func_0203D1E8((u32)func_020399A8(), (void *)1);
        func_021780FC(0);
    }
}



u32 func_0217446C(void)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), 0, 0x21f, 0, 0, 0, 0, 0);
}



/*
 * extent: existing follower ov011_func_021744D0.c stays separate.
 */
void func_0217449C(int a, int b, u8 *c, u8 *p)
{
    if (a != func_0203D1A4((struct Link *)((u32)func_020399A8()))) {
        ((F93F *)(p + 0x93f))->flags |= *c;
    }
}




/*
 * Handed as 0x021744D2; the function starts at the push {r0-r3} at 0x021744D0.
 */
int func_021744D0(int a, int b, int c, ...)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3F8((int)func_020399A8(), b, 0x220, 1, (u32)(&c), 0, 0, 0);
}




/*
 * 2026-10-05 (D8 lane19): re-verified, MATCH; only unresolved relocations are arm9 leaves 0x0202E7E0 and 0x0202E7C4 (no witness outside range). Needs labels seeded. Source is byte-correct; no C change possible.
 *
 * Blocked: MATCH*, two unlabelled arm9 leaves have no witness outside the range (Ilias's):
 *   0x0202E7E0 thumb `int f(int *p) { return *p; }` (ldr r0,[r0]; bx lr)
 *   0x0202E7C4 thumb leaf, ldm/stm struct copy of 0x18 bytes (words at 0202E7C4..0202E7DC)
 * Everything else in the file compiles byte-correct (88 of 90 B listed, tail is pad).
 */
void func_02174514(int a, int b, int *c, char *d)
{
    int p;
    int q;
    int t;

    p = func_02026478((void *)(((int *)d)[1]));
    q = func_02012F20(p);
    if ((unsigned char)d[0x8fb] & (1 << a)) {
        if (func_02014484(func_02012B38((const struct BigObj *)p)) == 1) {
            t = func_0202E7E0(q);
            if (t == 0 || t == 3) {
                func_0202E7C4(q, *c, (int)func_02012950((struct Sub24 *)p, a));
            }
        }
    }
}




/*
 * Handed as 0x0217456E; the function starts at the push {r0-r3} at 0x0217456C.
 */
int func_0217456C(int a, int b, int c, ...)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3F8((int)func_020399A8(), b, 0x221, 4, (u32)(&c), 0, 0, 0);
}




void func_021745B0(int a, int b, void *c, char *d)
{
    func_02026478((void *)(((int *)d)[1]));
    if (((unsigned char)d[0x8fb] & (1 << a)) && ((F *)(d + 0x8f8))->f0 == 0) {
        func_02082D44(c, d + 0x8e4, 0x14);
        ((F *)(d + 0x8f8))->f0 = 1;
    }
}



int func_021745F8(u32 a, u32 b)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), a, 0x222, 0x14, b, 0, 0, 0);
}



/*
 * extent: existing follower ov011_func_02174660.c stays separate.
 */
void func_02174630(int a, int b, u8 *c, u8 *p)
{
    if (a != func_0203D1A4((struct Link *)((u32)func_020399A8())) && (p[0x8fb] & (1 << a))) {
        func_020266AC(((u32 *)p)[1], a, *c);
    }
}




/*
 * Handed as 0x02174662; the function starts at the push {r0-r3} at 0x02174660.
 */
int func_02174660(int a, ...)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3A8(func_020399A8(), 0x223, 1, (u32)(&a));
}


void func_02174690(int n, int b, int c, u8 *p) { p[0x908] |= (u8)(1 << n); }



int func_021746AC(char *a, int b)
{
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    r = func_0203D3F8((u32)func_020399A8(), b, 0x224, 0, 0, 0, 0, 0);
    if (r == 1) {
        a[0x90c] = 0;
    }
    return r;
}



void func_021746EC(int a, int b, void *c, char *d)
{
    int h;
    int s;

    h = func_02026478((void *)(((struct Obj12421 *)d)->f4));
    s = (int)func_020127D0((u8 *)h, 0);
    func_021861F4(c, func_021583EC((void *)h, a));
    func_02082D44(c, (void *)s, 0x1E8);
    func_02012800((u8 *)h, c);
    d[0x90C] = 1;
}



int func_02174734(char *p, int b, void *c)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    if (func_0203D578((int)func_020399A8(), 0x225) == 1) {
        return 0;
    }
    func_02082D44(c, p + 0x460, 0x1E8);
    return func_0203D4D0((int)func_020399A8(), b & 0xFF, 0x225, 0x1E8, (u32)c, 0, 0, 1);
}


void func_02174798(int a, int b, int c, u8 *p)
{
    func_02161FF0(p + 0x35c, c);
}


int func_021747A8(int a, int b)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), b, 0x226, 8, a, 0, 0, 0);
}


void func_021747E0(int a, int b, int c, u8 *p)
{
    func_02162008(p + 0x35c, (u16)a);
}


int func_021747F4(int a, int b)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), b, 0x227, 8, a, 0, 0, 0);
}

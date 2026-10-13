/*
 * file:     unit_021E7164.c
 * unit:     yes
 * function: func_021E7164, func_021E71D8, func_021E71E4, func_021E7270, func_021E727C, func_021E72F4, func_021E7300, func_021E7320, func_021E732C, func_021E737C, func_021E7388, func_021E7414, func_021E7420
 * address:  0x021E7164
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689C93C  0x0689C93C  thumb
 *   func_0689D064  0x0689D064  thumb
 *   func_0689D174  0x0689D174  thumb
 *   func_0689D184  0x0689D184  thumb
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021C81C8  0x021C81C8  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   d_021F24EC     0x021F24EC  data   ov093  a4
 *   func_021C812C  0x021C812C  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   func_021C8138  0x021C8138  thumb  ov093
 *   func_021C8130  0x021C8130  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   d_021F2624     0x021F2624  data   ov093  a4
 *   d_021F2834     0x021F2834  data   ov093  a4
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   BTLV_CORE_PackByteTwice  0x021E8CF0  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F27F4     0x021F27F4  data   ov093  a4
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F282C     0x021F282C  data   ov093  a4
 *   d_021F27DC     0x021F27DC  data   ov093  a4
 */
#include "../../matched/include/Obj13541.h"
#include "../../matched/include/Obj07835.h"
#include "../../matched/include/Obj07836.h"

struct Q7;
struct QQ;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021C81C8(u8 *p, u8 *x, int flag);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);
extern u8 *func_021C812C(u8 *p);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern u16 func_021C8138(struct Q7 *p);
extern int func_0689D064(int a, int b, int c);
extern u8 *func_021C8130(u8 *p);
extern int func_0689D174(int a, int b);
extern int func_0689D184(int a, int b, int c);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern void BTL_EVENT_MultiplyVar(int key, int m);
extern void *func_021C88A4(char *p, int a, int b);
extern int BTLV_CORE_PackByteTwice(int a);
extern void func_021C88C8(void *a, void *b);
extern int func_021D59B4(u8 *p, int k);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 v);
extern int func_0689C93C(u16 k);
void func_021E7164(int u, int a, int b);
int *func_021E71D8(int *p);
void func_021E71E4(int a, int b, int c);
int *func_021E7270(int *p);
void func_021E727C(int a, int b, int c);
int *func_021E72F4(int *p);
void func_021E7300(int a, int b, int c);
int *func_021E7320(int *p);
void func_021E732C(int a, int b, int c);
int *func_021E737C(int *p);
void func_021E7388(int a, void *b, int c);
int *func_021E7414(int *p);
void func_021E7420(int a, int b, int c);
extern int d_021F24EC[];
extern int d_021F2624[];
extern int d_021F2834[];
extern int d_021F27F4[];
extern int d_021F282C[];
extern int d_021F27DC[];


void func_021E7164(int u, int a, int b)
{
    int x, y, q, v;

    if (b == BTL_EVENT_GetVar(3)) {
        x = (int)func_021C7CF4((int *)a, b);
        y = (int)func_021C7CF4((int *)a, (u8)BTL_EVENT_GetVar(4));
        x = func_021C81C8((u8 *)a, (u8 *)x, 0);
        y = func_021C81C8((u8 *)a, (u8 *)y, 0);
        q = x / y;
        if (q >= 4)
            v = 150;
        else if (q >= 3)
            v = 120;
        else if (q >= 2)
            v = 80;
        else {
            v = 60;
            if (q < 1)
                v = 40;
        }
        BTL_EVENT_OverwriteVar(0x30, v);
    }
}


int *func_021E71D8(int *p)
{
    *p = 1;
    return d_021F24EC;
}


/*
 * The decrement inside the call argument (`i--`) is what puts the `subs`
 * before the result test; a `for (...; i--)` step lands it after the branch.
 */
void func_021E71E4(int a, int b, int c)
{
    int x, y, i, v;
    u32 n;

    if (c == BTL_EVENT_GetVar(3)) {
        x = (int)func_021C812C((u8 *)b);
        y = BTL_EVENT_GetFactorKey((void *)a);
        i = func_021C8138((struct Q7 *)b) - 1;
        n = 0;
        for (; i >= 0;) {
            if (func_0689D064(x, y, i--) == 0)
                break;
            n++;
        }
        switch (n) {
        case 0: v = 0x28; break;
        case 1: v = 0x50; break;
        case 2: v = 0x78; break;
        case 3: v = 0xa0; break;
        default: v = 0xc8; break;
        }
        BTL_EVENT_OverwriteVar(0x30, v);
    }
}


int *func_021E7270(int *p)
{
    *p = 1;
    return d_021F2624;
}


void func_021E727C(int a, int b, int c)
{
    int x;
    u32 n;
    u8 i;

    if (c == BTL_EVENT_GetVar(3)) {
        x = (int)func_021C8130((u8 *)b);
        n = func_0689D174(x, 1);
        for (i = 0; i < n; i++) {
            if (func_021B9A24(c, func_0689D184(x, 1, i)) != 0) {
                BTL_EVENT_MultiplyVar(0x31, 0x2000);
                return;
            }
        }
    }
}


int *func_021E72F4(int *p)
{
    *p = 1;
    return d_021F2834;
}


void func_021E7300(int a, int b, int c)
{
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        k = BTL_EVENT_GetVar(4);
        BTL_EVENT_OverwriteVar(0x3b, k);
    }
}


int *func_021E7320(int *p)
{
    *p = 1;
    return d_021F282C;
}


void func_021E732C(int a, int b, int c)
{
    u32 i;
    u32 n;
    u8 *p;

    if (c == BTL_EVENT_GetVar(3)) {
        n = BTL_EVENT_GetVar(5);
        for (i = 0; i < n; i++) {
            p = func_021C88A4((char *)b, 0x14, c);
            ((struct Obj13541 *)p)->f4 = BTLV_CORE_PackByteTwice(10);
            ((struct Obj13541 *)p)->f6 = BTL_EVENT_GetVar(i + 6);
            func_021C88C8((void *)b, p);
        }
    }
}


int *func_021E737C(int *p)
{
    *p = 1;
    return d_021F27F4;
}


void func_021E7388(int a, void *b, int c)
{
    u32 i;
    u32 n;
    u8 *m;

    if (c == BTL_EVENT_GetVar(3)) {
        n = BTL_EVENT_GetVar(5);
        for (i = 0; i < n; i++) {
            if (func_021D59B4(func_021C7CF4(b, (u8)BTL_EVENT_GetVar(i + 6)), 0x10) != 0x36) {
                m = (u8 *)func_021C88A4(b, 0x1f, c);
                m[6] = BTL_EVENT_GetVar(i + 6);
                ((struct Obj07835 *)m)->f4 = 0x56;
                func_021C8838(m + 0xc, 2, 0x195);
                func_021C8860((struct S *)(m + 0xc), m[6]);
                func_021C8860((struct S *)(m + 0xc), ((struct Obj07835 *)m)->f4);
                func_021C88C8(b, m);
            }
        }
    }
}


int *func_021E7414(int *p)
{
    *p = 1;
    return d_021F27DC;
}


/*
 * The narrowed scan key is a `u8` local assigned from the call, then passed:
 * the inline cast `(u8)BTL_EVENT_GetVar(i + 6)` adds an `adds r1, r0` copy the
 * image does not have.
 */
void func_021E7420(int a, int b, int c)
{
    u16 k;
    u32 i;
    u32 n;
    u8 *p;
    u8 t;

    if (c == BTL_EVENT_GetVar(3)) {
        k = func_021D59B4(func_021C7CF4((int *)b, c), 0x10);
        if (func_0689C93C(k) == 0) {
            n = BTL_EVENT_GetVar(5);
            for (i = 0; i < n; i++) {
                t = BTL_EVENT_GetVar(i + 6);
                if (func_021D59B4(func_021C7CF4((int *)b, t), 0x10) != 0x36) {
                    p = func_021C88A4((char *)b, 0x1f, c);
                    ((struct Obj07836 *)p)->f6 = BTL_EVENT_GetVar(i + 6);
                    ((struct Obj07836 *)p)->f4 = k;
                    func_021C8838(p + 0xc, 2, 0x195);
                    func_021C8860((struct S *)(p + 0xc), ((struct Obj07836 *)p)->f6);
                    func_021C8860((struct S *)(p + 0xc), ((struct Obj07836 *)p)->f4);
                    func_021C88C8((void *)b, p);
                }
            }
        }
    }
}

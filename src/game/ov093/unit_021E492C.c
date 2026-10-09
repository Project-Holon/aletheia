/*
 * file:     unit_021E492C.c
 * unit:     yes
 * function: func_021E492C, func_021E493C, func_021E4948, func_021E4958, func_021E4A08, func_021E4A64, func_021E4A70, func_021E4AF4, func_021E4B00, func_021E4BA4
 * address:  0x021E492C
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
 *   d_021F2BA0     0x021F2BA0  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7FCC  0x021C7FCC  thumb  ov093
 *   func_021C7FE0  0x021C7FE0  thumb  ov093
 *   func_021C8120  0x021C8120  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021C83CC  0x021C83CC  thumb  ov093
 *   d_021F2744     0x021F2744  data   ov093  a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D67B8  0x021D67B8  thumb  ov093
 *   func_021D5778  0x021D5778  thumb  ov093
 *   func_021D5584  0x021D5584  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F273C     0x021F273C  data   ov093  a4
 *   d_021F25BC     0x021F25BC  data   ov093  a4
 */
#include "../../matched/include/Obj10091.h"
#include "../../matched/include/Obj01898.h"

struct Q1;
struct S2;
struct Unk021D62A8;
struct UtilWork;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern u8 *func_021C7FCC(u8 *s, int k);
extern char *func_021C7FE0(u8 *p, int v);
extern u8 *func_021C8120(u8 *s, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern u8 func_021D5440(u8 *p);
extern u32 func_021C83CC(u8 *p);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D67B8(u8 *q);
extern int func_021D5778(u8 *q, int w);
extern u8 func_021D5584(struct UtilWork *p, u32 i);
extern void func_021C8860(struct S *p, u32 val);
void func_021E492C(int a, u8 *b, int c, int d);
int *func_021E493C(int *p);
void func_021E4948(int a, u8 *b, int c, int d);
void func_021E4958(int a0, u8 *s, int k, int a3, u16 x);
u8 func_021E4A08(u8 *x, u8 idx, u8 lim, u8 *buf);
int *func_021E4A64(int *p);
void func_021E4A70(int u, int a, int b);
int *func_021E4AF4(int *p);
void func_021E4B00(int a0, u8 *s, int k);
int *func_021E4BA4(int *p);
/* 021E4948  stack-arg wrapper: func_021E4958(a, b, c, d, 0x6f) */
extern int d_021F2BA0[];
extern int d_021F2744[];
extern int d_021F273C[];
extern int d_021F25BC[];



/* 021E492C  stack-arg wrapper: func_021E4958(a, b, c, d, 0x70) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #0x70; str r4, [sp]; bl func_021E4958; add sp, #4; pop {r3, r4, pc}.
 */
void func_021E492C(int a, u8 *b, int c, int d)
{
    func_021E4958(a, b, c, d, 0x70);
}



int *func_021E493C(int *p)
{
    *p = 3;
    return d_021F2BA0;
}



/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #0x6f; str r4, [sp]; bl func_021E4958; add sp, #4; pop {r3, r4, pc}.
 */
void func_021E4948(int a, u8 *b, int c, int d)
{
    func_021E4958(a, b, c, d, 0x6f);
}





void func_021E4958(int a0, u8 *s, int k, int a3, u16 x)
{
    u8 *a;
    int b;
    u8 *p;
    u8 *e;
    u8 *e2;
    u8 n;
    u8 i;

    if (k == func_021D775C(3)) {
        a = func_021C7FCC(s, k);
        b = (int)func_021C7FE0(s, k);
        p = func_021C8120(s, 12);
        e = func_021C88A4((char *)s, 4, k);
        func_021C8838(e + 4, 1, x);
        func_021C88C8(s, e);
        n = func_021E4A08(a, 0, 12, p);
        if (b != 0)
            n = n + func_021E4A08((u8 *)b, n, 12, p);
        if (n != 0) {
            if (n > 12)
                n = 12;
            e2 = func_021C88A4((char *)s, 0xb, k);
            e2[0x14] = n;
            for (i = 0; i < n; i++)
                e2[8 + i] = p[i];
            ((struct Obj10091 *)e2)->f4 = 0x24;
            func_021C88C8(s, e2);
        }
    }
}





u8 func_021E4A08(u8 *x, u8 idx, u8 lim, u8 *buf)
{
    u8 j;
    u8 i;
    u8 n = func_021B9B94((struct Q1 *)x);
    u8 *h;

    j = 0;
    for (i = 0; i < n; i++) {
        if (idx >= lim)
            break;
        h = func_021B9C00((struct S2 *)x, i);
        if (func_021D62A8((struct Unk021D62A8 *)h) != 0) {
            buf[idx] = func_021D5440(h);
            idx = idx + 1;
            j = j + 1;
        }
    }
    return j;
}




/*
 * Sibling of src/matched/ov170_func_021E2650.c and ov170_func_021E376C.c.
 * The image computes r + 0x1E
 * separately for func_021DEFEC and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 */
int *func_021E4A64(int *p)
{
    *p = 1;
    return d_021F2744;
}




void func_021E4A70(int u, int a, int b)
{
    u8 k;
    u32 w;
    enum { E_ONE = 1 } e;
    int t;
    u8 *s;

    if (b == func_021D775C(3)) {
        k = func_021D775C(6);
        w = func_021C83CC((u8 *)a);
        e = E_ONE;
        s = func_021C88A4((char *)a, 0xe, b);
        s[0xf] = e;
        s[0x10] = k;
        ((struct Obj01898 *)s)->f4 = e;
        t = e - 3;
        s[0xc] = t;
        ((struct Obj01898 *)s)->f8 = w;
        s[0xe] = 1;
        func_021C88C8((void *)a, s);
        s = func_021C88A4((char *)a, 0xe, b);
        s[0xf] = e;
        s[0x10] = k;
        ((struct Obj01898 *)s)->f4 = 3;
        s[0xc] = t;
        ((struct Obj01898 *)s)->f8 = w;
        s[0xe] = 1;
        func_021C88C8((void *)a, s);
        s = func_021C88A4((char *)a, 0x13, b);
        s[4] = b;
        func_021C88C8((void *)a, s);
    }
}



int *func_021E4AF4(int *p)
{
    *p = 1;
    return d_021F273C;
}



void func_021E4B00(int a0, u8 *s, int k)
{
    u8 v;
    u8 *q;
    int w;
    int t;
    u8 n;
    u8 *e;

    if (k == func_021D775C(3)) {
        v = func_021D775C(6);
        q = func_021C7CF4((int *)s, v);
        w = func_021D67B8(q);
        t = func_021D5778(q, w);
        if (t != 4) {
            n = (int)func_021D5584((struct UtilWork *)q, (int)t);
            if (n > 4)
                n = 4;
            if (n != 0) {
                e = func_021C88A4((char *)s, 10, k);
                e[5] = v;
                e[4] = n;
                e[6] = t;
                func_021C8838(e + 8, 2, 641);
                func_021C8860((struct S *)(e + 8), v);
                func_021C8860((struct S *)(e + 8), w);
                func_021C8860((struct S *)(e + 8), n);
                func_021C88C8(s, e);
            }
        }
    }
}



int *func_021E4BA4(int *p)
{
    *p = 1;
    return d_021F25BC;
}

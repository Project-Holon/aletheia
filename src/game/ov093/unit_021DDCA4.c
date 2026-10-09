/*
 * file:     unit_021DDCA4.c
 * unit:     yes
 * function: func_021DDCA4, func_021DDCB8, func_021DDCC4, func_021DDCD8, func_021DDD38, func_021DDD8C, func_021DDDC4, func_021DDDFC, func_021DDE30, func_021DDE74, func_021DDEA4, func_021DDEF0, func_021DDEFC, func_021DDF38, func_021DDF8C, func_021DDF98, func_021DDFDC, func_021DE000, func_021DE024, func_021DE058, func_021DE0C0
 * address:  0x021DDCA4
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
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C7EC4  0x021C7EC4  thumb  ov093
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021DCFF8 0x021DCFF8 thumb ov093
 *   func_021DD044 0x021DD044 thumb ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   d_021F184C     0x021F184C  data   ov093  a4
 *   func_021D76BC 0x021D76BC thumb ov093
 *   d_021F15EC     0x021F15EC  data   ov093  a4
 *   func_021E89D4  0x021E89D4  thumb  ov093
 *   d_021F160C 0x021F160C data a4
 *   d_021F1E0C     0x021F1E0C  data   ov093  a4
 */
#include "../../matched/include/Obj10067.h"
#include "../../matched/include/Obj21380.h"

struct S;
struct QQ;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u32 func_021D6D7C(u8 *p);
extern void func_021D7704(int a, int b);
extern u32 func_021C7EC4(u8 *p);
extern int func_021E85F8(int id);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(struct S *l, u32 v);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021C88C8(void *a, void *b);
extern int func_021DCFF8(int, int);
extern void func_021DD044(void *, void *, int);
extern int func_021D59B4(u8 *p, int k);
extern u32 func_021D7B60(void *p, u32 b);
extern int func_021D76BC(int, unsigned int);
extern int func_021E89D4(u32 a);
void func_021DDCA4(int a, u8 *b, int c, int *d);
int *func_021DDCB8(int *p);
void func_021DDCC4(int a, u8 *b, int c, int *d);
int func_021DDCD8(int a, u8 *b, int c, int *d, u8 e, int f);
void func_021DDD38(void *a, u8 *b, int c, int *d);
void func_021DDD8C(int a, void *b, int c);
void func_021DDDC4(int a, void *b, int c);
void func_021DDDFC(int a, void *b, int c);
void func_021DDE30(int a, int b, int c, int d, int e);
int func_021DDE74(int a, void *b, int c, unsigned int d);
int func_021DDEA4(void *a, int b, u32 n);
int *func_021DDEF0(int *p);
void func_021DDEFC(int a, void *b, int c);
void func_021DDF38(void *a, void *b, int c, int *d);
int *func_021DDF8C(int *p);
void func_021DDF98(int a, void *b, int c);
void func_021DDFDC(int a, void *b, int c, int d);
void func_021DE000(int a, void *b, int c, int d);
void func_021DE024(int a, void *b, int c, int d);
void func_021DE058(void *a, void *b, int c, u8 *a3);
void func_021DE0C0(void *a, void *b, int c, u8 *d);
void *func_021DE0D0(int *p);
extern int d_021F184C[];
extern int d_021F15EC[];
extern u8 d_021F160C[];
extern int d_021F1E0C[];



/*
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #8; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl func_021DDCD8; add sp, #8; pop {r4, pc}.
 */
void func_021DDCA4(int a, u8 *b, int c, int *d)
{
    func_021DDCD8(a, b, c, d, 8, 0);
}




int *func_021DDCB8(int *p)
{
    *p = 2;
    return d_021F184C;
}




/*
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0; str r4, [sp]; movs r4, #1; str r4, [sp, #4]; bl func_021DDCD8; add sp, #8; pop {r4, pc}.
 */
void func_021DDCC4(int a, u8 *b, int c, int *d)
{
    func_021DDCD8(a, b, c, d, 0, 1);
}








int func_021DDCD8(int a, u8 *b, int c, int *d, u8 e, int f)
{
    if (c == func_021D775C(4) && e == func_021D775C(0x16)
        && (f != 0 || func_021D775C(0x38) > 3)
        && func_021D6D7C(func_021C7CF4((int *)b, c)) == 0) {
        func_021D7704(0x35, 0x800);
        if (func_021C7EC4(b) == 0)
            *d = 1;
        return 1;
    }
    return 0;
}








void func_021DDD38(void *a, u8 *b, int c, int *d)
{
    u8 *p;
    if (*d != 0 && func_021E85F8(c) != 0) {
        p = func_021C88A4((char *)b, 0x23, c);
        func_021C8838(p + 8, 2, 219);
        func_021C8860((struct S *)(p + 8), c);
        func_021C8860((struct S *)(p + 8), func_021D70A8(a));
        func_021C88C8(b, p);
    }
}








/*
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
void func_021DDD8C(int a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        func_021C7CF4(b, c);
        func_021DDE30(a, (int)b, c, func_021DCFF8(a, 2), 1);
    }
}








void func_021DDDC4(int a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        func_021C7CF4(b, c);
        func_021DDE30(a, (int)b, c, func_021DCFF8(a, 2), 0);
    }
}








void func_021DDDFC(int a, void *b, int c)
{
    func_021C7CF4(b, c);
    if (func_021DDEA4(b, c, func_021DCFF8(a, 2)) != 0) func_021DD044((void *)a, b, c);
}








void func_021DDE30(int a, int b, int c, int d, int e)
{
    int r;

    if (c == func_021D775C(2)) {
        if (e != 0)
            r = func_021DDE74(a, (void *)b, c, d);
        else
            r = func_021DDEA4((void *)b, c, d);
        if (r != 0)
            func_021DD044((void *)a, (void *)b, c);
    }
}








int func_021DDE74(int a, void *b, int c, unsigned int d)
{
    if (c == func_021D775C(2) && (unsigned char)func_021D775C(46) <= 1) return func_021DDEA4(b, c, d);
    return 0;
}






int func_021DDEA4(void *a, int b, u32 n)
{
    void *m;
    u32 v;

    m = func_021C7CF4(a, b);
    if (func_021D59B4(m, 0x11) == 0x52 && n > 2)
        n >>= 1;
    if (n == 0)
        n = 1;
    if ((u32)func_021D59B4(m, 0xe) > 1) {
        v = func_021D59B4(m, 0xd);
        if (v <= func_021D7B60(m, n))
            return 1;
    }
    return 0;
}



int *func_021DDEF0(int *p)
{
    *p = 2;
    return d_021F15EC;
}



void func_021DDEFC(int a, void *b, int c)
{
    if (c == func_021D775C(2) && func_021DDEA4(b, c, 4) != 0 && func_021D76BC(17, 2) != 0) func_021DD044((void *)a, b, c);
}




void func_021DDF38(void *a, void *b, int c, int *d)
{
    u8 *m;

    if (c == func_021D775C(2)) {
        m = (u8 *)func_021C88A4(b, 4, c);
        func_021C8838(m + 4, 2, 0x401);
        func_021C8860((struct S *)(m + 4), c);
        func_021C8860((struct S *)(m + 4), func_021D70A8(a));
        func_021C88C8(b, m);
        *d = 0;
    }
}


int *func_021DDF8C(int *p)
{
    *p = 6;
    return d_021F1E0C;
}


void func_021DDF98(int a, void *b, int c)
{
    u8 j;

    if (c == func_021D775C(2)) {
        func_021C7CF4(b, c);
        j = func_021DCFF8(a, 2);
        if (func_021DDE74(a, (void *)((int)b), c, j) != 0)
            func_021DD044((void *)a, (void *)((int)b), c);
    }
}




void func_021DDFDC(int a, void *b, int c, int d)
{
    if (c == func_021D775C(2)) func_021DE024(a, b, c, d);
}




void func_021DE000(int a, void *b, int c, int d)
{
    if (func_021D775C(12) != 6) func_021DDFDC(a, b, c, d);
}




void func_021DE024(int a, void *b, int c, int d)
{
    unsigned char n;
    func_021C7CF4(b, c);
    n = func_021DCFF8(a, 2);
    if (func_021DDEA4(b, c, n) != 0) func_021DD044((void *)a, b, c);
}




void func_021DE058(void *a, void *b, int c, u8 *a3)
{
    u8 *m;

    if (c == func_021D775C(2)) {
        func_021C7CF4(b, c);
        m = (u8 *)func_021C88A4(b, 0xc, c);
        m[0xf] = c;
        ((struct Obj10067 *)m)->f4 = 0x22;
        ((struct Obj10067 *)m)->f8 = func_021E89D4(0x78);
        func_021C8838(m + 0x14, 2, 0x404);
        func_021C8860((struct S *)(m + 0x14), c);
        func_021C8860((struct S *)(m + 0x14), func_021D70A8(a));
        func_021C88C8(b, m);
    }
}



void func_021DE0C0(void *a, void *b, int c, u8 *d) { if (((struct Obj21380 *)d)->f18) func_021DE058(a,b,c,d); }



/*
 * interface: r3 is untouched before bl; forward its incoming fourth argument.
 * lever: fourth argument keeps r3 live; three arguments give ldr/cmp r3.
 */
void *func_021DE0D0(int *p) { *p=2; return d_021F160C; }

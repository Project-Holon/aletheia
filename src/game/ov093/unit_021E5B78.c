/*
 * file:     unit_021E5B78.c
 * unit:     yes
 * function: func_021E5B6C, func_021E5B78, func_021E5C18, func_021E5C64, func_021E5C88, func_021E5CC8, func_021E5CD4, func_021E5D24, func_021E5D54, func_021E5DAC, func_021E5E2C, func_021E5E70, func_021E5E7C, func_021E5EB8, func_021E5F0C, func_021E5F18, func_021E5F30, func_021E5F48, func_021E5FD0, func_021E5FEC, func_021E6004, func_021E6010, func_021E6054, func_021E60A8, func_021E6120, func_021E612C, func_021E6158
 * address:  0x021E5B6C
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
 *   d_021F2454     0x021F2454  data   ov093  a4
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C7F4C  0x021C7F4C  thumb  ov093
 *   func_021C8010  0x021C8010  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F2CD8     0x021F2CD8  data   ov093  a4
 *   func_021C8168  0x021C8168  thumb  ov093
 *   func_021C815C  0x021C815C  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021D70C8  0x021D70C8  thumb  ov093
 *   func_021C88B4  0x021C88B4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 *   func_021C824C  0x021C824C  thumb  ov093
 *   func_021E869C  0x021E869C  thumb  ov093
 *   d_021F2EC8     0x021F2EC8  data   ov093  a4
 *   func_021E8940  0x021E8940  thumb  ov093
 *   d_021F2A38     0x021F2A38  data   ov093  a4
 *   func_021C8180   0x021C8180  thumb ov093
 *   func_021D5B68   0x021D5B68  thumb ov093
 *   func_021D5BB0   0x021D5BB0  thumb ov093
 *   func_021D7090   0x021D7090  thumb ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021D7040   0x021D7040  thumb
 *   d_021F2EF0     0x021F2EF0  data   ov093  a4
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   _u32_div_f     0x0209C2B0  arm
 *   func_021C7FCC  0x021C7FCC  thumb  ov093
 *   func_021B9B94  0x021B9B94  thumb  ov093
 *   func_021B9C00  0x021B9C00  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021D5B7C  0x021D5B7C  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   d_021F2A68     0x021F2A68  data   ov093  a4
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   d_021F242C     0x021F242C  data   ov093  a4
 *   d_021F240C     0x021F240C  data   ov093  a4
 */
#include "../../matched/include/Obj02791.h"
#include "../../matched/include/Obj10097.h"
#include "../../matched/include/Obj21516.h"
#include "../../matched/include/Obj13529.h"

struct Flag;
struct Unk021D62A8;
struct S;
struct QI;
struct UtilWork;
struct Q1;
struct S2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct Word { u32 v; } Word;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern int func_021C7F24(u8 *p, int i);
extern int func_021C7F4C(struct Flag *p);
extern int func_021C8010(u8 *p, unsigned int v);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern int func_021C8168(void *p);
extern int func_021C815C(int *p);
extern int func_021D76BC(int key, u32 val);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021D70C8(void *a);
extern void func_021C88B4(void *a, int k, int b);
extern void func_021C8838(void *l, int a, int b);
extern void func_021C8860(struct S *, unsigned int);
extern u16 func_021D5B40(struct QI *p);
extern u32 func_021D805C(void *p, u32 n);
extern int func_021C824C(u8 *p, int v);
extern int func_021E869C(void *p, int id);
extern Word func_021E8940(u8 v);
int func_021C8180(int *p);
int func_021D5B68(void *p);
int func_021D5BB0(struct UtilWork *p, u32 n);
void func_021D7090(u8 *p);
extern void func_021D7704(int a, int b);
extern int func_021D59B4(u8 *p, int k);
extern u32 _u32_div_f(u32, u32);
extern char *func_021C7FCC(u8 *p, int i);
extern u8 func_021B9B94(struct Q1 *p);
extern u8 *func_021B9C00(struct S2 *p, u32 i);
extern u8 func_021D5440(u8 *p);
extern int func_021D5B7C(void *m);
extern int func_021D62A8(struct Unk021D62A8 *p);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern int d_021F2454[];
int *func_021E5B6C(int *p);

int *func_021E5B6C(int *p)
{
    *p = 1;
    return d_021F2454;
}


void func_021E5B78(int a, void *b, int c);
int *func_021E5C0C(int *p);
void func_021E5C18(u8 *p, void *a, int b);
void func_021E5C64(void *a, void *b, int c);
void func_021E5C88(u8 *p, void *a, int b);
int *func_021E5CC8(int *p);
void func_021E5CD4(u8 *p, void *a, int b);
void func_021E5D24(int a, void *b, int c);
void func_021E5D54(u8 *p, void *a, int b);
void func_021E5DAC(u8 *p, void *a, int b, int *c);
void func_021E5E2C(u8 *p, void *a, int b, int *c);
int *func_021E5E70(int *p);
void func_021E5E7C(int a, void *b, int c);
void func_021E5EB8(u8 *p, void *a, int b);
int *func_021E5F0C(int *p);
void func_021E5F18(int a, int b, int c);
void func_021E5F30(int a, int b, int c);
void func_021E5F48(void *a, int b, int c, int *d);
void func_021E5FD0(int a, int b, int c, int *d);
void func_021E5FEC(int a, int b, int c);
int *func_021E6004(int *p);
void func_021E6010(u8 *p, void *a, int b, int *c);
void func_021E6054(u8 *p, void *a, int b, int *c);
u8 *func_021E60A8(void *a, u32 b, u8 c);
int *func_021E6120(int *p);
void func_021E612C(int a, void *b, int c);
int *func_021E6158(int *p);
extern int d_021F2CD8[];
extern int d_021F2EC8[];
extern int d_021F2A38[];
/* 021E5F18  shape F1: gate on func_021D775C(3) */
extern int d_021F2EF0[];
extern int d_021F2A68[];
extern int d_021F242C[];
extern int d_021F240C[];









void func_021E5B78(int a, void *b, int c)
{
    u8 *m;

    if (c == func_021D775C(3) && func_021C7F24(b, c) != 0 && func_021C7F4C(b) != 0) {
        m = (u8 *)func_021C88A4(b, 0x1e, c);
        ((struct Obj02791 *)m)->f4 = 4;
        m[8] = func_021C8010(b, c);
        ((struct Obj02791 *)m)->fC = c;
        m[0x1c] = 1;
        func_021C88C8(b, m);
        m = (u8 *)func_021C88A4(b, 0x17, c);
        m[8] = c;
        ((struct Obj02791 *)m)->f4 = 0xe;
        ((struct Obj02791 *)m)->f0 |= 1 << 24;
        func_021C88C8(b, m);
        m = (u8 *)func_021C88A4(b, 0x29, c);
        m[0x4c] = c;
        m[0x4d] = 1;
        ((struct Obj02791 *)m)->f0 |= 1 << 24;
        func_021C88C8(b, m);
    }
}









int *func_021E5C0C(int *p)
{
    *p = 3;
    return d_021F2CD8;
}









void func_021E5C18(u8 *p, void *a, int b)
{
    void *r;
    if (func_021C8168(a) != 0 || func_021C815C(a) != 0)
        func_021D76BC(0x22, 0x1a);
    r = func_021C7CF4(a, b);
    if (func_021D62C4(r, 8) != 0 && func_021D62C4(r, 0x16) != 0)
        func_021D76BC(0x22, 0x1a);
}








void func_021E5C64(void *a, void *b, int c)
{
    if (c == func_021D775C(3)) {
        func_021D70C8(a);
        func_021C88B4(b, 0x28, c);
    }
}







void func_021E5C88(u8 *p, void *a, int b)
{
    u8 *r;
    if (func_021D76BC(0x51, 1) != 0) {
        r = func_021C88A4(a, 4, b);
        func_021C8838(r + 4, 2, 0x2ff);
        func_021C8860((struct S *)(r + 4), b);
        func_021C88C8(a, r);
    }
}






int *func_021E5CC8(int *p)
{
    *p = 5;
    return d_021F2EC8;
}






void func_021E5CD4(u8 *p, void *a, int b)
{
    if (b != func_021D775C(2))
        return;
    {
        void *r = func_021C7CF4(a, b);
        u16 v = (u32)func_021D5B40(r);
        if (v == 0 || func_021D805C((void *)v, 10) == 0 || func_021C824C(a, b) == 0
            || func_021E869C(a, b) != 0)
            func_021D76BC(0x22, 0x1a);
    }
}










void func_021E5D24(int a, void *b, int c)
{
    if (c == func_021D775C(3)) {
        u16 n = (int)func_021D5B40(func_021C7CF4(b, c));
        func_021D76BC(0x30, func_021D805C((void *)n, 10));
    }
}










void func_021E5D54(u8 *p, void *a, int b)
{
    void *r;
    u16 v;
    u8 *q;
    if (b != func_021D775C(3))
        return;
    r = func_021C7CF4(a, b);
    v = (u32)func_021D5B40(r);
    if (v == 0)
        return;
    q = func_021C88A4(a, 4, b);
    func_021C8838(q + 4, 2, 0x30b);
    func_021C8860((struct S *)(q + 4), b);
    func_021C8860((struct S *)(q + 4), v);
    func_021C88C8(a, q);
}








void func_021E5DAC(u8 *p, void *a, int b, int *c)
{
    void *r;
    u16 v;
    u8 *q;
    if (b != func_021D775C(3))
        return;
    r = func_021C7CF4(a, b);
    v = (u32)func_021D5B40(r);
    if (v == 0)
        return;
    q = func_021C88A4(a, 0x23, b);
    ((struct Obj10097 *)q)->f4 = 1;
    func_021C88C8(a, q);
    *c = 1;
    if (func_021D775C(0x46) == 0 && func_021D775C(0x47) == 0 && func_021D805C((void *)v, 9) != 0) {
        q = func_021C88A4(a, 0x22, b);
        q[4] = func_021D775C(4);
        *(u16 *)(q + 6) = v;
        func_021C88C8(a, q);
    }
}







void func_021E5E2C(u8 *p, void *a, int b, int *c)
{
    void *r;
    u8 *q;
    if (b != func_021D775C(2))
        return;
    if (*c != 0)
        return;
    r = func_021C7CF4(a, b);
    if ((u16)(u32)func_021D5B40(r) != 0) {
        q = func_021C88A4(a, 0x23, b);
        ((struct Obj21516 *)q)->f4 = 1;
        func_021C88C8(a, q);
    }
}





int *func_021E5E70(int *p)
{
    *p = 2;
    return d_021F2A38;
}





void func_021E5E7C(int a, void *b, int c)
{
    void *r;

    if (c == func_021D775C(2)) {
        r = func_021C7CF4(b, c);
        if (func_021D62C4(r, 0x15) != 0 || func_021D62C4(r, 0x1f) != 0)
            func_021D76BC(0x22, 0x1a);
    }
}






void func_021E5EB8(u8 *p, void *a, int b)
{
    u8 *q;
    if (b != func_021D775C(3))
        return;
    q = func_021C88A4(a, 0xc, b);
    q[0xf] = b;
    ((struct Obj13529 *)q)->f4 = 0x1e;
    *(Word *)(q + 8) = func_021E8940(5);
    func_021C8838(q + 0x14, 2, 0x292);
    func_021C8860((struct S *)(q + 0x14), b);
    func_021C88C8(a, q);
}




int *func_021E5F0C(int *p)
{
    *p = 5;
    return d_021F2EF0;
}




/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E5F2E; movs r0, #0x51; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
void func_021E5F18(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x51, 1);
}







/* 021E5F30  shape F1: gate on func_021D775C(3) */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E5F46; movs r0, #0x42; movs r1, #0; bl func_021D76BC; pop {r4, pc}.
 */
void func_021E5F30(int a, int b, int c)
{
    if (c == func_021D775C(3))
        func_021D76BC(0x42, 0);
}







/*
 * func_021C8180(b) must exceed 1, the gate is func_021D775C(3), and the
 * (u8) of func_021D775C(6) keys func_021C7CF4 for two rejection tests.  Record
 * #4 is published as a two-string record, its key goes back through the d
 * pointer, and the first argument is left for the very last call.  a and d
 * both live on the stack because all four saved registers are taken.
 */
void func_021E5F48(void *a, int b, int c, int *d)
{
    u8 k;
    void *r;
    u8 *p;

    if ((u32)func_021C8180((int *)b) <= 1)
        return;
    if (c != func_021D775C(3))
        return;
    k = (u8)func_021D775C(6);
    r = func_021C7CF4((int *)b, k);
    if (func_021D5B68(r) != 0)
        return;
    if (func_021D5BB0(r, 1) != 0)
        return;
    p = func_021C88A4((char *)b, 4, c);
    func_021C8838(p + 4, 2, 0x414);
    func_021C8860((struct S *)(p + 4), c);
    func_021C8860((struct S *)(p + 4), k);
    func_021C88C8((void *)b, p);
    *d = k;
    func_021D7090(a);
}







void func_021E5FD0(int a, int b, int c, int *d)
{
    if (*d == func_021D775C(3))
        func_021D7704(0x31, 3 << 11);
}





/* 021E5FEC  shape F3: gate on func_021D775C(2) then func_021D7040 */
/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r3, r4, r5, lr}; adds r5, r0, #0; movs r0, #2; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E6002; adds r0, r5, #0; bl func_021D7040; pop {r3, r4, r5, pc}.
 */
void func_021E5FEC(int a, int b, int c)
{
    if (c == func_021D775C(2))
        func_021D7040(a);
}



int *func_021E6004(int *p)
{
    *p = 2;
    return d_021F2A68;
}



void func_021E6010(u8 *p, void *a, int b, int *c)
{
    int n;
    u32 i;
    if (b != func_021D775C(3))
        return;
    n = 0;
    for (i = 0; i < 6; i++) {
        if (func_021E60A8(a, b, i) != 0)
            n++;
    }
    if (n == 0)
        n = 1;
    func_021D76BC(0x2a, n);
    *c = 0;
}





void func_021E6054(u8 *p, void *a, int b, int *c)
{
    void *r;
    if (b != func_021D775C(3))
        return;
    r = func_021E60A8(a, b, *c);
    if (r == 0)
        r = func_021C7CF4(a, b);
    *c = *c + 1;
    if (*c >= 6)
        *c = 0;
    func_021D76BC(0x30, _u32_div_f(func_021D59B4(r, 0x15), 10) + 5);
}




u8 *func_021E60A8(void *a, u32 b, u8 c)
{
    void *s;
    u32 n;
    u32 i;
    u8 *t;
    int r;
    s = func_021C7FCC(a, b);
    n = func_021B9B94(s);
    if (c >= n)
        return 0;
    for (i = 0; i < n; i++) {
        r = 0;
        t = func_021B9C00(s, (u8)i);
        if (b == func_021D5440(t))
            r = 1;
        else if (func_021D5B7C(t) != 0 && func_021D62A8((struct Unk021D62A8 *)t) == 0)
            r = 1;
        if (r != 0) {
            if (c == 0)
                return t;
            c = c - 1;
        }
    }
    return 0;
}


int *func_021E6120(int *p)
{
    *p = 1;
    return d_021F242C;
}


void func_021E612C(int a, void *b, int c)
{
    if (c == func_021D775C(2)) {
        if (func_021D5BDC(func_021C7CF4(b, c), 0) != 0)
            func_021D76BC(0x22, 0x1a);
    }
}


int *func_021E6158(int *p)
{
    *p = 1;
    return d_021F240C;
}

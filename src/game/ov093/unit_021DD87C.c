/*
 * file:     unit_021DD87C.c
 * unit:     yes
 * function: func_021DD87C, func_021DD88C, func_021DD898, func_021DD8A8, func_021DD8B4, func_021DD8C4, func_021DD8D0, func_021DD8E0, func_021DD8EC, func_021DD8FC, func_021DD908, func_021DD980, func_021DD98C, func_021DD9E8, func_021DDA1C, func_021DDA28, func_021DDA6C, func_021DDAB8
 * address:  0x021DD87C
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
 *   d_021F1CF4     0x021F1CF4  data   ov093  a4
 *   d_021F1D1C     0x021F1D1C  data   ov093  a4
 *   d_021F1D44     0x021F1D44  data   ov093  a4
 *   d_021F1D6C     0x021F1D6C  data   ov093  a4
 *   func_021D775C   0x021D775C  thumb ov093
 *   func_021C7CF4   0x021C7CF4  thumb ov093
 *   func_021D5BDC   0x021D5BDC  thumb ov093
 *   func_021C88A4   0x021C88A4  thumb ov093
 *   func_021C88C8   0x021C88C8  thumb ov093
 *   func_021C8838   0x021C8838  thumb ov093
 *   func_021C8860   0x021C8860  thumb ov093
 *   func_021D70A8   0x021D70A8  thumb ov093
 *   d_021F1D94     0x021F1D94  data   ov093  a4
 *   func_021C8120  0x021C8120  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   d_021F1364     0x021F1364  data  ov093  a1
 *   d_021F1DBC     0x021F1DBC  data   ov093  a4
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 *   func_021DCFF8  0x021DCFF8  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   d_021F16CC     0x021F16CC  data   ov093  a4
 *   d_021F175C     0x021F175C  data   ov093  a4
 */
#include "../../matched/include/Obj12152.h"
#include "../../matched/include/Obj07818.h"
#include "../../matched/include/Obj13487.h"

struct QQ;
struct UtilWork;
struct S;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

int func_021D775C(int a);
void *func_021C7CF4(int *p, int i);
int func_021D5BDC(struct UtilWork *p, u32 n);
void *func_021C88A4(char *p, int a, int b);
void func_021C88C8(void *a, void *b);
void func_021C8838(void *p, int a, int b);
void func_021C8860(struct S *p, unsigned int a);
extern u16 func_021D70A8(struct QQ *p);
extern u8 *func_021C8120(u8 *p, int b);
extern int func_021D5D14(s8 *p, int i, int sign);
extern u32 func_021D78AC(u32 range);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021DD044(void *a, void *b, int c);
extern int func_021DCFF8(int a, int b);
extern int func_021D7B74(u8 *p, u32 k);
void func_021DD87C(int a, int b, int c);
int *func_021DD88C(int *p);
void func_021DD898(int a, int b, int c);
int *func_021DD8A8(int *p);
void func_021DD8B4(int a, int b, int c);
int *func_021DD8C4(int *p);
void func_021DD8D0(int a, int b, int c);
int *func_021DD8E0(int *p);
void func_021DD8EC(int a, int b, int c);
int *func_021DD8FC(int *p);
void func_021DD908(void *a, int b, int c);
int *func_021DD980(int *p);
void func_021DD98C(int x, void *a, u8 b);
void func_021DD9E8(void *a, int b, int c, int d);
int *func_021DDA1C(int *p);
void func_021DDA28(u8 *a, u8 *b, int c);
void func_021DDA6C(int a, u8 *b, int c);
int *func_021DDAB8(int *p);
/* 021DD898  shifted 3-arg wrapper -> func_021DD9E8(..., 0x2, 1) */
extern int d_021F1CF4[];
/* 021DD8B4  shifted 3-arg wrapper -> func_021DD9E8(..., 0x5, 1) */
extern int d_021F1D1C[];
/* 021DD8D0  shifted 3-arg wrapper -> func_021DD9E8(..., 0x3, 1) */
extern int d_021F1D44[];
/* 021DD8EC  shifted 3-arg wrapper -> func_021DD9E8(..., 0x4, 1) */
extern int d_021F1D6C[];
extern int d_021F1D94[];
extern u8 d_021F1364[5];
extern int d_021F1DBC[];
extern int d_021F16CC[];
extern int d_021F175C[];







/* 021DD87C  shifted 3-arg wrapper -> func_021DD9E8(..., 0x1, 1) */
/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #1; movs r3, #1; bl func_021DD9E8; pop {r3, pc}.
 */
void func_021DD87C(int a, int b, int c)
{
    func_021DD9E8((void *)b, c, 0x1, 1);
}







int *func_021DD88C(int *p)
{
    *p = 5;
    return d_021F1CF4;
}







/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #2; movs r3, #1; bl func_021DD9E8; pop {r3, pc}.
 */
void func_021DD898(int a, int b, int c)
{
    func_021DD9E8((void *)b, c, 0x2, 1);
}






int *func_021DD8A8(int *p)
{
    *p = 5;
    return d_021F1D1C;
}






/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #5; movs r3, #1; bl func_021DD9E8; pop {r3, pc}.
 */
void func_021DD8B4(int a, int b, int c)
{
    func_021DD9E8((void *)b, c, 0x5, 1);
}





int *func_021DD8C4(int *p)
{
    *p = 5;
    return d_021F1D44;
}





void func_021DD8D0(int a, int b, int c)
{
    func_021DD9E8((void *)b, c, 0x3, 1);
}




int *func_021DD8E0(int *p)
{
    *p = 5;
    return d_021F1D6C;
}




/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; movs r2, #4; movs r3, #1; bl func_021DD9E8; pop {r3, pc}.
 */
void func_021DD8EC(int a, int b, int c)
{
    func_021DD9E8((void *)b, c, 0x4, 1);
}



int *func_021DD8FC(int *p)
{
    *p = 5;
    return d_021F1D94;
}



void func_021DD908(void *a, int b, int c)
{
    void *p, *q;

    if (c != func_021D775C(2))
        return;
    if (func_021D5BDC(func_021C7CF4((int *)b, c), 9) != 0)
        return;
    p = func_021C88A4((char *)b, 0x17, c);
    ((struct Obj12152 *)p)->f8 = c;
    ((struct Obj12152 *)p)->f4 = 9;
    func_021C88C8((void *)b, p);
    q = func_021C88A4((char *)b, 4, c);
    func_021C8838((u8 *)q + 4, 2, 0x3e9);
    func_021C8860((struct S *)((u8 *)q + 4), c);
    func_021C8860((struct S *)((u8 *)q + 4), func_021D70A8(a));
    func_021C88C8((void *)b, q);
}



/*
 * extent: two bytes of zero alignment padding after the return.
 */
int *func_021DD980(int *p)
{
    *p = 5;
    return d_021F1DBC;
}



void func_021DD98C(int x, void *a, u8 b)
{
    void *m = func_021C7CF4(a, b);
    u8 *buf = func_021C8120(a, 5);
    u32 n;
    u32 i;
    u8 e;

    i = 0;
    n = 0;
    for (; i < 5; i++) {
        e = d_021F1364[i];
        if (func_021D5D14(m, e, 1) != 0)
            buf[n++] = e;
    }
    if (n != 0)
        func_021DD9E8(a, b, buf[func_021D78AC(n)], 2);
}




void func_021DD9E8(void *a, int b, int c, int d)
{
    u8 *p;
    if (b == func_021D775C(2)) {
        p = func_021C88A4(a, 0xe, b);
        ((struct Obj07818 *)p)->f4 = c;
        p[0xc] = d;
        p[0xf] = 1;
        p[0x10] = b;
        func_021C88C8(a, p);
    }
}



int *func_021DDA1C(int *p)
{
    *p = 2;
    return d_021F16CC;
}



void func_021DDA28(u8 *a, u8 *b, int c)
{
    if (c == func_021D775C(4) && func_021D775C(0x46) == 0 && func_021D775C(0x38) > 3
        && func_021D62C4(func_021C7CF4((int *)b, c), 0xf) == 0)
        func_021DD044(a, b, c);
}




void func_021DDA6C(int a, u8 *b, int c)
{
    void *m;
    u8 *p;
    u8 k;
    if (c == func_021D775C(2)) {
        m = func_021C7CF4((int *)b, c);
        k = func_021DCFF8(a, 2);
        p = func_021C88A4((char *)b, 5, c);
        p[6] = c;
        ((struct Obj13487 *)p)->f4 = func_021D7B74(m, k);
        func_021C88C8(b, p);
    }
}



int *func_021DDAB8(int *p)
{
    *p = 2;
    return d_021F175C;
}

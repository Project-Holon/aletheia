/*
 * file:     unit_021E1E44.c
 * unit:     yes
 * function: func_021E1E44, func_021E1EAC, func_021E1EB8, func_021E1F18, func_021E1F44, func_021E1F70, func_021E1F90, func_021E1F9C, func_021E1FCC, func_021E1FF8, func_021E2004, func_021E2030
 * address:  0x021E1E44
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
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021D76BC  0x021D76BC  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021D7040  0x021D7040  thumb  ov093
 *   d_021F2DD8     0x021F2DD8  data   ov093  a4
 *   d_021F2988     0x021F2988  data   ov093  a4
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021E89D4  0x021E89D4  thumb  ov093
 *   d_021F250C     0x021F250C  data   ov093  a4
 *   d_021F247C     0x021F247C  data   ov093  a4
 */
#include "../../matched/include/Obj13506.h"

struct UtilWork;
struct S;
struct QQ;
struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct Word { u32 v; } Word;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern u16 func_021D70A8(struct QQ *p);
extern int func_021D76BC(int key, u32 val);
extern void func_021D7704(int a, int b);
extern void func_021D7040(struct Node *n);
extern int func_021C7D00(u8 *p, int b);
extern Word func_021E89D4(int a);
void func_021E1E44(int u, int a, int b);
int *func_021E1EAC(int *p);
void func_021E1EB8(void *u, int a, int b, int *p);
void func_021E1F18(int u, int a, int b, int *p);
void func_021E1F44(void *u, int a, int b, int *p);
void func_021E1F70(void *u, int a, int b, int *p);
int *func_021E1F90(int *p);
void func_021E1F9C(int u, int a, int b);
void func_021E1FCC(void *u, int a, int b);
int *func_021E1FF8(int *p);
void func_021E2004(int u, int a, int b);
int *func_021E2030(int *p);
extern int d_021F2DD8[];
extern int d_021F2988[];
extern int d_021F250C[];
extern int d_021F247C[];




/*
 * The tail after the pop (movs r1,#4; str r1,[r0]; ldr r0,[pc]; bx lr) is an
 * unlabelled follower stub.
 */
void func_021E1E44(int u, int a, int b)
{
    u8 *r;
    u8 *s;

    if (b == func_021D775C(3)) {
        if (func_021D5BDC(func_021C7CF4((int *)a, b), 9) == 0) {
            r = func_021C88A4((char *)a, 0x17, b);
            r[8] = b;
            ((struct Obj13506 *)r)->f4 = 9;
            func_021C88C8((void *)a, r);
            s = func_021C88A4((char *)a, 4, b);
            func_021C8838(s + 4, 2, 0x411);
            func_021C8860((struct S *)(s + 4), b);
            func_021C88C8((void *)a, s);
        }
    }
}




/*
 * Leaf: -40000 - (a * 100 + b), the plain two-term member of the
 *  *  func_021E20B8 family (that one adds the 50-byte header).
 */
int *func_021E1EAC(int *p)
{
    *p = 4;
    return d_021F2DD8;
}




void func_021E1EB8(void *u, int a, int b, int *p)
{
    u8 *s;

    if (b == func_021D775C(2)) {
        if (func_021D775C(0x12) == func_021D70A8(u)) {
            s = func_021C88A4((char *)a, 4, b);
            func_021C8838(s + 4, 2, 0x298);
            func_021C8860((struct S *)(s + 4), b);
            func_021C88C8((void *)a, s);
            func_021D76BC(0x3e, 1);
            p[6] = 1;
            p[0] = 1;
        }
    }
}







void func_021E1F18(int u, int a, int b, int *p)
{
    if (*p == 2) {
        if (b == func_021D775C(3)) {
            if (func_021D775C(0x16) == 0xc)
                func_021D7704(0x31, 0x2000);
        }
    }
}







void func_021E1F44(void *u, int a, int b, int *p)
{
    if (b == func_021D775C(3)) {
        if (func_021D775C(0x12) != func_021D70A8(u))
            *p = 2;
    }
}





void func_021E1F70(void *u, int a, int b, int *p)
{
    if (b == func_021D775C(2)) {
        if (*p == 2)
            func_021D7040(u);
    }
}



int *func_021E1F90(int *p)
{
    *p = 2;
    return d_021F2988;
}



void func_021E1F9C(int u, int a, int b)
{
    u8 *s;

    if (b == func_021D775C(2)) {
        s = func_021C88A4((char *)a, 4, b);
        func_021C8838(s + 4, 1, 0x77);
        func_021C88C8((void *)a, s);
    }
}




void func_021E1FCC(void *u, int a, int b)
{
    if (b == func_021D775C(3)) {
        if (func_021D775C(0x12) == func_021D70A8(u))
            func_021D76BC(0x40, 0);
    }
}


int *func_021E1FF8(int *p)
{
    *p = 1;
    return d_021F250C;
}


void func_021E2004(int u, int a, int b)
{
    if (b == func_021D775C(3)) {
        Word t = func_021E89D4(func_021C7D00((u8 *)a, b));
        func_021D76BC(0x1e, t.v);
    }
}


int *func_021E2030(int *p)
{
    *p = 1;
    return d_021F247C;
}

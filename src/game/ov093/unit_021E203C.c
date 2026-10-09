/*
 * file:     unit_021E203C.c
 * unit:     yes
 * function: func_021E203C, func_021E208C, func_021E2098, func_021E20E0, func_021E2148, func_021E217C
 * address:  0x021E203C
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C83E8  0x021C83E8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021E03D8  0x021E03D8  thumb  ov093
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F2C78     0x021F2C78  data   ov093  a4
 *   d_021F2514     0x021F2514  data   ov093  a4
 */
#include "../../matched/include/Obj05220.h"

struct QQ;
struct S;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021C83E8(unsigned char *p, int i, int b);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021E03D8(u8 *a, int b);
extern int func_021D5B68(void *p);
extern void func_021C8860(struct S *p, u32 val);
void func_021E203C(int u, int a, int b);
int *func_021E208C(int *p);
void func_021E2098(void *u, int a, int b, int *p);
void func_021E20E0(int u, int a, int b);
void func_021E2148(void *u, int a, int b, int *p);
int *func_021E217C(int *p);
extern int d_021F2C78[];
extern int d_021F2514[];


void func_021E203C(int u, int a, int b)
{
    int t;
    u8 *s;

    if (b == func_021D775C(3)) {
        t = func_021D59B4(func_021C7CF4((int *)a, b), 0xf);
        if (func_021C83E8((unsigned char *)a, t * 5, b) != 0) {
            s = func_021C88A4((char *)a, 4, b);
            func_021C8838(s + 4, 1, 0x7a);
            func_021C88C8((void *)a, s);
        }
    }
}


int *func_021E208C(int *p)
{
    *p = 3;
    return d_021F2C78;
}


void func_021E2098(void *u, int a, int b, int *p)
{
    int t;

    if (b == func_021D775C(2)) {
        t = func_021D775C(0x12);
        if (t == func_021D70A8(u)) {
            p[6] = 1;
            return;
        }
        func_021E03D8(func_021C7CF4((int *)a, b), func_021D70A8(u));
    }
}




void func_021E20E0(int u, int a, int b)
{
    u8 *r;

    if (b == func_021D775C(4) && func_021D775C(0x46) == 0 && func_021D5B68(func_021C7CF4((int *)a, b)) == 0) {
        r = func_021C88A4((char *)a, 0xe, b);
        ((struct Obj05220 *)r)->f4 = 1;
        r[0xc] = 1;
        r[0xe] = 0;
        r[0xf] = 1;
        r[0x10] = b;
        r[0xd] = 1;
        func_021C8838(r + 0x18, 2, 0x214);
        func_021C8860((struct S *)(r + 0x18), b);
        func_021C88C8((void *)a, r);
    }
}




void func_021E2148(void *u, int a, int b, int *p)
{
    if (b == func_021D775C(2) && p[6] != 0)
        func_021E03D8(func_021C7CF4((int *)a, b), func_021D70A8(u));
}


int *func_021E217C(int *p)
{
    *p = 1;
    return d_021F2514;
}

/*
 * file:     unit_021E2188_p04.c
 * unit:     yes
 * function: func_021E26C8, func_021E2700
 * address:  0x021E26C8
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021E03F8  0x021E03F8  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021E8860  0x021E8860  thumb  ov093
 *   d_021F29C8     0x021F29C8  data   ov093  a4
 */
#include "../../matched/include/Obj10080.h"

struct QQ;
struct UtilWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

struct Cnt { u32 n; int max; };

extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern u16 func_021D70A8(struct QQ *p);
extern void func_021E03F8(int a, int b);
extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021E8860(int n);
void func_021E26C8(void *u, int a, int b, int *p);
void func_021E2700(void *a, void *b, int c, struct Cnt *d);
int *func_021E275C(int *p);
extern int d_021F29C8[];


void func_021E26C8(void *u, int a, int b, int *p)
{
    u8 *s;

    s = func_021C88A4((char *)a, 0xb, b);
    s[8] = b;
    s[0x14] = 1;
    ((struct Obj10080 *)s)->f4 = 0x19;
    func_021C88C8((void *)a, s);
    p[6] = 0;
    func_021E03F8(b, func_021D70A8(u));
}


void func_021E2700(void *a, void *b, int c, struct Cnt *d)
{
    void *v;
    u32 i;
    int k;

    if (c == func_021D775C(3)) {
        v = func_021C7CF4(b, c);
        k = 1;
        for (i = 0; i < d->n; i++)
            k <<= 1;
        if (func_021D5BDC(v, 7))
            k <<= 1;
        func_021E8860(k);
        d->n++;
        if ((int)d->n >= d->max)
            func_021E03F8(c, func_021D70A8(a));
    }
}


int *func_021E275C(int *p)
{
    *p = 2;
    return d_021F29C8;
}

/*
 * file:     unit_021E2188_p01.c
 * unit:     yes
 * function: func_021E2268, func_021E231C
 * address:  0x021E2268
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
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7DC0  0x021D7DC0  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021E03D8  0x021E03D8  thumb  ov093
 *   func_021D70A8  0x021D70A8  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 */
#include "../../matched/include/Obj05221.h"
#include "../../matched/include/Obj10076.h"

struct S;
struct QQ;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021D7DC0(int a, void *b, void *c);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(struct S *p, u32 val);
extern void func_021E03D8(u8 *a, int b);
extern u16 func_021D70A8(struct QQ *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
void func_021E2268(void *u, int a, int b, int *p);
void func_021E231C(void *u, int a, int b);


void func_021E2268(void *u, int a, int b, int *p)
{
    void *q;
    u8 *r;
    int f;

    if (b == func_021D775C(2)) {
        q = func_021C7CF4((int *)a, b);
        if (p[6] != 0) {
            f = 0;
            if (p[0] != 0)
                p[0] = p[0] - 1;
            if (func_021D775C(0x51) == 0) {
                r = func_021C88A4((char *)a, 0xb, b);
                ((struct Obj05221 *)r)->f4 = 0x19;
                f = 1;
                r[0x14] = 1;
                r[8] = b;
                func_021C88C8((void *)a, r);
            }
            if (p[0] == 0) {
                r = func_021C88A4((char *)a, 0xc, b);
                ((struct Obj05221 *)r)->f4 = 6;
                func_021D7DC0(6, q, r + 8);
                f = 1;
                r[0xd] = 1;
                r[0xf] = b;
                func_021C8838(r + 0x14, 2, 0x168);
                func_021C8860((struct S *)(r + 0x14), b);
                func_021C88C8((void *)a, r);
            }
            if (f != 0)
                func_021E03D8(q, func_021D70A8(u));
        }
    }
}


void func_021E231C(void *u, int a, int b)
{
    void *q;
    u8 *r;

    if (b == func_021D775C(2)) {
        q = func_021C7CF4((int *)a, b);
        if (func_021D62C4(q, 2) != 0) {
            r = func_021C88A4((char *)a, 0xb, b);
            ((struct Obj10076 *)r)->f4 = 0x19;
            r[0x14] = 1;
            r[8] = b;
            func_021C88C8((void *)a, r);
            func_021E03D8(q, func_021D70A8(u));
        }
    }
}

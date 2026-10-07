/*
 * file:     tr_ai_p19.c
 * unit:     yes
 * function: func_0218A0A4, func_0218A0F4
 * address:  0x0218A0A4
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_020113B0  0x020113B0  thumb
 */
#include "../../matched/include/Obj00005.h"

struct Cursor;
struct Cur;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

extern u32 func_0201134C(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern int func_021D59B4(u8 *p, int k);
extern void func_020113B0(struct Cur *c, u32 v);
int func_0218A0A4(struct Cursor *a, u8 *b, int c);
int func_0218A0F4(u8 *a, int op, int x, int y, int z);


int func_0218A0A4(struct Cursor *a, u8 *b, int c)
{
    int t;
    int n;
    u8 s;
    t = func_0201134C(a);
    n = func_0201134C(a);
    s = func_0218A160(b, t);
    func_021D59B4(func_0218A2FC(b, s), 8);
    return func_0218A0F4((u8 *)a, c, s, func_021D59B4(func_0218A2FC(b, s), 10), n);
}


int func_0218A0F4(u8 *a, int op, int x, int y, int z)
{
    int r = 0;
    switch (op) {
    case 0:
        if (x < y)
            r = 1;
        break;
    case 1:
        if (x > y)
            r = 1;
        break;
    case 2:
        if (x == y)
            r = 1;
        break;
    case 3:
        if (x != y)
            r = 1;
        break;
    case 4:
        if (x & y)
            r = 1;
        break;
    case 5:
        if (!(x & y))
            r = 1;
        break;
    case 6:
        if (x <= y)
            r = 1;
        break;
    case 7:
        if (x >= y)
            r = 1;
        break;
    }
    if (r == 1)
        func_020113B0((struct Cur *)a, (u32)(*(u8 * *)&((struct Obj00005 *)a)->f14 + z));
    return r;
}

/*
 * function: func_021F2588
 * address:  0x021F2588
 * packet:   pkt_ov032_021F2588
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F2588 0x021F2588 thumb
 *   func_021F25D4 0x021F25D4 thumb ov032
 *   func_021F2608 0x021F2608 thumb ov032
 *   func_021F2624 0x021F2624 thumb ov032
 *   func_0201235C 0x0201235C thumb
 */
#include "../include/Obj09800.h"

typedef unsigned char  u8;
extern int func_021F25D4(u8 *p, int *st);
extern int func_021F2608(char *, int *);
extern int func_021F2624(int, int *);
typedef unsigned int   u32;
struct S0201235C;
extern void func_0201235C(struct S0201235C *o, u32 *out);

int func_021F2588(int a0, int a1, int *st)
{
    int r;
    char *o;

    r = 0;
    o = (char *)st[3];
    switch (st[5]) {
    case 0:
        r = func_021F25D4((u8 *)o, st);
        break;
    case 1:
        r = func_021F2608(o, st);
        break;
    case 2:
        r = func_021F2624((int)o, st);
        break;
    }
    if (r) {
        ((struct Obj09800 *)o)->f72 = 0;
        func_0201235C((struct S0201235C *)a0, (u32 *)st[4]);
    }
    return 0;
}

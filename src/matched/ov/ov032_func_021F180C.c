/*
 * function: func_021F180C
 * address:  0x021F180C
 * packet:   pkt_ov032_021F180C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F180C 0x021F180C thumb
 *   func_02165E24 0x02165E24 thumb ov010
 *   func_02165FCC 0x02165FCC thumb ov010
 *   func_02165374 0x02165374 thumb ov010
 *   func_0200C1C8 0x0200C1C8 thumb
 *   func_021F18C4 0x021F18C4 thumb
 *   func_021F199C 0x021F199C thumb
 *   func_021F1888 0x021F1888 thumb
 */
#include "../include/Obj00007.h"

typedef unsigned short u16;

extern int func_02165E24(int a);
extern void func_02165FCC(int a, int b, u16 c);
extern void func_02165374(unsigned a0);
typedef unsigned int   u32;
struct Blk34;
extern u32 func_0200C1C8(struct Blk34 *p);
extern void func_021F18C4(char *this, int a);
extern int func_021F199C(char *p, void *x, int flag);
extern void func_021F1888(char *this, int a);

int func_021F180C(char *this, int x, int flag)
{
    int k;

    k = func_02165E24(x);
    if (flag != 0) {
        func_02165FCC(x, *(int *)&((struct Obj00007 *)this)->f110, ((struct Obj00007 *)this)->f96);
        func_021F18C4(this, 0x12);
        return 1;
    }
    switch (k) {
    case 1:
        return 0;
    case 0x12:
        return func_021F199C(this, (void *)x, 0);
    case 0x32:
        return func_021F199C(this, (void *)x, 1);
    case 0x18:
        func_02165374(func_0200C1C8((struct Blk34 *)(((struct Obj00007 *)this)->f14)));
        break;
    }
    func_021F1888(this, x);
    return 1;
}

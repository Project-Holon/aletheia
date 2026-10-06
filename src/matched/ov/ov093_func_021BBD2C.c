/*
 * function: func_021BBD2C
 * address:  0x021BBD2C
 * packet:   pkt_ov093_021BBD2C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB920  0x021BB920  thumb  ov093
 *   func_021D74E4  0x021D74E4  thumb  ov093
 *   func_021BC220  0x021BC220  thumb  ov093
 *   func_021BBFA8  0x021BBFA8  thumb  ov093
 */
#include "../include/Obj02777.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021BB920(u8 *p);
extern void func_021D74E4(void);
extern int func_021BC220(u8 *p, u8 *o);
extern u8 func_021BBFA8(u8 *p, u8 k);

int func_021BBD2C(u8 *p, int a)
{
    int *q;

    ((struct Obj02777 *)p)->f14 = 0;
    q = *(int * *)&((struct Obj02777 *)p)->fC;
    q[0] = 0;
    q[1] = 0;
    if (p[0x77c] == 0) {
        func_021BB920((u8 *)(((struct Obj02777 *)p)->f0));
        func_021D74E4();
        p[0x77d] = 0;
        p[0x77c] = 1;
        if (func_021BC220(p, (u8 *)a) != 0) {
            ((struct Obj02777 *)p)->f14 = 3;
            return 3;
        }
    }
    p[0x783] = func_021BBFA8(p, p[0x783]);
    return ((struct Obj02777 *)p)->f14;
}

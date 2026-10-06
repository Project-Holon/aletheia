/*
 * function: func_021F1340
 * address:  0x021F1340
 * packet:   pkt_ov032_021F1340
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1340 0x021F1340 thumb
 *   func_021F029C 0x021F029C thumb
 *   func_021F0DF4 0x021F0DF4 thumb
 *   func_021F05E8 0x021F05E8 thumb
 *   func_021F12B8 0x021F12B8 thumb
 */
#include "../include/Obj00188.h"

typedef unsigned char u8;

extern void func_021F029C(char *this, int a);
extern void func_021F0DF4(void *p, unsigned short v);
typedef unsigned int   u32;
extern void func_021F05E8(u8 *p, int a, u32 b);
extern void func_021F12B8(u8 *this, int dir);

void func_021F1340(char *this, int a, u8 b)
{
    this[0x81] = 1;
    this[0x82] = 0;
    ((struct Obj00188 *)this)->f84 = a;
    this[0x83] = b;
    ((struct Obj00188 *)this)->f88 = 0;
    func_021F029C(this, 1);
    if (((struct Obj00188 *)this)->f84 == 0)
        func_021F0DF4((void *)(((struct Obj00188 *)this)->f2D0), 0x13);
    else
        func_021F0DF4((void *)(((struct Obj00188 *)this)->f2CC), 0xf);
    func_021F05E8((u8 *)this, 4, 2);
    func_021F12B8((u8 *)this, a);
}

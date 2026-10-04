/*
 * function: func_021B815C
 * address:  0x021B815C
 * packet:   pkt_021B815C
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B7460  0x021B7460  thumb  ov173
 */
#include "../include/Obj14319.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern void func_021B7460(char *p, u32 v);

int func_021B815C(char *p)
{
    func_021B7460(p, 2);
    ((struct Obj14319 *)p)->f1BA = 1;
    *(u32 *)(p + 0x1ba - 0xa) = 3;
    return 2;
}

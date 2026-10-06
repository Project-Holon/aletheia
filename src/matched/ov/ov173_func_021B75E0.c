/*
 * function: func_021B75E0
 * address:  0x021B75E0
 * packet:   pkt_021B75E0
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
#include "../include/Obj14316.h"

typedef unsigned int   u32;
extern void func_021B7460(char *p, u32 kind);

int func_021B75E0(int *p)
{
    func_021B7460((char *)p, 7);
    ((struct Obj14316 *)p)->f1BA = 3;
    ((struct Obj14316 *)p)->f1B0 = 3;
    return 2;
}

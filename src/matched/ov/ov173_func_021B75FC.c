/*
 * function: func_021B75FC
 * address:  0x021B75FC
 * packet:   pkt_021B75FC
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
#include "../include/Obj14317.h"

typedef unsigned int   u32;
extern void func_021B7460(char *p, u32 kind);

int func_021B75FC(int *p)
{
    func_021B7460((char *)p, 8);
    ((struct Obj14317 *)p)->f1B0 = 8;
    *(unsigned char *)(((struct Obj14317 *)p)->f0 + 0x1a) = 1;
    return 2;
}

/*
 * function: func_021B9D20
 * address:  0x021B9D20
 * packet:   pkt_021B9D20
 * region:   ov181
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9C30  0x021B9C30  thumb  ov181
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj24504.h"

extern void func_021B9C30(char *);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021B9D20(char *p)
{
    func_021B9C30(p);
    func_020307B0((void *)(((struct Obj24504 *)p)->f2D4));
}

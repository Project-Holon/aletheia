/*
 * function: func_021B6730
 * address:  0x021B6730
 * packet:   pkt_021B6730
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B6290  0x021B6290  thumb  ov179
 */
#include "../include/Obj14389.h"

typedef unsigned int   u32;
extern void func_021B6290(char *p, u32 a, u32 b, u32 c);

int func_021B6730(int a, int *q)
{
    func_021B6290((char *)a, ((struct Obj14389 *)q)->f4, ((struct Obj14389 *)q)->f8, 5);
    return 1;
}

/*
 * function: func_021B676C
 * address:  0x021B676C
 * packet:   pkt_021B676C
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B630C  0x021B630C  thumb  ov179
 */
#include "../include/Obj14392.h"

typedef unsigned int   u32;
extern void func_021B630C(char *p, u32 a, u32 b, u32 c);

int func_021B676C(int a, int *q)
{
    func_021B630C((char *)a, ((struct Obj14392 *)q)->f4, ((struct Obj14392 *)q)->f8, 5);
    return 1;
}

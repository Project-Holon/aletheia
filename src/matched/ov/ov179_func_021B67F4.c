/*
 * function: func_021B67F4
 * address:  0x021B67F4
 * packet:   pkt_021B67F4
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204047C  0x0204047C  arm
 */
#include "../include/Obj14396.h"

extern void func_0204047C(int idx, unsigned short val);

int func_021B67F4(int a, int *q)
{
    func_0204047C((unsigned char)((struct Obj14396 *)q)->f4,
                  (unsigned char)((struct Obj14396 *)q)->f8);
    return 1;
}

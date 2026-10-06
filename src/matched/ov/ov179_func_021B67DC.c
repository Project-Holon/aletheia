/*
 * function: func_021B67DC
 * address:  0x021B67DC
 * packet:   pkt_021B67DC
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02040588  0x02040588  arm
 */
#include "../include/Obj14395.h"

typedef unsigned int   u32;
extern void func_02040588(u32 which, unsigned char enable);

int func_021B67DC(int a, int *q)
{
    func_02040588((unsigned char)((struct Obj14395 *)q)->f4,
                  (unsigned char)((struct Obj14395 *)q)->f8);
    return 1;
}

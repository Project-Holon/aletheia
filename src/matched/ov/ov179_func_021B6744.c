/*
 * function: func_021B6744
 * address:  0x021B6744
 * packet:   pkt_ov179_021B6744
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B62B8  0x021B62B8  thumb  ov179
 */
#include "../include/Obj14390.h"

typedef unsigned int   u32;
extern void func_021B62B8(char *p, u32 a, u32 b, u32 c);

int func_021B6744(int a, int *q)
{
    func_021B62B8((char *)a, ((struct Obj14390 *)q)->f4, ((struct Obj14390 *)q)->f8, 5);
    return 1;
}

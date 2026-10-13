/*
 * function: func_0217AFBC
 * address:  0x0217AFBC
 * packet:   pkt_0217AFBC
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E867C  0x021E867C  thumb  ov177
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 */
#include "../include/Obj04561.h"

typedef unsigned int   u32;
struct PrintSys;
extern void func_021E867C(char *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

void func_0217AFBC(int *p)
{
    func_021E867C((char *)(((struct Obj04561 *)p)->f8));
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj04561 *)p)->f14));
}

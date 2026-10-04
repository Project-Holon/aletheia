/*
 * function: func_02184470
 * address:  0x02184470
 * packet:   pkt_02184470
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0208B500  0x0208B500  arm
 */
#include "../include/Obj10643.h"

extern void func_0208B500(int *);

void func_02184470(int *p)
{
    if (((struct Obj10643 *)p)->f30 == 0) {
        func_0208B500(p);
        ((struct Obj10643 *)p)->f28 = 1;
    } else {
        ((struct Obj10643 *)p)->f2C = 1;
    }
}

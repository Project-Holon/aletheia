/*
 * function: func_021F6C80
 * address:  0x021F6C80
 * packet:   pkt_021F6C80
 * region:   ov135
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj07243.h"
#include "../include/Obj07244.h"

int func_021F6C80(void *pa, void *pb)
{
    signed char a3;
    signed char b3;
    signed char b4;
    signed char b2;

    if (((struct Obj07243 *)pa)->f0 != ((struct Obj07244 *)pb)->f0)
        return 0;
    b2 = ((struct Obj07244 *)pb)->f2;
    if (b2 != 3 && b2 != ((struct Obj07243 *)pa)->f2)
        return 0;
    a3 = ((struct Obj07243 *)pa)->f3;
    if (a3 == 0)
        return 0;
    b3 = ((struct Obj07244 *)pb)->f3;
    if (b3 != 0 && b3 > a3)
        return 0;
    b4 = ((struct Obj07244 *)pb)->f4;
    if (b4 != 0 && b4 < a3)
        return 0;
    return 1;
}

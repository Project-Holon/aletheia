/*
 * function: func_0217DFBC
 * address:  0x0217DFBC
 * packet:   pkt_0217DFBC
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E8A00  0x021E8A00  thumb  ov177
 */
#include "../include/Obj00348.h"

extern int func_021E8A00(int);

int func_0217DFBC(int *p)
{
    if (*(int *)&((struct Obj00348 *)p)->fC)
        return func_021E8A00(*(int *)&((struct Obj00348 *)p)->fC);
    return -1;
}

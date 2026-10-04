/*
 * function: func_0220C6D0
 * address:  0x0220C6D0
 * packet:   pkt_0220C6D0
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02209A7C 0x02209A7C thumb
 */
#include "../include/Obj00315.h"

extern int func_02209A7C(int, int, int);

void func_0220C6D0(char *a)
{
    ((struct Obj00315 *)a)->f14C = func_02209A7C(*(int *)&((struct Obj00315 *)a)->f8, 9,
                                         *(unsigned short *)(*(int *)&((struct Obj00315 *)a)->f0 + 0xc));
}
/*
 * function: func_02208A54
 * address:  0x02208A54
 * packet:   pkt_02208A54
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02047CFC 0x02047CFC arm
 */
#include "../include/Obj00687.h"

extern int func_02047CFC(int, int, int);

void func_02208A54(char *a)
{
    *(int *)&((struct Obj00687 *)a)->f14 = func_02047CFC(4, 1, ((struct Obj00687 *)a)->f0);
    ((struct Obj00687 *)a)->f1C = 0;
}
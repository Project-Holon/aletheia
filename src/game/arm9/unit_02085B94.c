/*
 * file:     unit_02085B94.c
 * function: OS_SetThreadUserParameter
 * address:  0x02085B94
 * packet:   pkt_02085B94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../../matched/include/Obj16692.h"

void OS_SetThreadUserParameter(char *thread, int parameter)
{
    ((struct Obj16692 *)thread)->fB4 = parameter;
}

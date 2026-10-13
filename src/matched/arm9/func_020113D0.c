/*
 * function: VM_SetWait
 * address:  0x020113D0
 * packet:   pkt_020113D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
#include "../include/Obj00005.h"

void VM_SetWait(char *p, int val)
{
    p[0xd] = 2;
    *(int *)&((struct Obj00005 *)p)->f10 = val;
}

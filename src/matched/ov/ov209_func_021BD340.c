/*
 * function: func_021BD340
 * address:  0x021BD340
 * packet:   pkt_ov209_021BD340
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD314 0x021BD314 thumb
 */
#include "../include/Obj00088.h"

extern void func_021BD314(char *p, int i);

int func_021BD340(char *a, int arg)
{
    func_021BD314(a, arg);
    *(int *)(*(int *)&((struct Obj00088 *)a)->f0 + 0x10) = 3;
    return 7;
}
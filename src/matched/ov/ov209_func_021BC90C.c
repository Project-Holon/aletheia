/*
 * function: func_021BC90C
 * address:  0x021BC90C
 * packet:   pkt_021BC90C
 * region:   ov209
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */
#include "../include/Obj00088.h"

void func_021BC90C(char *a, int b)
{
    ((struct Obj00088 *)a)->fC40 = 0x30;
    *(unsigned short *)&((struct Obj00088 *)a)->fC42 = b;
}
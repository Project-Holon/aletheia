/*
 * unit:     no
 * function: func_020607B8
 * address:  0x020607B8
 * packet:   pkt_02060764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj00512.h"

void *func_020607B8(int *p, void *node, int *a)
{
    int *b;
    ((struct Obj00512 *)node)->f8 = (int)a;
    if (a != 0) {
        b = (int *)a[3];
        a[3] = (int)node;
    } else {
        b = (int *)p[0];
        p[0] = (int)node;
    }
    *(int *)&((struct Obj00512 *)node)->fC = (int)b;
    if (b != 0)
        b[2] = (int)node;
    else
        p[1] = (int)node;
    return node;
}


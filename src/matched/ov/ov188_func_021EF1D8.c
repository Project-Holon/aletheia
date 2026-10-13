/*
 * function: func_021EF1D8
 * address:  0x021EF1D8
 * packet:   pkt_021EF1D8
 * region:   ov188
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 */
#include "../include/Obj02907.h"
#include "../include/Obj24897.h"

extern void MI_CpuCopy8(void *, void *, int);

int func_021EF1D8(char *p, char *a1)
{
    int v = ((struct Obj24897 *)a1)->f34;

    ((struct Obj02907 *)p)->f98 = v;
    MI_CpuCopy8(a1 + 0x38, ((struct Obj02907 *)p)->f94, v);
    return 1;
}

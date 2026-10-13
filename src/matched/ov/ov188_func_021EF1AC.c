/*
 * function: func_021EF1AC
 * address:  0x021EF1AC
 * packet:   pkt_021EF1AC
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
#include "../include/Obj14493.h"
#include "../include/Obj24896.h"
typedef unsigned int u32;

extern void MI_CpuCopy8(void *, void *, int);

int func_021EF1AC(char *p, char *q)
{
    u32 a = ((struct Obj14493 *)p)->f94;

    if (a != 0) {
        u32 b = ((struct Obj14493 *)p)->f98;

        if (b < 0xc00) {
            ((struct Obj24896 *)q)->f34 = b;
            MI_CpuCopy8((void *)a, q + 0x38, b);
            return 1;
        }
    }
    return 0;
}

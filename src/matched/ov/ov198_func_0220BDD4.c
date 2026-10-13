/*
 * function: func_0220BDD4
 * address:  0x0220BDD4
 * packet:   pkt_0220BDD4
 * region:   ov198
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj25132.h"

struct Descriptor;
typedef unsigned int   u32;
extern u32 BMP_WIN_Delete(struct Descriptor *d);

void func_0220BDD4(char *p)
{
    unsigned int i;
    for (i = 0; i < ((struct Obj25132 *)p)->f2174; i++)
    {
        BMP_WIN_Delete(*(void **)(p + 0x1f70 + i * 8));
    }
}

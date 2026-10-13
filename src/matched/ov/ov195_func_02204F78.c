/*
 * function: func_02204F78
 * address:  0x02204F78
 * packet:   pkt_02204F78
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 */
#include "../include/Obj14525.h"

typedef unsigned int   u32;
extern void GFL_USE_FadeOutBgm(u32 a);

void func_02204F78(int a, char *b)
{
    if (((struct Obj14525 *)b)->f30 == 4) {
        GFL_USE_FadeOutBgm(0x3c);
        ((struct Obj14525 *)b)->f30 = 6;
    }
}

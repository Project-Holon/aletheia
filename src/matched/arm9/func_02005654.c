/*
 * function: GFL_USE_SetVBlankHook
 * address:  0x02005654
 * packet:   pkt_02005654
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _GflUse     0x020AA194  data  a4
 */

#include "../include/G_GflSys.h"

extern struct GflSys _GflUse;

int GFL_USE_SetVBlankHook(int a, int b)
{
    int v = *(int *)((char *)&(*(int *)&_GflUse) + 8);

    if (v != 0) {
        return 0;
    }

    *(int *)((char *)&(*(int *)&_GflUse) + 8) = a;
    (*(int *)&_GflUse) = b;
    return 1;
}

/*
 * function: func_0218B310
 * address:  0x0218B310
 * packet:   pkt_ov021_0218B310
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0219E418  0x0219E418  thumb  ov021
 */
#include "../include/Obj19510.h"

void *func_021A3074(unsigned char *p);
typedef unsigned int   u32;
int func_0219E418(u32 a, u32 b);

int func_0218B310(void *a, unsigned char *s)
{
    if ((func_0219E418((u32)func_021A3074(a), ((struct Obj19510 *)s)->f24) & 3) == 0)
        return 1;
    return 0;
}

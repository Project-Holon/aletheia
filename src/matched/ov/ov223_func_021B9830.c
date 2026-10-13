/*
 * function: func_021B9830
 * address:  0x021B9830
 * packet:   pkt_021B9830
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_UTIL_Create  0x02047CFC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00739.h"

typedef unsigned short u16;

extern int G3D_UTIL_Create(int, int, u16);

void func_021B9830(char *p)
{
    ((struct Obj00739 *)p)->f28 = G3D_UTIL_Create(5, 4, ((struct Obj00739 *)p)->f0);
    ((struct Obj00739 *)p)->f3A = 0;
}

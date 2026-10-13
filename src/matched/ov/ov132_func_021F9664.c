/*
 * function: func_021F9664
 * address:  0x021F9664
 * packet:   pkt_021F9664
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_InstallBgmBuffers  0x02006448  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10533.h"

typedef unsigned int   u32;
extern int GFL_USE_InstallBgmBuffers(u32 a0, u32 a1, u32 a2);

void func_021F9664(char *p, int a)
{
    ((struct Obj10533 *)p)->f24 = 1;
    GFL_USE_InstallBgmBuffers(((struct Obj10533 *)p)->f1DC, ((struct Obj10533 *)p)->f1E0, a);
}

/*
 * function: func_021B9CE0
 * address:  0x021B9CE0
 * packet:   pkt_021B9CE0
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9CF0  0x021B9CF0  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26140.h"

extern unsigned short func_021B9CF0(char *p, unsigned i);

int func_021B9CE0(char *p, int idx)
{
    return func_021B9CF0(p, idx) + ((struct Obj26140 *)p)->f0;
}

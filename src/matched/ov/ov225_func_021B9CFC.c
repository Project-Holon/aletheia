/*
 * function: func_021B9CFC
 * address:  0x021B9CFC
 * packet:   pkt_021B9CFC
 * region:   ov225
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B9D0C  0x021B9D0C  thumb  ov225
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26142.h"

extern unsigned short func_021B9D0C(char *p, unsigned i);

int func_021B9CFC(char *p, int idx)
{
    return func_021B9D0C(p, idx) + ((struct Obj26142 *)p)->f8;
}

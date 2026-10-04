/*
 * function: func_021B3B04
 * address:  0x021B3B04
 * packet:   pkt_ov021_021B3B04
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (tail-call stub), called from func_021B35A4.
 *
 * symbols:
 *   func_0201F868  0x0201F868  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19996.h"

extern void func_0201F868(void *p);

void func_021B3B04(char *w)
{
    func_0201F868(((struct Obj19996 *)w)->f180);
}

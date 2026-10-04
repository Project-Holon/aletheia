/*
 * function: func_021BA208
 * address:  0x021BA208
 * packet:   pkt_021BA208
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9C00  0x021B9C00  thumb  ov218
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26047.h"

extern int func_021B9C00(char *p);

int func_021BA208(void *unused, char *p)
{
    return func_021B9C00((char *)(((struct Obj26047 *)p)->f28)) != 0;
}

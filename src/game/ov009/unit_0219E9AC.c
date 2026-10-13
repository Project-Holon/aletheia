/*
 * file:     unit_0219E9AC.c
 * function: func_0219E9AC
 * address:  0x0219E9AC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sets the flag bits of a server.
 */

#include "unit_0219E1EC_types.h"

void func_0219E9AC(SBServer *server, unsigned char flags)
{
    server->flags = flags;
}

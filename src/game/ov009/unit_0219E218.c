/*
 * file:     unit_0219E218.c
 * function: func_0219E218
 * address:  0x0219E218
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Public query port of a server, as stored (network byte order).
 */

#include "unit_0219E1EC_types.h"

unsigned short func_0219E218(const SBServer *server)
{
    return server->publicport;
}

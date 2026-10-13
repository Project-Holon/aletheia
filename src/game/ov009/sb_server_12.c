/*
 * file:     sb_server_12.c
 * function: SBServerSetFlags
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

#include "sb_server_2_types.h"

void SBServerSetFlags(SBServer *server, unsigned char flags)
{
    server->flags = flags;
}

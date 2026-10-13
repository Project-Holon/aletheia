/*
 * file:     sb_server_4.c
 * function: SBServerGetPublicQueryPortNBO
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

#include "sb_server_2_types.h"

unsigned short SBServerGetPublicQueryPortNBO(const SBServer *server)
{
    return server->publicport;
}

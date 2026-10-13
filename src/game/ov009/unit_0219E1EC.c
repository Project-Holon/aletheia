/*
 * file:     unit_0219E1EC.c
 * function: SBServerGetPublicInetAddress
 * address:  0x0219E1EC
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Public address of a server.
 */

#include "unit_0219E1EC_types.h"

unsigned int SBServerGetPublicInetAddress(const SBServer *server)
{
    return server->publicip;
}

/*
 * file:     sb_server_6.c
 * function: SBServerGetPrivateInetAddress
 * address:  0x0219E238
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Private address of a server.
 */

#include "sb_server_2_types.h"

unsigned int SBServerGetPrivateInetAddress(const SBServer *server)
{
    return server->privateip;
}

/*
 * file:     sb_server_10.c
 * function: SBServerGetPing
 * address:  0x0219E8F8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Ping time of a server (the update time field).
 */

#include "sb_server_2_types.h"

int SBServerGetPing(const SBServer *server)
{
    return server->updatetime;
}

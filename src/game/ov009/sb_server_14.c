/*
 * file:     sb_server_14.c
 * unit:     yes
 * function: SBServerSetICMPIP, SBServerSetState, SBServerGetState
 * address:  0x0219E9C0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "sb_server_2_types.h"

void SBServerSetICMPIP(SBServer *server, unsigned int icmpIp);
void SBServerSetState(SBServer *server, unsigned char state);
unsigned char SBServerGetState(const SBServer *server);

/*
 * Sets the address used for the ICMP ping of a server.
 */
void SBServerSetICMPIP(SBServer *server, unsigned int icmpIp)
{
    server->icmpip = icmpIp;
}

/*
 * Sets the state bits of a server.
 */
void SBServerSetState(SBServer *server, unsigned char state)
{
    server->state = state;
}

/*
 * State bits of a server.
 */
unsigned char SBServerGetState(const SBServer *server)
{
    return server->state;
}

/*
 * file:     unit_0219E9C0.c
 * unit:     yes
 * function: func_0219E9C0, func_0219E9C8, func_0219E9D0
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
#include "unit_0219E1EC_types.h"

void func_0219E9C0(SBServer *server, unsigned int icmpIp);
void func_0219E9C8(SBServer *server, unsigned char state);
unsigned char func_0219E9D0(const SBServer *server);

/*
 * Sets the address used for the ICMP ping of a server.
 */
void func_0219E9C0(SBServer *server, unsigned int icmpIp)
{
    server->icmpip = icmpIp;
}

/*
 * Sets the state bits of a server.
 */
void func_0219E9C8(SBServer *server, unsigned char state)
{
    server->state = state;
}

/*
 * State bits of a server.
 */
unsigned char func_0219E9D0(const SBServer *server)
{
    return server->state;
}

/*
 * file:     sb_serverlist_4.c
 * function: SBServerListSetLastError
 * address:  0x021A0A1C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Sets the last error text of a server list.
 */

#include "sb_server_2_types.h"

void SBServerListSetLastError(SBServerList *slist, char *lastError)
{
    slist->lasterror = lastError;
}

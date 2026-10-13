/*
 * file:     unit_021A0A1C.c
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

#include "unit_0219E1EC_types.h"

void SBServerListSetLastError(SBServerList *slist, char *lastError)
{
    slist->lasterror = lastError;
}

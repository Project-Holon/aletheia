/*
 * file:     unit_0219F0D8.c
 * function: ServerBrowserGetMyPublicIPAddr
 * address:  0x0219F0D8
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Public address of this console, as the list server reported it.
 */

#include "unit_0219E1EC_types.h"

unsigned int ServerBrowserGetMyPublicIPAddr(const ServerBrowser *browser)
{
    return browser->list.mypublicip;
}

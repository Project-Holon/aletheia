/*
 * function: GFL_NET_IRC_WIRELESS_SetSessionParamValue
 * address:  0x0203DA68
 * packet:   pkt_0203DA68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   d_021469F0 0x021469F0 data a4
 *
 * Stores a word into the singleton at +0x74.
 */

#include "../include/G_Ctx.h"

extern struct Ctx *d_021469F0;
void GFL_NET_IRC_WIRELESS_SetSessionParamValue(unsigned int value)
{
    *(unsigned int *)(((unsigned char *)d_021469F0) + 0x74) = value;
}

/*
 * file:     br_codein_socl.c
 * function: func_021E2F98
 * address:  0x021E2F98
 * packet:   pkt_021E2F98
 * region:   ov183
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gBrCodeinDefaultPair  0x021E3910  data  ov183
 */

#include "soc_types.h"

extern SOCLResource gBrCodeinDefaultPair;

void func_021E2F98(SOCLResource *resource)
{
    *resource = gBrCodeinDefaultPair;
}

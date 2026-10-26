/*
 * file:     br_codein_socl.c
 * function: BR_CODEIN_SOCL_InitDefault
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

#include "br_codein_types.h"

extern const struct CodeinStoredFns gBrCodeinDefaultPair;

void BR_CODEIN_SOCL_InitDefault(struct CodeinStoredFns *resource)
{
    *resource = gBrCodeinDefaultPair;
}

/*
 * function: OEKAKI_GetJoinedBits
 * address:  0x02186558
 * packet:   pkt_02186558
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   UNION_APP_GetJoinedBits  0x021841A0  thumb  ov022
 *
 * Unblocked by matching the leaf at 0x021841A0 in ov022: the address is
 * below ov023's own base (0x021841E0) and ov022 is its only coherent code
 * home; the region hint is corrected from ov023 to ov022.
 */
#include "../include/Obj20368.h"

typedef unsigned int u32;

unsigned char UNION_APP_GetJoinedBits(unsigned char *p);

int OEKAKI_GetJoinedBits(char *p)
{
    return UNION_APP_GetJoinedBits((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj20368 *)p)->f4));
}

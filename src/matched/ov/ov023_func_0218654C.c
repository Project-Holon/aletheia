/*
 * function: OEKAKI_GetJoinedCount
 * address:  0x0218654C
 * packet:   pkt_0218654C
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   UNION_APP_GetMemberCount  0x021841A4  thumb  ov022
 *
 * Unblocked by matching the leaf at 0x021841A4 in ov022: the address is
 * below ov023's own base (0x021841E0) and ov022 is its only coherent code
 * home; the region hint is corrected from ov023 to ov022.
 */
#include "../include/Obj13027.h"

typedef unsigned int u32;

int UNION_APP_GetMemberCount(unsigned char *p);

int OEKAKI_GetJoinedCount(char *p)
{
    return UNION_APP_GetMemberCount((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj13027 *)p)->f4));
}

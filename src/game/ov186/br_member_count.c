/*
 * file:     br_member_count.c
 * unit:     yes
 * function: BR_MEMBER_COUNT_GetU16Count
 * address:  0x02200228
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from br_pokesearch.c by tools/splitfile.py.
 *
 * symbols:
 *   BR_MEMBER_COUNT_GetU16Count 0x02200228 thumb ov186
 *   ARC_UTIL_LoadMemberWithSize   0x0204A298  arm
 */
#include "../types.h"

extern void *ARC_UTIL_LoadMemberWithSize(int archiveID, int memberIdx, int decompress, int memberId, u32 *out);

/* Load the group table member (id 0x62, index 5) and report its u16 count. */
u16 *BR_MEMBER_COUNT_GetU16Count(void *member, unsigned *countOut)
{
    u32 byteSize;
    u16 *base;
    base = ARC_UTIL_LoadMemberWithSize(0x62, 5, 0, (int)member, &byteSize);
    *countOut = byteSize >> 1;
    return base;
}

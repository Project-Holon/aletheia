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
typedef unsigned int   u32;
extern int ARC_UTIL_LoadMemberWithSize(int a0, int a1, int a2, int a3, u32 *out);

int BR_MEMBER_COUNT_GetU16Count(void *a, unsigned *out)
{
    int local;
    int r;
    r = ARC_UTIL_LoadMemberWithSize(0x62, 5, 0, (int)a, (u32 *)(&local));
    *out = (unsigned)local >> 1;
    return r;
}

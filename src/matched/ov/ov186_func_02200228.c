/*
 * function: func_02200228
 * address:  0x02200228
 * packet:   pkt_02200228
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadMemberWithSize   0x0204A298  arm
 *
 * Read a 16-bit value from an SDK parameter block (id 0x62, index 5), store
 * its half through *out, and return the SDK call's own result.
 */

typedef unsigned int   u32;
extern int ARC_UTIL_LoadMemberWithSize(int a0, int a1, int a2, int a3, u32 *out);

int func_02200228(void *a, unsigned *out)
{
    int local;
    int r;
    r = ARC_UTIL_LoadMemberWithSize(0x62, 5, 0, (int)a, (u32 *)(&local));
    *out = (unsigned)local >> 1;
    return r;
}

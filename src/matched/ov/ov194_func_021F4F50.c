/*
 * function: func_021F4F50
 * address:  0x021F4F50
 * packet:   pkt_021F4F50
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_UTIL_LoadMember 0x0204A1BC arm
 */

extern int ARC_UTIL_LoadMember(int a0, int a1, int a2, int a3);

int func_021F4F50(int a)
{
    return ARC_UTIL_LoadMember(0x77, 8, 0, a);
}

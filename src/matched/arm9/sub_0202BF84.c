/*
 * function: ISS_ZONE_SYS_ClearActive
 * address:  0x0202BF84
 * packet:   pkt_0202BEBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned int u32;

void ISS_ZONE_SYS_ClearActive(u32 *p)
{
    if (*p != 0) {
        *p = 0;
    }
}

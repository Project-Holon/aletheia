/*
 * function: ISS_ZONE_SYS_Stop
 * address:  0x0202BEE4
 * packet:   pkt_0202BEBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   ISS_ZONE_SYS_ClearActive  0x0202BF84  thumb
 */

typedef unsigned int u32;

extern void ISS_ZONE_SYS_ClearActive(u32 *p);

void ISS_ZONE_SYS_Stop(void *p)
{
    ISS_ZONE_SYS_ClearActive(p);
}

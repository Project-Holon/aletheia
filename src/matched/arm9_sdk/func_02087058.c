/*
 * function: OS_IsTickAvailable
 * address:  0x02087058
 * packet:   pkt_02087058
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02151330 0x02151330 data
 */

typedef unsigned short u16;
typedef int BOOL;

extern u16 g_02151330;

BOOL OS_IsTickAvailable(void)
{
    return g_02151330;
}

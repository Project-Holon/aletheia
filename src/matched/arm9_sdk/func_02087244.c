/*
 * function: OS_IsAlarmAvailable
 * address:  0x02087244
 * packet:   pkt_02087244
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02151340 0x02151340 data
 */

typedef unsigned short u16;
typedef int BOOL;

extern u16 g_02151340;

BOOL OS_IsAlarmAvailable(void)
{
    return g_02151340;
}

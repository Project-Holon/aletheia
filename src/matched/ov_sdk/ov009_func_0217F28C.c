/*
 * function: current_time_hires
 * address:  0x0217F28C
 * packet:   pkt_ov009_0217F28C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      current_time_hires (gsplatformutil.o)
 *
 * symbols:
 *   OS_GetTick                       0x020870d0 arm
 *   _ll_udiv                         0x0209c00c arm
 */

extern unsigned long long OS_GetTick(void);
extern unsigned long long _ll_udiv(unsigned long long num, unsigned long long den);

unsigned int current_time_hires(void)
{
    return (unsigned int)((OS_GetTick() * 0xfa00ULL) / 0x82eaULL);
}

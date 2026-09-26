/*
 * function: func_0217F264
 * address:  0x0217F264
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * current_time: GameSpy's millisecond clock.  The 64-bit tick from
 * OS_GetTick is scaled by 64 then divided by 33514 (0x82EA); the quotient's
 * low word is the result.  The scale/divide is the inlined u64 arithmetic
 * that mwcc turns into the _ll_udiv runtime call.
 *
 * symbols:
 *   OS_GetTick     0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 */

extern unsigned long long OS_GetTick(void);
extern unsigned long long _ll_udiv(unsigned long long a, unsigned long long b);

unsigned int func_0217F264(void)
{
    unsigned long long t = OS_GetTick();

    return (unsigned int)((t << 6) / 33514);
}

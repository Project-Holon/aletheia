/*
 * file:     unit_0217F264.c
 * unit:     yes
 * function: func_0217F264, func_0217F28C
 * address:  0x0217F264
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_GetTick     0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 */
extern unsigned long long OS_GetTick(void);
extern unsigned long long _ll_udiv(unsigned long long a, unsigned long long b);
unsigned int func_0217F264(void);
unsigned int current_time_hires(void);


/*
 * current_time: GameSpy's millisecond clock.  The 64-bit tick from
 * OS_GetTick is scaled by 64 then divided by 33514 (0x82EA); the quotient's
 * low word is the result.  The scale/divide is the inlined u64 arithmetic
 * that mwcc turns into the _ll_udiv runtime call.
 */
unsigned int func_0217F264(void)
{
    unsigned long long t = OS_GetTick();

    return (unsigned int)((t << 6) / 33514);
}


unsigned int current_time_hires(void)
{
    return (unsigned int)((OS_GetTick() * 0xfa00ULL) / 0x82eaULL);
}

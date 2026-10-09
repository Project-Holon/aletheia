/*
 * file:     unit_02164D64_p02.c
 * unit:     yes
 * function: func_02165B68
 * address:  0x02165B68
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Two on TWL hardware (NWM), one otherwise (WM). A 12-byte linker veneer at
 * 0x02165B5C..0x02165B68 separates this function from unit_02164D64_p01.c.
 *
 * symbols:
 *   OS_IsRunOnTwl  0x02085D3C  arm
 */

extern int OS_IsRunOnTwl(void);

/*
 * Two when the word call is non-zero, one otherwise.
 */
int func_02165B68(void)
{
    return OS_IsRunOnTwl() ? 2 : 1;
}




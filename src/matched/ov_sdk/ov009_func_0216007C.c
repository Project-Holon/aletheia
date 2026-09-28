/*
 * function: CPS_GetSslHandshakePriority
 * address:  0x0216007C
 * packet:   pkt_ov009_0216007C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPS_GetSslHandshakePriority (libssl.TWL.HYB.a ssl.o)
 * symbols:
 *   pairlist                         0x021a1d40 data ov009
 */

extern unsigned long pairlist[];

unsigned long CPS_GetSslHandshakePriority(void)
{
	return pairlist[1];
}

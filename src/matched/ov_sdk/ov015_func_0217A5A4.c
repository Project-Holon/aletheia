/*
 * function: IRC_GetUnitNumber
 * address:  0x0217A5A4
 * packet:   pkt_ov015_0217A5A4
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_0217AAB0                   0x0217AAB0  data
*/

extern unsigned char d_0217AAB0[];

unsigned int IRC_GetUnitNumber(void)
{
	return d_0217AAB0[1];
}


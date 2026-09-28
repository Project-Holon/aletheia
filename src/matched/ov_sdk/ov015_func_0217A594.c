/*
 * function: IRC_SetUnitNumber
 * address:  0x0217A594
 * packet:   pkt_ov015_0217A594
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

void IRC_SetUnitNumber(unsigned int n)
{
	d_0217AAB0[0] = (unsigned char)n;
}


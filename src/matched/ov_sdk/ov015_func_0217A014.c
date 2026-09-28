/*
 * function: DSPi_IsSoundPlayingCore
 * address:  0x0217A014
 * packet:   pkt_ov015_0217A014
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_0217ABA8                   0x0217ABA8  data
*/

extern unsigned char d_0217ABA8[];

unsigned int DSPi_IsSoundPlayingCore(void)
{
	return *(unsigned int *)(d_0217ABA8 + 0x18);
}


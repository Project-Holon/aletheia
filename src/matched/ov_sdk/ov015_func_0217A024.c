/*
 * function: IRC_IsConnect
 * address:  0x0217A024
 * packet:   pkt_ov015_0217A024
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

unsigned int IRC_IsConnect(void)
{
	return *(unsigned int *)(d_0217ABA8 + 0x24);
}


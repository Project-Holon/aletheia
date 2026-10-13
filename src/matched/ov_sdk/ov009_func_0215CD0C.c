/*
 * function: SOCLi_DhcpTimeout
 * address:  0x0215CD0C
 * packet:   pkt_ov009_0215CD0C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021AA440  0x021AA440  data
*/

extern unsigned long g_021AA440[3];

void SOCLi_DhcpTimeout(void)
{
	g_021AA440[2] |= 2;
}

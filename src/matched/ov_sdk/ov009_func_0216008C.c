/*
 * function: CPS_SetSslHandshakePriority
 * address:  0x0216008C
 * packet:   pkt_ov009_0216008C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021A1D40                   0x021A1D40  data
*/

extern unsigned char d_021A1D40[];
void CPS_SetSslHandshakePriority(int len)
{
	*(int *)(d_021A1D40 + 4) = len;
}


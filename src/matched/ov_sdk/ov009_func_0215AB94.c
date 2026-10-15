/*
 * function: CPS_SetUdpCallback
 * address:  0x0215AB94
 * packet:   pkt_ov009_0215AB94
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gMslRefToken  0x02150FEC  data
*/

struct CpsRoot
{
	int prev;
	char *current;
};
extern struct CpsRoot gMslRefToken;

void CPS_SetUdpCallback(int callback)
{
	char *soc = *(char **)(gMslRefToken.current + 0xa4);

	if (soc != 0)
		*(int *)(soc + 0x44) = callback;
}

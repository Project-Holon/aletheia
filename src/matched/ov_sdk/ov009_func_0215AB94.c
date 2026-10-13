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
 *   g_02150FEC  0x02150FEC  data
*/

struct CpsRoot
{
	int prev;
	char *current;
};
extern struct CpsRoot g_02150FEC;

void CPS_SetUdpCallback(int callback)
{
	char *soc = *(char **)(g_02150FEC.current + 0xa4);

	if (soc != 0)
		*(int *)(soc + 0x44) = callback;
}

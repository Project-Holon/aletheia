/*
 * function: CPS_SocDup
 * address:  0x0215AB7C
 * packet:   pkt_ov009_0215AB7C
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

void CPS_SocDup(char *dst)
{
	*(int *)(dst + 0xa4) = *(int *)(gMslRefToken.current + 0xa4);
}

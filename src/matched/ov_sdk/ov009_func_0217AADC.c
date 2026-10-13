/*
 * function: DWC_Netcheck_GetReturnCode
 * address:  0x0217AADC
 * packet:   pkt_ov009_0217AADC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021ACE5C  0x021ACE5C  data
*/

struct NetcheckHolder
{
	int unused;
	char *nc;
};
extern struct NetcheckHolder g_021ACE5C;

int DWC_Netcheck_GetReturnCode(void)
{
	return *(int *)(g_021ACE5C.nc + 0x1004);
}

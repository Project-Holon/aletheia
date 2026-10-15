/*
 * function: SOCLi_CheckNConfig
 * address:  0x0215F1D4
 * packet:   pkt_ov009_0215F1D4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_CheckNConfig (libsoc.TWL.HYB.a(socl_misc.o))
 *
 * symbols:
 *   SOCLi_IsIPv4ValidNodeAddr  0x0215F184  arm  ov009
 *   SOCLi_IsIPv4ValidDNSAddr  0x0215F0F0  arm  ov009
 *   g_021A827C     0x021A827C  data
 *   g_021A82BC     0x021A82BC  data
 *   g_021A8298     0x021A8298  data
 *   g_021A82DC     0x021A82DC  data
 */

extern unsigned long g_021A827C;
extern unsigned long g_021A82BC;
extern unsigned long g_021A8298;
extern unsigned long g_021A82DC[2];

extern int SOCLi_IsIPv4ValidNodeAddr(unsigned long netmask, unsigned long addr);
extern int SOCLi_IsIPv4ValidDNSAddr(unsigned long netmask, unsigned long dns, unsigned long addr);

int SOCLi_CheckNConfig(void)
{
	if (g_021A827C == 0 || ((~g_021A827C) & (~g_021A827C + 1)) != 0)
		return 0;
	if (SOCLi_IsIPv4ValidNodeAddr(g_021A827C, g_021A82BC) == 0)
		return 0;
	if (g_021A8298 != 0) {
		if (SOCLi_IsIPv4ValidNodeAddr(g_021A827C, g_021A8298) == 0
		    || (g_021A827C != 0xffffffff
			&& (g_021A82BC & g_021A827C) != (g_021A8298 & g_021A827C))
		    || g_021A82BC == g_021A8298)
			g_021A8298 = 0;
	}
	if (SOCLi_IsIPv4ValidDNSAddr(g_021A827C, g_021A82DC[0], g_021A82BC) == 0)
		g_021A82DC[0] = 0;
	if (SOCLi_IsIPv4ValidDNSAddr(g_021A827C, g_021A82DC[1], g_021A82BC) == 0)
		g_021A82DC[1] = 0;
	return 1;
}

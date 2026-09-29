/*
 * function: func_0215F1D4
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
 *   func_0215F184  0x0215F184  arm  ov009
 *   func_0215F0F0  0x0215F0F0  arm  ov009
 *   g_021A827C     0x021A827C  data
 *   g_021A82BC     0x021A82BC  data
 *   g_021A8298     0x021A8298  data
 *   g_021A82DC     0x021A82DC  data
 */

extern unsigned long g_021A827C;
extern unsigned long g_021A82BC;
extern unsigned long g_021A8298;
extern unsigned long g_021A82DC[2];

extern int func_0215F184(unsigned long netmask, unsigned long addr);
extern int func_0215F0F0(unsigned long netmask, unsigned long dns, unsigned long addr);

int func_0215F1D4(void)
{
	if (g_021A827C == 0 || ((~g_021A827C) & (~g_021A827C + 1)) != 0)
		return 0;
	if (func_0215F184(g_021A827C, g_021A82BC) == 0)
		return 0;
	if (g_021A8298 != 0) {
		if (func_0215F184(g_021A827C, g_021A8298) == 0
		    || (g_021A827C != 0xffffffff
			&& (g_021A82BC & g_021A827C) != (g_021A8298 & g_021A827C))
		    || g_021A82BC == g_021A8298)
			g_021A8298 = 0;
	}
	if (func_0215F0F0(g_021A827C, g_021A82DC[0], g_021A82BC) == 0)
		g_021A82DC[0] = 0;
	if (func_0215F0F0(g_021A827C, g_021A82DC[1], g_021A82BC) == 0)
		g_021A82DC[1] = 0;
	return 1;
}

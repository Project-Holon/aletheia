/*
 * function: SOCLi_StartupSOCL
 * address:  0x0215CAE4
 * packet:   pkt_ov009_0215CAE4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_StartupSOCL (libsoc.TWL.HYB.a(socl_startup.o))
 *
 * symbols:
 *   SOCLi_StartupCommandPacketQueue  0x0215CD3C  arm  ov009
 *   func_0215D070  0x0215D070  arm  ov009
 *   gSoclConfig  0x021A1CD8  data
 *   g_021A1D14  0x021A1D14  data
 *   g_021AA440  0x021AA440  data
 */

#include "../include/G_021A1CD8.h"

extern int SOCLi_StartupCommandPacketQueue(long cp_max_count);
extern void *func_0215D070(void *param);
extern struct G_021A1CD8 *gSoclConfig;
extern int g_021A1D14;
extern void *g_021AA440[4];

int SOCLi_StartupSOCL(void)
{
	int r;

	r = SOCLi_StartupCommandPacketQueue(gSoclConfig->cpMaxCount);
	if (r >= 0) {
		g_021AA440[3] = func_0215D070(&g_021A1D14);
	}
	return r;
}

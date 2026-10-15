/*
 * function: SOCL_Startup
 * address:  0x0215CA8C
 * packet:   pkt_ov009_0215CA8C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCL_Startup (libsoc.TWL.HYB.a(socl_startup.o))
 *
 * symbols:
 *   OSi_ReferSymbol  0x02004EB0  arm
 *   SOCLi_InitResource  0x0215F0D4  arm  ov009
 *   func_0215CB24  0x0215CB24  arm  ov009
 *   SOCLi_StartupSOCL  0x0215CAE4  arm  ov009
 *   SOCLi_CleanupCPS  0x0215EC90  arm  ov009
 *   gSoclStartupSdkRef  0x020050C4  data
 *   gSoclConfig  0x021A1CD8  data
 */

#include "../include/G_021A1CD8.h"

extern void OSi_ReferSymbol(const void *symbol);
extern void SOCLi_InitResource(void);
extern void func_0215CB24(void);
extern int SOCLi_StartupSOCL(void);
extern void SOCLi_CleanupCPS(void);
extern char gSoclStartupSdkRef[42];
extern struct G_021A1CD8 *gSoclConfig;

int SOCL_Startup(void *socl_config)
{
	int result;

	OSi_ReferSymbol(gSoclStartupSdkRef);
	if (gSoclConfig != 0) {
		return 0;
	}
	SOCLi_InitResource();
	gSoclConfig = socl_config;
	func_0215CB24();
	result = SOCLi_StartupSOCL();
	if (result < 0) {
		SOCLi_CleanupCPS();
		gSoclConfig = 0;
	}
	return result;
}

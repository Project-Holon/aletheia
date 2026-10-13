/*
 * function: func_0215CA8C
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
 *   func_0215F0D4  0x0215F0D4  arm  ov009
 *   func_0215CB24  0x0215CB24  arm  ov009
 *   func_0215CAE4  0x0215CAE4  arm  ov009
 *   func_0215EC90  0x0215EC90  arm  ov009
 *   g_020050C4  0x020050C4  data
 *   g_021A1CD8  0x021A1CD8  data
 */

#include "../include/G_021A1CD8.h"

extern void OSi_ReferSymbol(const void *symbol);
extern void func_0215F0D4(void);
extern void func_0215CB24(void);
extern int func_0215CAE4(void);
extern void func_0215EC90(void);
extern char g_020050C4[42];
extern struct G_021A1CD8 *g_021A1CD8;

int func_0215CA8C(void *socl_config)
{
	int result;

	OSi_ReferSymbol(g_020050C4);
	if (g_021A1CD8 != 0) {
		return 0;
	}
	func_0215F0D4();
	g_021A1CD8 = socl_config;
	func_0215CB24();
	result = func_0215CAE4();
	if (result < 0) {
		func_0215EC90();
		g_021A1CD8 = 0;
	}
	return result;
}

/*
 * function: func_0215EC90
 * address:  0x0215EC90
 * packet:   pkt_ov009_0215EC90
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_CleanupCPS (libsoc.TWL.HYB.a(socl_cleanup.o))
 *
 * symbols:
 *   CPS_Cleanup  0x02157640  arm  ov009
 *   CPS_SetScavengerCallback  0x02157630  arm  ov009
 *   CPS_SetCheckNConfigCallback  0x02157280  arm  ov009
 *   func_02166424  0x02166424  arm  ov009
 */

extern void CPS_Cleanup(void);
extern void CPS_SetScavengerCallback(int v);
extern void CPS_SetCheckNConfigCallback(int v);
extern void func_02166424(void (*callback)(unsigned char *, unsigned char *, unsigned char *, long));

void func_0215EC90(void)
{
	CPS_Cleanup();
	CPS_SetScavengerCallback(0);
	CPS_SetCheckNConfigCallback(0);
	func_02166424(0);
}

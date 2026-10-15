/*
 * function: func_0215CCA0
 * address:  0x0215CCA0
 * packet:   pkt_ov009_0215CCA0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOCLi_SetMyIP (libsoc.TWL.HYB.a(socl_startup.o))
 *
 * symbols:
 *   gSoclConfig  0x021A1CD8  data
 *   g_021A82BC  0x021A82BC  data
 *   g_021A827C  0x021A827C  data
 *   g_021A8298  0x021A8298  data
 *   g_021A82DC  0x021A82DC  data
 *   g_021AA440  0x021AA440  data
 */

#include "../include/G_021A1CD8.h"

extern struct G_021A1CD8 *gSoclConfig;
extern unsigned long g_021A82BC;
extern unsigned long g_021A827C;
extern unsigned long g_021A8298;
extern unsigned long g_021A82DC[2];
extern unsigned long g_021AA440[3];

void func_0215CCA0(void)
{
	g_021A82BC = gSoclConfig->myIp;
	g_021A827C = gSoclConfig->netMask;
	g_021A8298 = gSoclConfig->gatewayIp;
	g_021A82DC[0] = gSoclConfig->dnsIp[0];
	g_021A82DC[1] = gSoclConfig->dnsIp[1];
	g_021AA440[2] |= 2;
}

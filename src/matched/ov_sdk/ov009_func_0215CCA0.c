/*
 * function: SOCLi_SetMyIP
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
 *   gCpsMyIp  0x021A82BC  data
 *   gCpsNetMask  0x021A827C  data
 *   gCpsGateway  0x021A8298  data
 *   gCpsDnsIp  0x021A82DC  data
 *   g_021AA440  0x021AA440  data
 */

#include "../include/G_021A1CD8.h"

extern struct G_021A1CD8 *gSoclConfig;
extern unsigned long gCpsMyIp;
extern unsigned long gCpsNetMask;
extern unsigned long gCpsGateway;
extern unsigned long gCpsDnsIp[2];
extern unsigned long g_021AA440[3];

void SOCLi_SetMyIP(void)
{
	gCpsMyIp = gSoclConfig->myIp;
	gCpsNetMask = gSoclConfig->netMask;
	gCpsGateway = gSoclConfig->gatewayIp;
	gCpsDnsIp[0] = gSoclConfig->dnsIp[0];
	gCpsDnsIp[1] = gSoclConfig->dnsIp[1];
	g_021AA440[2] |= 2;
}

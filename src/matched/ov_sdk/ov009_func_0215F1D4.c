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
 *   gCpsNetMask     0x021A827C  data
 *   gCpsMyIp     0x021A82BC  data
 *   gCpsGateway     0x021A8298  data
 *   gCpsDnsIp     0x021A82DC  data
 */

extern unsigned long gCpsNetMask;
extern unsigned long gCpsMyIp;
extern unsigned long gCpsGateway;
extern unsigned long gCpsDnsIp[2];

extern int SOCLi_IsIPv4ValidNodeAddr(unsigned long netmask, unsigned long addr);
extern int SOCLi_IsIPv4ValidDNSAddr(unsigned long netmask, unsigned long dns, unsigned long addr);

int SOCLi_CheckNConfig(void)
{
	if (gCpsNetMask == 0 || ((~gCpsNetMask) & (~gCpsNetMask + 1)) != 0)
		return 0;
	if (SOCLi_IsIPv4ValidNodeAddr(gCpsNetMask, gCpsMyIp) == 0)
		return 0;
	if (gCpsGateway != 0) {
		if (SOCLi_IsIPv4ValidNodeAddr(gCpsNetMask, gCpsGateway) == 0
		    || (gCpsNetMask != 0xffffffff
			&& (gCpsMyIp & gCpsNetMask) != (gCpsGateway & gCpsNetMask))
		    || gCpsMyIp == gCpsGateway)
			gCpsGateway = 0;
	}
	if (SOCLi_IsIPv4ValidDNSAddr(gCpsNetMask, gCpsDnsIp[0], gCpsMyIp) == 0)
		gCpsDnsIp[0] = 0;
	if (SOCLi_IsIPv4ValidDNSAddr(gCpsNetMask, gCpsDnsIp[1], gCpsMyIp) == 0)
		gCpsDnsIp[1] = 0;
	return 1;
}

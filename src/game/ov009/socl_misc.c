/*
 * file:     socl_misc.c
 * unit:     yes
 * function: SOCLi_RoundUp4, SOCLi_InitResource, SOCLi_IsIPv4ValidDNSAddr, SOCLi_IsIPv4ValidNodeAddr, SOCLi_CheckNConfig
 * address:  0x0215F0C8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   SOCLi_Resource  0x021AA4AC  data
 *   gCpsNetMask     0x021A827C  data
 *   gCpsMyIp     0x021A82BC  data
 *   gCpsGateway     0x021A8298  data
 *   gCpsDnsIp     0x021A82DC  data
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */
#include "ov009_globals.h"

#define IS_A(m, d, a) ((((unsigned int)(a) ^ (d)) & (m)) != 0 || ((d) & ~(m)) != 0)
#define IS_B(m, d, a) (((((a) ^ (d)) & (m)) != 0 || (~(m) ^ ((d) & ~(m))) != 0) ? 1 : 0)
#include "../types.h"

extern void MI_CpuFill8(void *p, int v, int n);
u32 SOCLi_RoundUp4(u32 size);
void SOCLi_InitResource(void);
int SOCLi_IsIPv4ValidDNSAddr(unsigned long netmask, unsigned long dns, unsigned long addr);
int SOCLi_IsIPv4ValidNodeAddr(unsigned long netmask, unsigned long addr);
int SOCLi_CheckNConfig(void);
extern SoclResource SOCLi_Resource;
extern unsigned long gCpsNetMask;
extern unsigned long gCpsMyIp;
extern unsigned long gCpsGateway;
extern unsigned long gCpsDnsIp[2];

u32 SOCLi_RoundUp4(u32 size)
{
    return (size + 3) & ~3;
}

/*
 * Clears the eight bytes of the object at 0x021AA4AC.
 */
void SOCLi_InitResource(void)
{
    MI_CpuFill8(((char *)&SOCLi_Resource), 0, 8);
}

/*
 * 2026-10-01 lane08: EXACT.  A `(unsigned int)` cast on `addr` in IS_A makes
 *   the two xors distinct expressions to CSE (cast-between-uses idiom), and
 *   IS_B is the `(x || y) ? 1 : 0` value form with `~m ^ (d & ~m)` (teq).
 *
 * sdk:      SOCLi_IsIPv4ValidDNSAddr (libsoc.TWL.HYB.a(socl_misc.o))
 */
int SOCLi_IsIPv4ValidDNSAddr(unsigned long netmask, unsigned long dns, unsigned long addr)
{
	int ret = 0;
	int notloop = 0;
	int valid = 0;

	if (dns != 0xffffffff && dns != 0 && addr != dns && IS_A(netmask, dns, addr) && IS_B(netmask, dns, addr))
		valid = 1;
	if (valid && ((dns & 0xff000000) ^ 0x7f000000) != 0)
		notloop = 1;
	if (notloop && ((dns & 0xf0000000) ^ 0xe0000000) != 0)
		ret = 1;
	return ret;
}

/*
 * sdk:      SOCLi_IsIPv4ValidNodeAddr (libsoc.TWL.HYB.a(socl_misc.o))
 */
int SOCLi_IsIPv4ValidNodeAddr(unsigned long netmask, unsigned long addr)
{
	int ret = 0;
	int notloop = 0;
	int host = 0;
	unsigned long h = addr & ~netmask;

	if ((~netmask ^ h) != 0 && h != 0)
		host = 1;
	if (host && ((addr & 0xff000000) ^ 0x7f000000) != 0)
		notloop = 1;
	if (notloop && ((addr & 0xf0000000) ^ 0xe0000000) != 0)
		ret = 1;
	return ret;
}

/*
 * sdk:      SOCLi_CheckNConfig (libsoc.TWL.HYB.a(socl_misc.o))
 */
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

/*
 * function: SOC_GetHostByName
 * address:  0x0215F650
 * packet:   pkt_ov009_0215F650
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SOC_GetHostByName (libsoc.TWL.HYB.a(soc.o))
 *
 * symbols:
 *   SOCL_Resolve  0x0215EDD0  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   STD_CopyLString  0x0208CB10  arm
 *   gSocHostName     0x021AA544  data
 *   gSocStatics     0x021AA4BC  data
 *   g_021AA4BC_ip  0x021AA4BC  data
 *   gSocHostAddrList     0x021AA4D4  data
 *   gSocHostEnt     0x021AA4DC  data
 */

#include "../include/G_SOCLAlloc.h"

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

typedef struct {
	char *name;
	char **aliases;
	short addrType;
	short length;
	unsigned char **addrList;
} HostEnt;

extern unsigned long SOCL_Resolve(char *hostname);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int STD_CopyLString(char *destp, const char *srcp, int siz);

extern struct SOCLAlloc gSocStatics;
extern struct SOCLAlloc g_021AA4BC_ip;
extern unsigned char *gSocHostAddrList[2];
extern HostEnt gSocHostEnt;
extern char gSocHostName[0x101];

HostEnt *SOC_GetHostByName(const char *name)
{
	unsigned long h;

	h = SOCL_Resolve((char *)name);
	if (h == 0) {
		return 0;
	}
	MI_CpuFill8(gSocHostName, 0, 0x101);
	STD_CopyLString(gSocHostName, name, 0x101);
	gSocStatics.hostent_name = gSocHostName;
	gSocStatics.hostent_aliases = 0;
	gSocStatics.hostent_addrType = 2;
	gSocStatics.hostent_length = 4;
	gSocStatics.hostent_addrList = gSocHostAddrList;
	gSocStatics.addrList[0] = (unsigned char *)&(*(unsigned long *)&g_021AA4BC_ip);
	gSocStatics.addrList[1] = 0;
	gSocStatics.w00 = SWAP32(h);
	return &gSocHostEnt;
}

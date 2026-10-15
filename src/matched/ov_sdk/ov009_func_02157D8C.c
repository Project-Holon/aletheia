/*
 * function: inq_arpcache
 * address:  0x02157D8C
 * packet:   pkt_ov009_02157D8C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      inq_arpcache (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   is_broadcast  0x021578EC  arm  ov009
 *   is_multicast  0x02157928  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   gCpsNetVars  0x021A826C  data
 *   CPSMyMac  0x021A82D4  data
 *   gCpsBroadcastMac  0x021A1CA1  data
 *   gCpsArpCache  0x021A8384  data
 *   g_021A838E  0x021A838E  data
 */

#include "../include/G_ArpEntry.h"

struct NetVars {
	unsigned char pad0[0x50];
	unsigned long myip;
};

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long is_broadcast(unsigned long ip);
extern int is_multicast(unsigned v);
extern unsigned long long func_020870D0(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern struct NetVars gCpsNetVars;
extern unsigned char CPSMyMac[6];
extern unsigned char gCpsBroadcastMac[6];
extern struct ArpEntry gCpsArpCache[8];

unsigned char *inq_arpcache(unsigned long ip)
{
	unsigned long i;
	unsigned char (*result)[6];
	unsigned long enabled;

	enabled = OS_DisableInterrupts();
	result = 0;
	if (ip == 0x7f000001 || ip == gCpsNetVars.myip) {
		result = (unsigned char (*)[6])CPSMyMac;
	} else if (is_broadcast(ip) || is_multicast(ip)) {
		result = (unsigned char (*)[6])gCpsBroadcastMac;
	} else {
		for (i = 0; i < 8; i++) {
			if (ip == gCpsArpCache[i].ip) {
				gCpsArpCache[i].when = func_020870D0() >> 16;
				result = &gCpsArpCache[i].mac;
				break;
			}
		}
	}
	OS_RestoreInterrupts(enabled);
	return (unsigned char *)result;
}

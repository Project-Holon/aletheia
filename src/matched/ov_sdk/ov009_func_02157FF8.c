/*
 * function: reg_arpcache
 * address:  0x02157FF8
 * packet:   pkt_ov009_02157FF8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      reg_arpcache (libcps.TWL.HYB.a network.o)
 *
 * symbols:
 *   ip_islocal            0x02157888  arm  ov009
 *   is_multicast            0x02157928  arm  ov009
 *   OS_GetTick               0x020870D0  arm
 *   MI_CpuCopy               0x02082EA4  arm
 *   gCpsNetVars               0x021A826C  data
 *   gCpsArpCache               0x021A8384  data
 */

#include "../include/G_ArpEntry.h"

extern unsigned long ip_islocal(unsigned long ip);
extern int is_multicast(unsigned v);
extern unsigned long long OS_GetTick(void);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern unsigned char gCpsNetVars;
extern struct ArpEntry gCpsArpCache[8];

#define NV(off, type) (*(type *)((char *)&gCpsNetVars + (off)))

void reg_arpcache(unsigned char (*mac)[6], unsigned long ip, int new_entry)
{
	unsigned long i;
	unsigned long candidate;
	unsigned short now;
	unsigned short oldest_time;

	if (ip == 0x7f000001 || ip == NV(0x50, unsigned long))
		return;
	if (!ip_islocal(ip))
		return;
	if (is_multicast(ip))
		return;
	now = (unsigned short)(OS_GetTick() >> 16);
	for (i = 0; i < 8; i++) {
		if (gCpsArpCache[i].ip == ip) {
			gCpsArpCache[i].when = now;
			MI_CpuCopy(mac, gCpsArpCache[i].mac, 6);
			return;
		}
	}
	if (!new_entry)
		return;
	oldest_time = 0;
	candidate = 0;
	for (i = 0; i < 8; i++) {
		if (gCpsArpCache[i].ip == 0) {
			candidate = i;
			break;
		}
		if ((short)(now - gCpsArpCache[i].when) > oldest_time) {
			candidate = i;
			oldest_time = now - gCpsArpCache[i].when;
		}
	}
	gCpsArpCache[candidate].ip = ip;
	MI_CpuCopy(mac, gCpsArpCache[candidate].mac, 6);
	gCpsArpCache[candidate].when = now;
}

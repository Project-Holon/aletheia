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
 *   g_021A826C               0x021A826C  data
 *   g_021A8384               0x021A8384  data
 */

#include "../include/G_ArpEntry.h"

extern unsigned long ip_islocal(unsigned long ip);
extern int is_multicast(unsigned v);
extern unsigned long long OS_GetTick(void);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern unsigned char g_021A826C;
extern struct ArpEntry g_021A8384[8];

#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))

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
		if (g_021A8384[i].ip == ip) {
			g_021A8384[i].when = now;
			MI_CpuCopy(mac, g_021A8384[i].mac, 6);
			return;
		}
	}
	if (!new_entry)
		return;
	oldest_time = 0;
	candidate = 0;
	for (i = 0; i < 8; i++) {
		if (g_021A8384[i].ip == 0) {
			candidate = i;
			break;
		}
		if ((short)(now - g_021A8384[i].when) > oldest_time) {
			candidate = i;
			oldest_time = now - g_021A8384[i].when;
		}
	}
	g_021A8384[candidate].ip = ip;
	MI_CpuCopy(mac, g_021A8384[candidate].mac, 6);
	g_021A8384[candidate].when = now;
}

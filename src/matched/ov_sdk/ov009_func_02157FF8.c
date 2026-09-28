/*
 * function: func_02157FF8
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
 *   func_02157888            0x02157888  arm  ov009
 *   func_02157928            0x02157928  arm  ov009
 *   OS_GetTick               0x020870D0  arm
 *   MI_CpuCopy               0x02082EA4  arm
 *   g_021A826C               0x021A826C  data
 *   g_021A8384               0x021A8384  data
 */

typedef struct CPSArpCache {
	unsigned long ip;
	unsigned char mac[6];
	unsigned short time;
} CPSArpCache;

extern unsigned long func_02157888(unsigned long ip);
extern unsigned long func_02157928(unsigned long ip);
extern unsigned long long OS_GetTick(void);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern unsigned char g_021A826C;
extern CPSArpCache g_021A8384[8];

#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))

void func_02157FF8(unsigned char (*mac)[6], unsigned long ip, int new_entry)
{
	unsigned long i;
	unsigned long candidate;
	unsigned short now;
	unsigned short oldest_time;

	if (ip == 0x7f000001 || ip == NV(0x50, unsigned long))
		return;
	if (!func_02157888(ip))
		return;
	if (func_02157928(ip))
		return;
	now = (unsigned short)(OS_GetTick() >> 16);
	for (i = 0; i < 8; i++) {
		if (g_021A8384[i].ip == ip) {
			g_021A8384[i].time = now;
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
		if ((short)(now - g_021A8384[i].time) > oldest_time) {
			candidate = i;
			oldest_time = now - g_021A8384[i].time;
		}
	}
	g_021A8384[candidate].ip = ip;
	MI_CpuCopy(mac, g_021A8384[candidate].mac, 6);
	g_021A8384[candidate].time = now;
}

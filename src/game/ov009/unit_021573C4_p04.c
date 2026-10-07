/*
 * file:     unit_021573C4_p04.c
 * unit:     yes
 * function: func_02157FF8, func_02158134
 * address:  0x02157FF8
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
 *   func_02157888            0x02157888  arm  ov009
 *   func_02157928            0x02157928  arm  ov009
 *   OS_GetTick               0x020870D0  arm
 *   MI_CpuCopy               0x02082EA4  arm
 *   g_021A826C               0x021A826C  data
 *   g_021A8384               0x021A8384  data
 *   func_021578C8  0x021578C8  arm  ov009
 *   func_02157D8C  0x02157D8C  arm  ov009
 *   func_02157F60  0x02157F60  arm  ov009
 *   func_02082EA4  0x02082EA4  arm
 *   func_021579E8  0x021579E8  arm  ov009
 *   g_021A82D4  0x021A82D4  data
 */
#include "../../matched/include/G_ArpEntry.h"

#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))
extern unsigned long func_02157888(unsigned long ip);
extern int func_02157928(unsigned v);
extern unsigned long long OS_GetTick(void);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern unsigned long func_021578C8(unsigned long ip);
extern void func_02082EA4(void *src, void *dst, unsigned long size);
extern void func_021579E8(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
void func_02157FF8(unsigned char (*mac)[6], unsigned long ip, int new_entry);
void func_02158134(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned short type);
extern unsigned char g_021A826C;
extern struct ArpEntry g_021A8384[8];
extern unsigned char g_021A82D4[6];


/*
 * sdk:      reg_arpcache (libcps.TWL.HYB.a network.o)
 */
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

extern unsigned char (*func_02157D8C(unsigned long ip))[6];

extern unsigned char (*func_02157F60(unsigned long ip))[6];


/*
 * sdk:      send_ether (libcps.TWL.HYB.a(network.o))
 */
void func_02158134(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned short type)
{
	unsigned char (*mac_to)[6];

	*(unsigned short *)(hdr - 2) = (type >> 8) | (type << 8);
	if (!func_02157928(ip_to)) {
		ip_to = func_021578C8(ip_to);
		if (ip_to == 0)
			return;
		mac_to = func_02157D8C(ip_to);
		if (mac_to == 0)
			mac_to = func_02157F60(ip_to);
		if (mac_to == 0)
			return;
		func_02082EA4(mac_to, hdr - 0xe, 6);
	} else {
		hdr[-0xe] = 1;
		hdr[-0xd] = 0;
		hdr[-0xc] = 0x5e;
		hdr[-0xb] = (ip_to >> 16) & 0x7f;
		hdr[-0xa] = ip_to >> 8;
		hdr[-9] = ip_to;
	}
	func_02082EA4(g_021A82D4, hdr - 8, 6);
	func_021579E8(hdr - 0xe, hdr_len + 0xe, body, body_len);
}

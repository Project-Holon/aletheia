/*
 * file:     unit_021573C4_p10.c
 * unit:     yes
 * function: func_02157FF8, func_02158134, func_02158204
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
 *   func_0215781C            0x0215781C  arm  ov009
 *   OS_DisableInterrupts     0x02087988  arm
 *   func_02157A44            0x02157A44  arm  ov009
 *   OS_RestoreInterrupts     0x0208799C  arm
 *   g_021A1CC0               0x021A1CC0  data
 */
#include "../../matched/include/G_ArpEntry.h"

extern unsigned long func_02157888(unsigned long ip);
extern int func_02157928(unsigned v);
extern unsigned long long OS_GetTick(void);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern unsigned long func_021578C8(unsigned long ip);
extern void func_02082EA4(void *src, void *dst, unsigned long size);
extern void func_021579E8(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
extern unsigned short func_0215781C(unsigned char *s, unsigned long len);
extern unsigned long OS_DisableInterrupts(void);
extern void func_02157A44(unsigned char *srcAddr, unsigned char *dstAddr, unsigned char *buf1, unsigned long size1, unsigned char *buf2, unsigned long size2);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
/* * sdk: reg_arpcache (libcps.TWL.HYB.a network.o) */ void func_02157FF8(unsigned char (*mac)[6], unsigned long ip, int new_entry);
/* * sdk: send_ether (libcps.TWL.HYB.a(network.o)) */ void func_02158134(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned short type);
void func_02158204(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned long offset);
extern unsigned char g_021A826C;
extern struct ArpEntry g_021A8384[8];
extern unsigned char g_021A82D4[6];
extern char g_021A1CC0[];


#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))



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

static inline unsigned short swap16(unsigned short x)
{
	return (unsigned short)((x >> 8) | (x << 8));
}


/*
 * sdk:      send_ip_frag (libcps.TWL.HYB.a network.o)
 */
void func_02158204(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len, unsigned long ip_to, unsigned long offset)
{
	unsigned long enabled;

	*(unsigned short *)(hdr - 0x12) = swap16((unsigned short)(hdr_len + 0x14 + body_len));
	*(unsigned short *)(hdr - 0xe) = swap16((unsigned short)offset);
	*(unsigned short *)(hdr - 0xa) = 0;
	*(unsigned short *)(hdr - 0xa) = swap16(func_0215781C(hdr - 0x14, 0x14));
	if (ip_to != 0x7f000001 && ip_to != NV(0x50, unsigned long))
		func_02158134(hdr - 0x14, hdr_len + 0x14, body, body_len, ip_to, 0x800);
	if (ip_to != 0x7f000001 && ip_to != NV(0x50, unsigned long) && !func_02157928(ip_to))
		return;
	MI_CpuCopy(g_021A1CC0, hdr - 0x1c, 8);
	enabled = OS_DisableInterrupts();
	func_02157A44(g_021A82D4, g_021A82D4, hdr - 0x1c, hdr_len + 0x1c, body, body_len);
	OS_RestoreInterrupts(enabled);
}

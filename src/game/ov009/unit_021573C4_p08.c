/*
 * file:     unit_021573C4_p08.c
 * unit:     yes
 * function: func_02157D8C, func_02157E54
 * address:  0x02157D8C
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
 *   func_02087988  0x02087988  arm
 *   func_021578EC  0x021578EC  arm  ov009
 *   func_02157928  0x02157928  arm  ov009
 *   func_020870D0  0x020870D0  arm
 *   func_0208799C  0x0208799C  arm
 *   g_021A826C  0x021A826C  data
 *   g_021A82D4  0x021A82D4  data
 *   g_021A1CA1  0x021A1CA1  data
 *   g_021A8384  0x021A8384  data
 *   g_021A838E  0x021A838E  data
 *   MI_CpuFill8              0x02082BCC  arm
 *   MI_CpuCopy               0x02082EA4  arm
 *   func_021579E8            0x021579E8  arm  ov009
 */
#include "../../matched/include/G_ArpEntry.h"

struct NetVars {
	unsigned char pad0[0x50];
	unsigned long myip;
};

extern unsigned long func_02087988(void);
extern unsigned long func_021578EC(unsigned long ip);
extern int func_02157928(unsigned v);
extern unsigned long long func_020870D0(void);
extern unsigned long func_0208799C(unsigned long state);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern void MI_CpuCopy(void *srcp, void *destp, unsigned long size);
extern void func_021579E8(unsigned char *hdr, unsigned long hdr_len, unsigned char *body, unsigned long body_len);
unsigned char *func_02157D8C(unsigned long ip);
void func_02157E54(unsigned long ip);
extern struct NetVars g_021A826C;
extern unsigned char g_021A82D4[6];
extern unsigned char g_021A1CA1[6];
extern struct ArpEntry g_021A8384[8];


/*
 * sdk:      inq_arpcache (libcps.TWL.HYB.a(network.o))
 */
unsigned char *func_02157D8C(unsigned long ip)
{
	unsigned long i;
	unsigned char (*result)[6];
	unsigned long enabled;

	enabled = func_02087988();
	result = 0;
	if (ip == 0x7f000001 || ip == g_021A826C.myip) {
		result = (unsigned char (*)[6])g_021A82D4;
	} else if (func_021578EC(ip) || func_02157928(ip)) {
		result = (unsigned char (*)[6])g_021A1CA1;
	} else {
		for (i = 0; i < 8; i++) {
			if (ip == g_021A8384[i].ip) {
				g_021A8384[i].when = func_020870D0() >> 16;
				result = &g_021A8384[i].mac;
				break;
			}
		}
	}
	func_0208799C(enabled);
	return (unsigned char *)result;
}


#define NV(off, type) (*(type *)((char *)&g_021A826C + (off)))

#define SWAP16(x) ((unsigned short)(((x) >> 8) | ((x) << 8)))


static inline void put_ip(unsigned char *p, unsigned long v)
{
	*(unsigned short *)p = SWAP16((unsigned short)(v >> 16));
	*(unsigned short *)(p + 2) = SWAP16((unsigned short)v);
}


/*
 * sdk:      send_arprequest (libcps.TWL.HYB.a network.o)
 */
void func_02157E54(unsigned long ip)
{
	unsigned char buf[42];

	MI_CpuFill8(buf, 0, 42);
	MI_CpuFill8(buf, 0xff, 6);
	MI_CpuCopy(g_021A82D4, buf + 6, 6);
	*(unsigned short *)(buf + 12) = 0x0608;
	buf[15] = 1;
	buf[16] = 8;
	*(unsigned short *)(buf + 18) = 0x0406;
	buf[21] = 1;
	MI_CpuCopy(g_021A82D4, buf + 22, 6);
	put_ip(buf + 28, NV(0x50, unsigned long));
	put_ip(buf + 38, ip);
	func_021579E8(buf, 42, 0, 0);
}

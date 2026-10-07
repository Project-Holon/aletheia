/*
 * function: func_02157D8C
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
 */

#include "../include/G_ArpEntry.h"

struct NetVars {
	unsigned char pad0[0x50];
	unsigned long myip;
};

extern unsigned long func_02087988(void);
extern unsigned long func_021578EC(unsigned long ip);
extern int func_02157928(unsigned v);
extern unsigned long long func_020870D0(void);
extern unsigned long func_0208799C(unsigned long state);
extern struct NetVars g_021A826C;
extern unsigned char g_021A82D4[6];
extern unsigned char g_021A1CA1[6];
extern struct ArpEntry g_021A8384[8];

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

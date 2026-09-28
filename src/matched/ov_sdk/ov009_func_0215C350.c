/*
 * function: func_0215C350
 * address:  0x0215C350
 * packet:   pkt_ov009_0215C350
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dhcp_request_server (libcps.TWL.HYB.a(network.o))
 *
 * symbols:
 *   func_0215AB10  0x0215AB10  arm  ov009
 *   func_0215AA88  0x0215AA88  arm  ov009
 *   func_0215AAB0  0x0215AAB0  arm  ov009
 *   func_0215BE80  0x0215BE80  arm  ov009
 *   func_0215BF88  0x0215BF88  arm  ov009
 *   func_0215AB5C  0x0215AB5C  arm  ov009
 *   g_021A826C     0x021A826C  data
 */

struct NetVars {
	unsigned char pad0[0x1c];
	unsigned long dhcp_server_ip;
	unsigned char pad1[0x1c];
	unsigned long lease_time;
	unsigned long lease_sleep;
};

extern void func_0215AB10(void);
extern void func_0215AA88(void);
extern void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern unsigned long func_0215BE80(int mode);
extern int func_0215BF88(unsigned long id, int retry);
extern void func_0215AB5C(void);
extern struct NetVars g_021A826C;

int func_0215C350(unsigned long *sleep, int mode)
{
	int result;
	int retry;
	unsigned long save;

	func_0215AB10();
	func_0215AA88();
	if (mode == 1)
		func_0215AAB0(0x44, 0x43, g_021A826C.dhcp_server_ip);
	else
		func_0215AAB0(0x44, 0x43, 0xffffffff);
	for (retry = 0; retry < 5; retry++) {
		result = func_0215BF88(func_0215BE80(mode), retry);
		if (result != 0 && result != 1)
			break;
	}
	func_0215AB5C();
	if (result == 2) {
		*sleep = g_021A826C.lease_time >> 1;
		g_021A826C.lease_sleep = (g_021A826C.lease_time * 3) >> 3;
		return 1;
	}
	save = g_021A826C.lease_sleep >> 1;
	g_021A826C.lease_sleep = save;
	*sleep = save;
	switch (mode) {
	case 1:
		if (save < 0x3c) {
			*sleep = 1;
			g_021A826C.lease_sleep = g_021A826C.lease_time >> 3;
		}
		break;
	case 2:
		if (save < 0x3c)
			*sleep = 1;
		break;
	}
	return 0;
}

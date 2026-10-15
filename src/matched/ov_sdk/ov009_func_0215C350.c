/*
 * function: dhcp_request_server
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
 *   CPS_SocUse  0x0215AB10  arm  ov009
 *   CPS_SocDatagramMode  0x0215AA88  arm  ov009
 *   CPS_SocBind  0x0215AAB0  arm  ov009
 *   dhcp_send_request  0x0215BE80  arm  ov009
 *   dhcp_analyze_response  0x0215BF88  arm  ov009
 *   CPS_SocRelease  0x0215AB5C  arm  ov009
 *   gCpsNetVars     0x021A826C  data
 */

struct NetVars {
	unsigned char pad0[0x1c];
	unsigned long dhcp_server_ip;
	unsigned char pad1[0x1c];
	unsigned long lease_time;
	unsigned long lease_sleep;
};

extern void CPS_SocUse(void);
extern void CPS_SocDatagramMode(void);
extern void CPS_SocBind(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern unsigned long dhcp_send_request(int mode);
extern int dhcp_analyze_response(unsigned long id, int retry);
extern void CPS_SocRelease(void);
extern struct NetVars gCpsNetVars;

int dhcp_request_server(unsigned long *sleep, int mode)
{
	int result;
	int retry;
	unsigned long save;

	CPS_SocUse();
	CPS_SocDatagramMode();
	if (mode == 1)
		CPS_SocBind(0x44, 0x43, gCpsNetVars.dhcp_server_ip);
	else
		CPS_SocBind(0x44, 0x43, 0xffffffff);
	for (retry = 0; retry < 5; retry++) {
		result = dhcp_analyze_response(dhcp_send_request(mode), retry);
		if (result != 0 && result != 1)
			break;
	}
	CPS_SocRelease();
	if (result == 2) {
		*sleep = gCpsNetVars.lease_time >> 1;
		gCpsNetVars.lease_sleep = (gCpsNetVars.lease_time * 3) >> 3;
		return 1;
	}
	save = gCpsNetVars.lease_sleep >> 1;
	gCpsNetVars.lease_sleep = save;
	*sleep = save;
	switch (mode) {
	case 1:
		if (save < 0x3c) {
			*sleep = 1;
			gCpsNetVars.lease_sleep = gCpsNetVars.lease_time >> 3;
		}
		break;
	case 2:
		if (save < 0x3c)
			*sleep = 1;
		break;
	}
	return 0;
}

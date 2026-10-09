/*
 * file:     unit_021573C4_p35.c
 * unit:     yes
 * function: func_0215C2F8, func_0215C350, func_0215C44C
 * address:  0x0215C2F8
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
 *   func_0215AB10  0x0215AB10  arm  ov009
 *   func_0215AA88  0x0215AA88  arm  ov009
 *   func_0215AAB0  0x0215AAB0  arm  ov009
 *   func_0215BD8C  0x0215BD8C  arm  ov009
 *   func_0215BF88  0x0215BF88  arm  ov009
 *   func_0215AB5C  0x0215AB5C  arm  ov009
 *   func_0215BE80  0x0215BE80  arm  ov009
 *   g_021A826C     0x021A826C  data
 *   func_0215BC04  0x0215BC04  arm  ov009
 *   func_0215BD58  0x0215BD58  arm  ov009
 *   func_0215B470  0x0215B470  arm  ov009
 *   g_021A878E  0x021A878E  data
 */
struct NetVars_021573C4 {
	unsigned char pad0[0x1c];
	unsigned long dhcp_server_ip;
	unsigned char pad1[0x1c];
	unsigned long lease_time;
	unsigned long lease_sleep;
};

struct NetVars_0215C44C {
	unsigned char pad0[0x1c];
	unsigned long dhcp_server_ip;
};

extern void func_0215AB10(void);
extern void func_0215AA88(void);
extern void func_0215AAB0(unsigned short local_port, unsigned short remote_port, unsigned long remote_ip);
extern unsigned long func_0215BD8C(void);
extern int func_0215BF88(unsigned long id, int retry);
extern void func_0215AB5C(void);
extern unsigned long func_0215BE80(int mode);
extern unsigned char *func_0215BC04(unsigned char *d, int type);
extern unsigned char *func_0215BD58(unsigned char pattern, unsigned long minimum, unsigned char *d, unsigned long curlen);
extern unsigned long func_0215B470(unsigned char *buf, unsigned long len);
/* * sdk: dhcp_discover_server (libcps.TWL.HYB.a(network.o)) */ int func_0215C2F8(void);
/* * sdk: dhcp_request_server (libcps.TWL.HYB.a(network.o)) */ int func_0215C350(unsigned long *sleep, int mode);
void func_0215C44C(void);
extern struct NetVars_021573C4 g_021A826C;
extern unsigned char g_021A878E[];



/*
 * sdk:      dhcp_discover_server (libcps.TWL.HYB.a(network.o))
 */
int func_0215C2F8(void)
{
    int result;
    int retry;

    func_0215AB10();
    func_0215AA88();
    func_0215AAB0(0x44, 0x43, 0xffffffff);
    for (retry = 0; retry < 5; retry++) {
        result = func_0215BF88(func_0215BD8C(), retry);
        if (result == 1)
            break;
    }
    func_0215AB5C();
    return result == 1;
}



/*
 * sdk:      dhcp_request_server (libcps.TWL.HYB.a(network.o))
 */
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


/*
 * sdk:      dhcp_release_server (libcps.TWL.HYB.a(network.o))
 */
void func_0215C44C(void)
{
	unsigned char *buf;
	unsigned char *d;

	func_0215AB10();
	func_0215AA88();
	func_0215AAB0(0x44, 0x43, g_021A826C.dhcp_server_ip);
	buf = g_021A878E;
	d = func_0215BC04(buf, 7);
	*d++ = 0x36;
	*d++ = 4;
	*d++ = (unsigned short)(g_021A826C.dhcp_server_ip >> 16) >> 8;
	*d++ = g_021A826C.dhcp_server_ip >> 16;
	*d++ = (unsigned short)g_021A826C.dhcp_server_ip >> 8;
	*d++ = g_021A826C.dhcp_server_ip;
	*d++ = 0xff;
	d = func_0215BD58(0, 300, d, d - buf);
	func_0215B470(buf, d - buf);
	func_0215AB5C();
}

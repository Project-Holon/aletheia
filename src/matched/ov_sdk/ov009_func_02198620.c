/*
 * function: func_02198620
 * address:  0x02198620
 * packet:   pkt_ov009_02198620
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gt2AddressToString (libdwcgsgt2.TWL.HYB.a(gt2utility.o))
 *
 * symbols:
 *   func_0215FA9C  0x0215FA9C  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   g_021AE41C  0x021AE41C  data
 *   g_021AE420  0x021AE420  data
 *   g_021A594C  0x021A594C  data
 *   g_021A5954  0x021A5954  data
 *   g_021A5958  0x021A5958  data
 */

typedef struct SOCInAddr {
	unsigned int addr;
} SOCInAddr;

extern char *func_0215FA9C(SOCInAddr in);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern int g_021AE41C;
extern char g_021AE420[][22];
extern char g_021A594C[];
extern char g_021A5954[];
extern char g_021A5958[];

char *func_02198620(unsigned int ip, unsigned short port, char *string)
{
	char *strAddress;
	SOCInAddr inAddr;

	if (string == 0) {
		g_021AE41C ^= 1;
		string = g_021AE420[g_021AE41C];
	}
	if (ip != 0) {
		inAddr.addr = ip;
		if (port != 0) {
			strAddress = func_0215FA9C(inAddr);
			OS_SPrintf(string, g_021A594C, strAddress, port);
		} else {
			strAddress = func_0215FA9C(inAddr);
			OS_SPrintf(string, g_021A5954, strAddress);
		}
	} else {
		if (port != 0)
			OS_SPrintf(string, g_021A5958, port);
		else
			string[0] = 0;
	}
	return string;
}

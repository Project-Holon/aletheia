/*
 * function: gt2AddressToString
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
 *   gGt2StringTableIndex  0x021AE41C  data
 *   gGt2StringTable  0x021AE420  data
 *   gGt2AddressPortFmt  0x021A594C  data
 *   gGt2AddressFmt  0x021A5954  data
 *   gGt2PortFmt  0x021A5958  data
 */

typedef struct SOCInAddr {
	unsigned int addr;
} SOCInAddr;

extern char *func_0215FA9C(SOCInAddr in);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern int gGt2StringTableIndex;
extern char gGt2StringTable[][22];
extern char gGt2AddressPortFmt[];
extern char gGt2AddressFmt[];
extern char gGt2PortFmt[];

char *gt2AddressToString(unsigned int ip, unsigned short port, char *string)
{
	char *strAddress;
	SOCInAddr inAddr;

	if (string == 0) {
		gGt2StringTableIndex ^= 1;
		string = gGt2StringTable[gGt2StringTableIndex];
	}
	if (ip != 0) {
		inAddr.addr = ip;
		if (port != 0) {
			strAddress = func_0215FA9C(inAddr);
			OS_SPrintf(string, gGt2AddressPortFmt, strAddress, port);
		} else {
			strAddress = func_0215FA9C(inAddr);
			OS_SPrintf(string, gGt2AddressFmt, strAddress);
		}
	} else {
		if (port != 0)
			OS_SPrintf(string, gGt2PortFmt, port);
		else
			string[0] = 0;
	}
	return string;
}

/*
 * function: func_02198958
 * address:  0x02198958
 * packet:   pkt_ov009_02198958
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GetLocalPort (libdwcgsnatneg.TWL.HYB.a(natify.o))
 *
 * symbols:
 *   func_0217ED0C  0x0217ED0C  arm  ov009
 */

typedef struct SOCSockAddrIn {
	unsigned char len;
	unsigned char family;
	unsigned short port;
	unsigned int addr;
} SOCSockAddrIn;

extern int func_0217ED0C(int sock, void *addr, int *len);

unsigned short func_02198958(int sock)
{
	int ret;
	SOCSockAddrIn saddr;
	int saddrlen;

	saddrlen = 8;
	ret = func_0217ED0C(sock, &saddr, &saddrlen);
	if (ret == -1)
		return 0;
	return saddr.port;
}

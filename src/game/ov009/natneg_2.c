/*
 * file:     natneg_2.c
 * unit:     yes
 * function: func_021992FC, func_02199360
 * address:  0x021992FC
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
 *   func_0217EFB8  0x0217EFB8  arm  ov009
 *   func_0217F038  0x0217F038  arm  ov009
 *   func_0217ED0C  0x0217ED0C  arm  ov009
 */
typedef struct SOCInAddr {
    unsigned int addr;
} SOCInAddr;

typedef struct SOCHostEnt {
    unsigned char pad0[0xC];
    SOCInAddr **addrList;
} SOCHostEnt;

typedef struct SOCSockAddrIn {
	unsigned char len;
	unsigned char family;
	unsigned short port;
	unsigned int addr;
} SOCSockAddrIn;

extern SOCHostEnt *func_0217EFB8(void);
extern int func_0217F038(SOCInAddr *addr);
extern int func_0217ED0C(int sock, void *addr, int *len);
unsigned int func_021992FC(void);
unsigned short func_02199360(int sock);


unsigned int func_021992FC(void)
{
    int num_local_ips;
    SOCHostEnt *phost;
    SOCInAddr *addr;
    unsigned int localip;

    localip = 0;
    phost = func_0217EFB8();
    if (!phost)
        return 0;
    for (num_local_ips = 0;; num_local_ips++) {
        addr = phost->addrList[num_local_ips];
        if (!addr)
            break;
        if (addr->addr != 16777343) {
            localip = *(unsigned int *)addr;
            if (func_0217F038((SOCInAddr *)addr))
                return localip;
        }
    }
    return localip;
}


unsigned short func_02199360(int sock)
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

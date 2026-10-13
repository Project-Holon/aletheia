/*
 * file:     soc_3.c
 * unit:     yes
 * function: SOC_GetHostByName, SOC_GetSockName, SOC_GetHostID, SOC_SetResolver, SOC_Fcntl, func_0215F8A4, FreeFunc_SOCL, SOC_Startup, SOC_Cleanup, SOC_InetNtoA, SOC_InetAtoN, SOC_InetNtoP, SOC_U32to4U8_Alt, SOC_Poll
 * address:  0x0215F650
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0215EDD0  0x0215EDD0  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_0208CB10  0x0208CB10  arm
 *   g_021AA544     0x021AA544  data
 *   g_021AA4BC     0x021AA4BC  data
 *   g_021AA4BC_ip  0x021AA4BC  data
 *   g_021AA4D4     0x021AA4D4  data
 *   g_021AA4DC     0x021AA4DC  data
 *   SOCL_GetHostID   0x0215ef48 arm
 *   func_0215EEE0  0x0215EEE0  arm  ov009
 *   func_0215CA8C  0x0215CA8C  arm  ov009
 *   func_0215F8A4  0x0215F8A4  arm  ov009
 *   func_0215F8D0  0x0215F8D0  arm  ov009
 *   g_021AA50C     0x021AA50C  data
 *   func_0215EBF0  0x0215EBF0  arm  ov009
 *   _ZZ12SOC_InetNtoA9SOCInAddrE6buffer   0x021aa4ec data
 *   func_0215EE98  0x0215EE98  arm  ov009
 *   MI_CpuCopy8      0x02082d44 arm
 *   SOC_U32to4U8     0x0215fbac arm
 *   OS_SNPrintf      0x02084f80 arm
 *   g_021A1D2C       0x021a1d2c data
 *   func_0215EFB0  0x0215EFB0  arm  ov009
 *   func_02085A38  0x02085A38  arm
 */
#include "../../matched/include/G_SOCLAlloc.h"

typedef struct {
	char *name;
	char **aliases;
	short addrType;
	short length;
	unsigned char **addrList;
} HostEnt;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned long  u32;

typedef struct {
	unsigned char pad[0xae];
	signed char flag;
} Sock;

typedef struct SOCConfig {
    unsigned short vendor;
    unsigned short version;
    void *(*alloc)(u32, long);
    void (*free)(u32, void *, long);
    u32 flag;
    u32 addr;
    u32 netmask;
    u32 router;
    u32 dns1;
    u32 dns2;
    long timeWaitBuffer;
    long reassemblyBuffer;
    long mtu;
    long rwin;
} SOCConfig;

typedef struct SOCLConfig {
    int use_dhcp;
    u32 my_ip;
    u32 net_mask;
    u32 gateway_ip;
    u32 dns_ip0;
    u32 dns_ip1;
    void *(*alloc)(u32);
    void (*free)(void *);
    u32 cmd_packet_max;
    u32 pad24[3];
    long mtu;
    long rwin;
} SOCLConfig;

typedef struct SOCStatics {
    u32 hostip;
    void (*FreeFunc_SOC)(u32, void *, long);
    char pad8[4];
    void *(*AllocFunc_SOC)(u32, long);
    char pad10[8];
    unsigned char *addrList[2];
    char *hostent_name;
    char **hostent_aliases;
    short hostent_addrType;
    short hostent_length;
    unsigned char **hostent_addrList;
    char pad30[0x20];
    SOCLConfig soclConfig;
} SOCStatics;

struct SOCInAddr {
    unsigned long addr;
};

typedef struct {
	int fd;
	short events;
	short revents;
} PollFD;

extern unsigned long func_0215EDD0(char *hostname);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int func_0208CB10(char *destp, const char *srcp, int siz);
extern unsigned long SOCL_GetHostID(void);
extern int func_0215EEE0(unsigned long dns1, unsigned long dns2);
extern int func_0215CA8C(void *socl_config);
extern unsigned long func_0215EE98(char *hostname);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void SOC_U32to4U8(unsigned long adr_u32, unsigned char *adr_4u8);
extern int OS_SNPrintf(char *dst, unsigned long len, char *fmt, ...);
extern int func_0215EFB0(int s);
extern void func_02085A38(unsigned long msec);
HostEnt *SOC_GetHostByName(const char *name);
int SOC_GetSockName(u8 *sock, u8 *sockAddr);
long SOC_GetHostID(void);
int SOC_SetResolver(unsigned long *dns1, unsigned long *dns2);
int SOC_Fcntl(Sock *s, int cmd, int flags);
int SOC_Startup(const SOCConfig *config);
int SOC_InetAtoN(char *cp, unsigned long *inp);
char *SOC_InetNtoP(int af, void *src, char *dst, unsigned int len);
void SOC_U32to4U8_Alt(unsigned addr32, unsigned char *addr4);
int SOC_Poll(PollFD *fds, unsigned int nfds, long long timeout);
extern SOCStatics g_021AA4BC;
extern u32 g_021AA4BC_ip;
extern unsigned char *g_021AA4D4[2];
extern HostEnt g_021AA4DC;
extern char g_021AA544[0x101];
extern SOCLConfig g_021AA50C;
extern char _ZZ12SOC_InetNtoA9SOCInAddrE6buffer[16];
extern char g_021A1D2C[];

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))
extern int func_0215EBF0(void);
int SOC_Cleanup(void);



/*
 * sdk:      SOC_GetHostByName (libsoc.TWL.HYB.a(soc.o))
 */
HostEnt *SOC_GetHostByName(const char *name)
{
	unsigned long ipAddr;

	ipAddr = func_0215EDD0((char *)name);
	if (ipAddr == 0) {
		return 0;
	}
	MI_CpuFill8(g_021AA544, 0, 0x101);
	func_0208CB10(g_021AA544, name, 0x101);
	g_021AA4BC.hostent_name = g_021AA544;
	g_021AA4BC.hostent_aliases = 0;
	g_021AA4BC.hostent_addrType = 2;
	g_021AA4BC.hostent_length = 4;
	g_021AA4BC.hostent_addrList = g_021AA4D4;
	g_021AA4BC.addrList[0] = (unsigned char *)&g_021AA4BC_ip;
	g_021AA4BC.addrList[1] = 0;
	g_021AA4BC.hostip = SWAP32(ipAddr);
	return &g_021AA4DC;
}



/*
 * Fills the socket address at `sockAddr`: length byte 8, family 2, then the
 * byte-swapped port (halfword at sock+0xb0, 0 when no host id) and the
 * byte-swapped host id from SOCL_GetHostID. A null socket returns -0x27.
 */
int SOC_GetSockName(u8 *sock, u8 *sockAddr)
{
    u32 hostId;
    u16 port;

    if (sock == 0)
        return -0x27;

    hostId = SOCL_GetHostID();
    port = sock ? *(u16 *)(sock + 0xb0) : 0;
    port = hostId ? port : 0;

    sockAddr[0] = 8;
    sockAddr[1] = 2;
    *(u16 *)(sockAddr + 2) = (u16)(((port >> 8) & 0xff) | ((port << 8) & 0xff00));
    *(u32 *)(sockAddr + 4) = ((hostId >> 24) & 0xff) | ((hostId >> 8) & 0xff00)
                      | ((hostId << 8) & 0xff0000) | ((hostId << 24) & 0xff000000);
    return 0;
}



long SOC_GetHostID(void)
{
    unsigned long hostId = SOCL_GetHostID();

    return (long)(((hostId >> 24) & 0xff) | ((hostId >> 8) & 0xff00)
                | ((hostId << 8) & 0xff0000) | ((hostId << 24) & 0xff000000));
}



/*
 * sdk:      SOC_SetResolver (libsoc.TWL.HYB.a(soc.o))
 */
int SOC_SetResolver(unsigned long *dns1, unsigned long *dns2)
{
	return func_0215EEE0(SWAP32(*dns1), SWAP32(*dns2));
}



/*
 * sdk:      SOC_Fcntl (libsoc.TWL.HYB.a(soc.o))
 */
int SOC_Fcntl(Sock *s, int cmd, int flags)
{
	if (s == 0) {
		return -1;
	}
	switch (cmd) {
	case 3:
		if (s->flag == 1) {
			return 0;
		}
		return 4;
	case 4:
		if (flags & 4) {
			s->flag = 0;
		} else {
			s->flag = 1;
		}
		break;
	}
	return 0;
}



static void *AllocFunc_SOCL(unsigned long size)
{
    unsigned long *m;
    unsigned long msize = size + 4;

    m = (unsigned long *)g_021AA4BC.AllocFunc_SOC(0, msize);
    if (m != 0)
        *m++ = msize;
    return m;
}


static void FreeFunc_SOCL(void *ptr)
{
    unsigned long *m;

    if (ptr == 0)
        return;
    m = (unsigned long *)((char *)ptr - 4);
    g_021AA4BC.FreeFunc_SOC(0, m, *m);
}


/*
 * sdk:      SOC_Startup (libsoc.TWL.HYB.a(soc.o))
 *
 * soc.o's statics sit in one block; the vendor addresses the stores through
 * one pool word anchored at 0x021AA4BC (hostip_1 of SOC_GetHostByName) and
 * passes soclConfig (0x021AA50C, block +0x50) by its own symbol, so the block
 * is written as a struct overlay named by offset and the call argument as its
 * own extern.
 */
int SOC_Startup(const SOCConfig *config)
{
    g_021AA4BC.soclConfig.use_dhcp = (config->flag == 1);
    g_021AA4BC.soclConfig.my_ip = SWAP32(config->addr);
    g_021AA4BC.soclConfig.net_mask = SWAP32(config->netmask);
    g_021AA4BC.soclConfig.gateway_ip = SWAP32(config->router);
    g_021AA4BC.soclConfig.dns_ip0 = SWAP32(config->dns1);
    g_021AA4BC.soclConfig.dns_ip1 = SWAP32(config->dns2);
    g_021AA4BC.soclConfig.alloc = AllocFunc_SOCL;
    g_021AA4BC.soclConfig.free = FreeFunc_SOCL;
    g_021AA4BC.AllocFunc_SOC = config->alloc;
    g_021AA4BC.FreeFunc_SOC = config->free;
    g_021AA4BC.soclConfig.cmd_packet_max = 0x40;
    g_021AA4BC.soclConfig.mtu = config->mtu;
    g_021AA4BC.soclConfig.rwin = config->rwin;
    return func_0215CA8C(&g_021AA50C);
}

/*
 * Tail call to SOCL_Cleanup; sits between SOC_Startup and SOC_InetNtoA in
 * soc.o, so it is SOC_Cleanup.
 */
int SOC_Cleanup(void)
{
    return func_0215EBF0();
}

char *SOC_InetNtoA(struct SOCInAddr in)
{
    SOC_InetNtoP(2, &in, _ZZ12SOC_InetNtoA9SOCInAddrE6buffer, 16);
    return _ZZ12SOC_InetNtoA9SOCInAddrE6buffer;
}




/*
 * sdk:      SOC_InetAtoN (libsoc.TWL.HYB.a(soc.o))
 */
int SOC_InetAtoN(char *cp, unsigned long *inp)
{
	unsigned long ipAddr;

	ipAddr = func_0215EE98(cp);
	if (ipAddr == 0) {
		return 0;
	}
	if (inp != 0) {
		*inp = SWAP32(ipAddr);
	}
	return 1;
}



char *SOC_InetNtoP(int af, void *src, char *dst, unsigned int len)
{
    unsigned long addr32;
    unsigned char addr[4];

    if (af != 2)
        return 0;
    if (len < 0x10)
        return 0;
    MI_CpuCopy8(src, &addr32, 4);
    SOC_U32to4U8(addr32, addr);
    OS_SNPrintf(dst, 16, g_021A1D2C, addr[3], addr[2], addr[1], addr[0]);
    return dst;
}


/*
 * Writes a word big-endian into four bytes.
 */
void SOC_U32to4U8_Alt(unsigned addr32, unsigned char *addr4)
{
    addr4[0] = (unsigned char)(addr32 >> 24);
    addr4[1] = (unsigned char)(addr32 >> 16);
    addr4[2] = (unsigned char)(addr32 >> 8);
    addr4[3] = (unsigned char)addr32;
}



/*
 * sdk:      SOC_Poll (libsoc.TWL.HYB.a(soc.o))
 */
int SOC_Poll(PollFD *fds, unsigned int nfds, long long timeout)
{
	PollFD *fp;
	int is_enable_timeout;
	long long time;
	unsigned int i;
	int num_good;
	int status;
	int status_mask;

	if (nfds == 0 || fds == 0) {
		return 0;
	}
	time = timeout;
	is_enable_timeout = (time != -1);
	for (;;) {
		num_good = 0;
		fp = fds;
		for (i = 0; i < nfds; i++, fp++) {
			status_mask = fp->events | 0xe0;
			status = status_mask & func_0215EFB0(fp->fd);
			fp->revents = (short)status;
			if (status) {
				num_good++;
			}
		}
		if (num_good > 0) {
			break;
		}
		if (is_enable_timeout && time <= 0) {
			break;
		}
		func_02085A38(1);
		time -= 523;
	}
	return num_good;
}

/*
 * file:     unit_0215F650_p01.c
 * unit:     yes
 * function: func_0215F650, func_0215F714, func_0215F7B0, func_0215F7E8, func_0215F854, func_0215F8A4, FreeFunc_SOCL, func_0215F8FC
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
 *   func_02082BCC  0x02082BCC  arm
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
extern void func_02082BCC(void *dstp, unsigned char data, unsigned long size);
extern int func_0208CB10(char *destp, const char *srcp, int siz);
extern int func_0215EF48(void);
extern unsigned long SOCL_GetHostID(void);
extern int func_0215EEE0(unsigned long dns1, unsigned long dns2);
extern int func_0215CA8C(void *socl_config);
extern unsigned long func_0215EE98(char *hostname);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void SOC_U32to4U8(unsigned long adr_u32, unsigned char *adr_4u8);
extern int OS_SNPrintf(char *dst, unsigned long len, char *fmt, ...);
extern int func_0215EFB0(int s);
extern void func_02085A38(unsigned long msec);
HostEnt *func_0215F650(const char *name);
int func_0215F714(u8 *p, u8 *dst);
long SOC_GetHostID(void);
int func_0215F7E8(unsigned long *dns1, unsigned long *dns2);
int func_0215F854(Sock *s, int cmd, int mode);
int func_0215F8FC(const SOCConfig *config);
int func_0215FAD0(char *cp, unsigned long *inp);
char *SOC_InetNtoP(int af, void *src, char *dst, unsigned int len);
void func_0215FBAC(unsigned v, unsigned char *p);
int func_0215FBCC(PollFD *fds, unsigned int nfds, long long timeout);
extern SOCStatics g_021AA4BC;
extern u32 g_021AA4BC_ip;
extern unsigned char *g_021AA4D4[2];
extern HostEnt g_021AA4DC;
extern char g_021AA544[0x101];
extern SOCLConfig g_021AA50C;
extern char _ZZ12SOC_InetNtoA9SOCInAddrE6buffer[16];
extern char g_021A1D2C[];

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))



/*
 * sdk:      SOC_GetHostByName (libsoc.TWL.HYB.a(soc.o))
 */
HostEnt *func_0215F650(const char *name)
{
	unsigned long h;

	h = func_0215EDD0((char *)name);
	if (h == 0) {
		return 0;
	}
	func_02082BCC(g_021AA544, 0, 0x101);
	func_0208CB10(g_021AA544, name, 0x101);
	g_021AA4BC.hostent_name = g_021AA544;
	g_021AA4BC.hostent_aliases = 0;
	g_021AA4BC.hostent_addrType = 2;
	g_021AA4BC.hostent_length = 4;
	g_021AA4BC.hostent_addrList = g_021AA4D4;
	g_021AA4BC.addrList[0] = (unsigned char *)&g_021AA4BC_ip;
	g_021AA4BC.addrList[1] = 0;
	g_021AA4BC.hostip = SWAP32(h);
	return &g_021AA4DC;
}



/*
 * Build a packet header at `dst`: tag bytes 8, 2, then the byte-swapped
 * halfword at p+0xb0 and the byte-swapped word returned by func_0215EF48.
 * A null p returns -0x27.
 */
int func_0215F714(u8 *p, u8 *dst)
{
    u32 r;
    u16 t;

    if (p == 0)
        return -0x27;

    r = func_0215EF48();
    t = p ? *(u16 *)(p + 0xb0) : 0;
    t = r ? t : 0;

    dst[0] = 8;
    dst[1] = 2;
    *(u16 *)(dst + 2) = (u16)(((t >> 8) & 0xff) | ((t << 8) & 0xff00));
    *(u32 *)(dst + 4) = ((r >> 24) & 0xff) | ((r >> 8) & 0xff00)
                      | ((r << 8) & 0xff0000) | ((r << 24) & 0xff000000);
    return 0;
}



long SOC_GetHostID(void)
{
    unsigned long hostid = SOCL_GetHostID();

    return (long)(((hostid >> 24) & 0xff) | ((hostid >> 8) & 0xff00)
                | ((hostid << 8) & 0xff0000) | ((hostid << 24) & 0xff000000));
}



/*
 * sdk:      SOC_SetResolver (libsoc.TWL.HYB.a(soc.o))
 */
int func_0215F7E8(unsigned long *dns1, unsigned long *dns2)
{
	return func_0215EEE0(SWAP32(*dns1), SWAP32(*dns2));
}



/*
 * sdk:      SOC_Fcntl (libsoc.TWL.HYB.a(soc.o))
 */
int func_0215F854(Sock *s, int cmd, int mode)
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
		if (mode & 4) {
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
int func_0215F8FC(const SOCConfig *config)
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

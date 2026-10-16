/*
 * file:     soc.c
 * unit:     yes
 * function: SOC_Socket, func_0215F454, SOC_Connect, SOC_Recv, SOC_RecvFrom, SOC_Send, func_0215F5B4, SOC_Shutdown, SOC_Close, SOC_GetHostByName, SOC_GetSockName, SOC_GetHostID, SOC_SetResolver, SOC_Fcntl, func_0215F8A4, FreeFunc_SOCL, SOC_Startup, SOC_Cleanup, SOC_InetNtoA, SOC_InetAtoN, SOC_InetNtoP, SOC_U32to4U8, SOC_Poll
 * address:  0x0215F428
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
 *   SOCL_CreateSocket    0x0215d070 arm
 *   SOCLSocketParamTCP   0x021a1cfc data
 *   SOCLSocketParamUDP   0x021a1ce4 data
 *   SOCL_Bind   0x0215d43c arm
 *   SOCL_Connect     0x0215d4ac arm
 *   SOCL_ReadFrom   0x0215d6c8 arm
 *   SOCL_WriteTo   0x0215e024 arm
 *   SOCL_Resolve  0x0215EDD0  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   STD_CopyLString  0x0208CB10  arm
 *   gSocHostName     0x021AA544  data
 *   gSocStatics     0x021AA4BC  data
 *   g_021AA4BC_ip  0x021AA4BC  data
 *   gSocHostAddrList     0x021AA4D4  data
 *   gSocHostEnt     0x021AA4DC  data
 *   SOCL_GetHostID   0x0215ef48 arm
 *   SOCL_SetResolver  0x0215EEE0  arm  ov009
 *   SOCL_Startup  0x0215CA8C  arm  ov009
 *   func_0215F8A4  0x0215F8A4  arm  ov009
 *   func_0215F8D0  0x0215F8D0  arm  ov009
 *   gSoclStartupConfig     0x021AA50C  data
 *   SOCL_Cleanup  0x0215EBF0  arm  ov009
 *   _ZZ12SOC_InetNtoA9SOCInAddrE6buffer   0x021aa4ec data
 *   SOCL_InetAtoH  0x0215EE98  arm  ov009
 *   MI_CpuCopy8      0x02082d44 arm
 *   OS_SNPrintf      0x02084f80 arm
 *   gSoclIpv4Format       0x021a1d2c data
 *   SOCL_GetStatus  0x0215EFB0  arm  ov009
 *   OS_Sleep  0x02085A38  arm
 *   SOCL_Close  0x0215E84C  arm
 */
#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))
#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))
struct SOCLSocketParam {
    unsigned long w[16];
};

struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
};

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
	char *name;
	char **aliases;
	short addrType;
	short length;
	unsigned char **addrList;
} HostEnt;

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

extern int SOCL_CreateSocket(struct SOCLSocketParam *param);
extern int SOCL_Bind(int s, unsigned short local_port);
extern int SOCL_Connect(int s, unsigned short remote_port, unsigned long remote_ip);
extern int SOCL_ReadFrom(int s, void *buffer, int buffer_len,
                         unsigned short *remote_port, unsigned long *remote_ip,
                         int flags);
extern int SOCL_ReadFrom(int s, void *buffer, int buffer_len, unsigned short *remote_port, unsigned long *remote_ip, int flags);
extern int SOCL_WriteTo(int s, void *buffer, int buffer_len,
                        unsigned short remote_port, unsigned long remote_ip,
                        int flags);
extern int func_0215E6B8(int s);
extern int SOCL_Close(int s);
extern unsigned long SOCL_Resolve(char *hostname);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int STD_CopyLString(char *destp, const char *srcp, int siz);
extern unsigned long SOCL_GetHostID(void);
extern int SOCL_SetResolver(unsigned long dns1, unsigned long dns2);
extern int SOCL_Startup(void *socl_config);
extern unsigned long SOCL_InetAtoH(char *hostname);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int OS_SNPrintf(char *dst, unsigned long len, char *fmt, ...);
extern int SOCL_GetStatus(int s);
extern void OS_Sleep(unsigned long msec);
extern int SOCL_Cleanup(void);
int SOC_Socket(int unused, int type);
int SOC_Bind(int s, void *sockAddr);
int SOC_Connect(int s, void * sockAddr);
int SOC_Recv(int s, void *buf, int len, int flags);
int SOC_RecvFrom(int a0, int a1, int a2, int a3, u8 *out);
int SOC_Send(int s, void *buf, int len, int flags);
int SOC_SendTo(int s, void * buf, int len, int flags, void * sockTo);
int SOC_Shutdown(int s, int how);
int SOC_Close(int s);
HostEnt *SOC_GetHostByName(const char *name);
int SOC_GetSockName(u8 *sock, u8 *sockAddr);
long SOC_GetHostID(void);
int SOC_SetResolver(unsigned long *dns1, unsigned long *dns2);
int SOC_Fcntl(Sock *s, int cmd, int flags);
int SOC_Startup(const SOCConfig *config);
int SOC_Cleanup(void);
char *SOC_InetNtoA(struct SOCInAddr in);
int SOC_InetAtoN(char *cp, unsigned long *inp);
char *SOC_InetNtoP(int af, void *src, char *dst, unsigned int len);
void SOC_U32to4U8(unsigned long adr_u32, unsigned char *adr_4u8);
int SOC_Poll(PollFD *fds, unsigned int nfds, long long timeout);
extern struct SOCLSocketParam SOCLSocketParamTCP;
extern struct SOCLSocketParam SOCLSocketParamUDP;
extern SOCStatics gSocStatics;
extern u32 g_021AA4BC_ip;
extern unsigned char *gSocHostAddrList[2];
extern HostEnt gSocHostEnt;
extern char gSocHostName[0x101];
extern SOCLConfig gSoclStartupConfig;
extern char _ZZ12SOC_InetNtoA9SOCInAddrE6buffer[16];
extern char gSoclIpv4Format[];





int SOC_Socket(int unused, int type)
{
    if (type == 1)
        return SOCL_CreateSocket(&SOCLSocketParamTCP);
    return SOCL_CreateSocket(&SOCLSocketParamUDP);
}





int SOC_Bind(int s, void *sockAddr)
{
    unsigned short port = *(unsigned short *)((char *)sockAddr + 2);

    return SOCL_Bind(s, (unsigned short)(((port >> 8) & 0xff)
                                       | ((port << 8) & 0xff00)));
}





int SOC_Connect(int s, void * sockAddr)
{
    struct SOCSockAddrIn * addr = (struct SOCSockAddrIn *)sockAddr;

    return SOCL_Connect(s, SWAP16(addr->port), SWAP32(addr->addr));
}





int SOC_Recv(int s, void *buf, int len, int flags)
{
    return SOCL_ReadFrom(s, buf, len, 0, 0, flags);
}





/*
 * Ask SOCL_ReadFrom for a two-word header into locals; on success and with a
 * non-null destination object, write the byte-swapped halfword to +2 and the
 * byte-swapped word to +4.  Returns the callee's result.
 */
int SOC_RecvFrom(int a0, int a1, int a2, int a3, u8 *out)
{
    u16 h;
    u32 w;
    int r;

    r = SOCL_ReadFrom(a0, (void *)a1, a2, &h, (long unsigned int *)(&w), a3);
    if (r < 0)
        return r;
    if (out == 0)
        return r;

    *(u16 *)(out + 2) = (u16)(((h >> 8) & 0xff) | ((h << 8) & 0xff00));
    *(u32 *)(out + 4) = ((w >> 24) & 0xff) | ((w >> 8) & 0xff00)
                      | ((w << 8) & 0xff0000) | ((w << 24) & 0xff000000);
    return r;
}




int SOC_Send(int s, void *buf, int len, int flags)
{
    return SOCL_WriteTo(s, buf, len, 0, 0, flags);
}




int SOC_SendTo(int s, void * buf, int len, int flags, void * sockTo)
{
    struct SOCSockAddrIn * addr = (struct SOCSockAddrIn *)sockTo;
    unsigned short port;
    unsigned long ip;

    if (sockTo != 0) {
        port = addr->port;
        ip = addr->addr;
        port = (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00));
        ip = ((ip >> 24) & 0xff) | ((ip >> 8) & 0xff00) | ((ip << 8) & 0xff0000)
           | ((ip << 24) & 0xff000000);
    } else {
        port = 0;
        ip = 0;
    }
    return SOCL_WriteTo(s, buf, len, port, ip, flags);
}



/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 *
 * This is SOC_Shutdown(s, how): SOCL_Shutdown reads only s, but every
 * caller sets how (mov r1, #2 in ov114 and ov125), so it stays.
 */
int SOC_Shutdown(int s, int how)
{
    return func_0215E6B8(s);
}



/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 */
int SOC_Close(int s)
{
    return SOCL_Close(s);
}




/*
 * sdk:      SOC_GetHostByName (libsoc.TWL.HYB.a(soc.o))
 */
HostEnt *SOC_GetHostByName(const char *name)
{
	unsigned long ipAddr;

	ipAddr = SOCL_Resolve((char *)name);
	if (ipAddr == 0) {
		return 0;
	}
	MI_CpuFill8(gSocHostName, 0, 0x101);
	STD_CopyLString(gSocHostName, name, 0x101);
	gSocStatics.hostent_name = gSocHostName;
	gSocStatics.hostent_aliases = 0;
	gSocStatics.hostent_addrType = 2;
	gSocStatics.hostent_length = 4;
	gSocStatics.hostent_addrList = gSocHostAddrList;
	gSocStatics.addrList[0] = (unsigned char *)&g_021AA4BC_ip;
	gSocStatics.addrList[1] = 0;
	gSocStatics.hostip = SWAP32(ipAddr);
	return &gSocHostEnt;
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
	return SOCL_SetResolver(SWAP32(*dns1), SWAP32(*dns2));
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




static void *AllocFunc_SOCL(u32 size)
{
    unsigned long *m;
    unsigned long msize = size + 4;

    m = (unsigned long *)gSocStatics.AllocFunc_SOC(0, msize);
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
    gSocStatics.FreeFunc_SOC(0, m, *m);
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
    gSocStatics.soclConfig.use_dhcp = (config->flag == 1);
    gSocStatics.soclConfig.my_ip = SWAP32(config->addr);
    gSocStatics.soclConfig.net_mask = SWAP32(config->netmask);
    gSocStatics.soclConfig.gateway_ip = SWAP32(config->router);
    gSocStatics.soclConfig.dns_ip0 = SWAP32(config->dns1);
    gSocStatics.soclConfig.dns_ip1 = SWAP32(config->dns2);
    gSocStatics.soclConfig.alloc = AllocFunc_SOCL;
    gSocStatics.soclConfig.free = FreeFunc_SOCL;
    gSocStatics.AllocFunc_SOC = config->alloc;
    gSocStatics.FreeFunc_SOC = config->free;
    gSocStatics.soclConfig.cmd_packet_max = 0x40;
    gSocStatics.soclConfig.mtu = config->mtu;
    gSocStatics.soclConfig.rwin = config->rwin;
    return SOCL_Startup(&gSoclStartupConfig);
}


/*
 * Tail call to SOCL_Cleanup; sits between SOC_Startup and SOC_InetNtoA in
 * soc.o, so it is SOC_Cleanup.
 */
int SOC_Cleanup(void)
{
    return SOCL_Cleanup();
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

	ipAddr = SOCL_InetAtoH(cp);
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
    OS_SNPrintf(dst, 16, gSoclIpv4Format, addr[3], addr[2], addr[1], addr[0]);
    return dst;
}



/*
 * Writes a word big-endian into four bytes.
 */
void SOC_U32to4U8(unsigned long adr_u32, unsigned char *adr_4u8)
{
    adr_4u8[0] = (unsigned char)(adr_u32 >> 24);
    adr_4u8[1] = (unsigned char)(adr_u32 >> 16);
    adr_4u8[2] = (unsigned char)(adr_u32 >> 8);
    adr_4u8[3] = (unsigned char)adr_u32;
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
			status = status_mask & SOCL_GetStatus(fp->fd);
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
		OS_Sleep(1);
		time -= 523;
	}
	return num_good;
}

/*
 * file:     gsavailable.c
 * unit:     yes
 * function: func_0217C690, func_0217C704, func_0217C750, func_0217C848, func_0217C900
 * address:  0x0217C690
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsavailable.o (get_sockaddrin, SendPacket, GSIStartAvailableCheckA,
 *           HandlePacket, GSIAvailableCheckThink)
 *
 * symbols:
 *   inet_addr  0x0217ED38  arm ov009
 *   SOC_GetHostByName  0x0215F650  arm ov009
 *   sendto  0x0217ECA4  arm  ov009
 *   current_time  0x0217F264  arm  ov009
 *   g_021ACF7C     0x021ACF7C  data
 *   func_021803BC  0x021803BC  arm ov009
 *   SocketStartUp  0x0217F25C  arm ov009
 *   OS_SPrintf  0x02084F40  arm
 *   func_0217C690  0x0217C690  arm ov009
 *   func_0217EB18  0x0217EB18  arm ov009
 *   strlen  0x0209477C  arm
 *   func_02092344  0x02092344  arm
 *   func_0217C704  0x0217C704  arm ov009
 *   gGsAvailabilityGameName     0x021ACEFC  data
 *   g_021ACF3C     0x021ACF3C  data
 *   g_021A36E8     0x021A36E8  data
 *   func_020923F0  0x020923F0  arm
 *   g_021A370C     0x021A370C  data
 *   func_0217EF50  0x0217EF50  arm  ov009
 *   func_0217EC60  0x0217EC60  arm  ov009
 *   func_0217C848  0x0217C848  arm  ov009
 *   closesocket  0x0217EB2C  arm  ov009
 *   gGsAvailabilityState     0x021ACEF8  data
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;

struct SOCSockAddrIn {
    u8  len;
    u8  family;
    u16 port;
    u32 addr;
};

struct SOCHostEnt {
    char *name;
    char **aliases;
    short addrType;
    short length;
    unsigned char **addrList;
};

typedef struct {
    int sock;
    struct SOCSockAddrIn address;
    char packet[64];
    int packetLen;
    unsigned int sendTime;
    int retryCount;
} AvailableCheck;

struct SOCSockAddr;

extern int inet_addr(int a);
extern struct SOCHostEnt *SOC_GetHostByName(char *name);
extern int sendto(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen);
extern unsigned int current_time(void);
extern int func_021803BC(char *dst, const char *src, unsigned int n);
extern void SocketStartUp(void);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern int func_0217C690(char *hostname, int port, struct SOCSockAddrIn *saddr);
extern int func_0217EB18(int pf, int type, int protocol);
extern int strlen(const u8 *s);
extern void *func_02092344(void *dst, const void *src, unsigned long n);
extern void func_0217C704(void);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern int func_0217EF50(int sock);
extern int func_0217EC60(int sock, char *buf, int len, int flags, void *addr, int *fromlen);
extern int func_0217C848(char *packet, int len, struct SOCSockAddrIn *address, int *disabledservices);
extern int closesocket(int sock);
extern char gGsAvailabilityGameName[];
extern char g_021ACF3C[];
extern char g_021A36E8[];
extern char g_021A370C[];
extern int gGsAvailabilityState;
extern AvailableCheck g_021ACF7C;

/*
 * sdk:      get_sockaddrin (gsavailable.o)
 */
int func_0217C690(char *hostname, int port, struct SOCSockAddrIn *saddr)
{
    struct SOCHostEnt *host;
    saddr->family = 2;
    saddr->port = (unsigned short)((((unsigned short)port >> 8) & 0xff) | (((unsigned short)port << 8) & 0xff00));
    saddr->addr = inet_addr((int)hostname);
    if (saddr->addr == 0xFFFFFFFF) {
        host = SOC_GetHostByName(hostname);
        if (host == 0) return 0;
        saddr->addr = *(unsigned long *)host->addrList[0];
    }
    return 1;
}

/*
 * sdk:      SendPacket (gsavailable.o)
 */
void func_0217C704(void)
{
    sendto(g_021ACF7C.sock, g_021ACF7C.packet, g_021ACF7C.packetLen, 0, (struct SOCSockAddr *)&g_021ACF7C.address, 8);
    g_021ACF7C.sendTime = current_time();
}

/*
 * sdk:      GSIStartAvailableCheckA (gsavailable.o)
 */
void func_0217C750(char *gamename)
{
    int len;
    int override;
    char *host;
    char hostname[64];
    func_021803BC(gGsAvailabilityGameName, gamename, 64);
    g_021ACF7C.sock = -1;
    SocketStartUp();
    override = g_021ACF3C[0];
    if (override == 0)
        OS_SPrintf(hostname, g_021A36E8, gamename);
    host = g_021ACF3C;
    if (override == 0)
        host = hostname;
    if (!func_0217C690(host, 27900, &g_021ACF7C.address))
        return;
    g_021ACF7C.sock = func_0217EB18(2, 2, 0);
    if (g_021ACF7C.sock == -1)
        return;
    g_021ACF7C.packet[0] = 9;
    len = strlen((const u8 *)gamename);
    func_02092344(g_021ACF7C.packet + 5, gamename, len + 1);
    g_021ACF7C.packetLen = len + 6;
    func_0217C704();
    g_021ACF7C.retryCount = 0;
}

/*
 * sdk:      HandlePacket (gsavailable.o)
 */
int func_0217C848(char *packet, int len, struct SOCSockAddrIn *address, int *disabledservices)
{
    int bitfield;
    if (len < 7)
        return 1;
    if (func_020923F0((const u8 *)(&address->addr), (const u8 *)&g_021ACF7C.address.addr, 4) != 0)
        return 1;
    if (address->port != g_021ACF7C.address.port)
        return 1;
    if (func_020923F0((const u8 *)packet, (const u8 *)g_021A370C, 3) != 0)
        return 1;
    bitfield = (packet[3] << 24) & 0xff000000;
    bitfield |= (packet[4] << 16) & 0xff0000;
    bitfield |= (packet[5] << 8) & 0xff00;
    bitfield |= (unsigned char)packet[6];
    *disabledservices = bitfield;
    return 0;
}

/*
 * sdk:      GSIAvailableCheckThink (libdwcgscommon.TWL.HYB.a(gsavailable.o))
 */
int func_0217C900(void)
{
    char packet[64];
    struct SOCSockAddrIn address;
    int len = sizeof(address);
    int rcode;
    int disabledservices;
    if (g_021ACF7C.sock == -1) {
        gGsAvailabilityState = 1;
        return 1;
    }
    if (func_0217EF50(g_021ACF7C.sock)) {
        rcode = func_0217EC60(g_021ACF7C.sock, packet, 64, 0, &address, &len);
        if (func_0217C848(packet, rcode, &address, &disabledservices) == 0) {
            closesocket(g_021ACF7C.sock);
            if (disabledservices & 1) {
                gGsAvailabilityState = 2;
                return 2;
            } else if (disabledservices & 2) {
                gGsAvailabilityState = 3;
                return 3;
            } else {
                gGsAvailabilityState = 1;
                return 1;
            }
        }
    }
    if (current_time() > g_021ACF7C.sendTime + 2000) {
        if (g_021ACF7C.retryCount == 1) {
            closesocket(g_021ACF7C.sock);
            gGsAvailabilityState = 1;
            return 1;
        }
        func_0217C704();
        g_021ACF7C.retryCount++;
    }
    return 0;
}

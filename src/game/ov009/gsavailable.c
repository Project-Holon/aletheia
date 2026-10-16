/*
 * file:     gsavailable.c
 * unit:     yes
 * function: get_sockaddrin, SendPacket, GSIStartAvailableCheckA, HandlePacket, GSIAvailableCheckThink
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
 *   gGsAvailableCheck     0x021ACF7C  data
 *   gsiSafeStrcpyA  0x021803BC  arm ov009
 *   SocketStartUp  0x0217F25C  arm ov009
 *   OS_SPrintf  0x02084F40  arm
 *   get_sockaddrin  0x0217C690  arm ov009
 *   socket  0x0217EB18  arm ov009
 *   strlen  0x0209477C  arm
 *   func_02092344  0x02092344  arm
 *   SendPacket  0x0217C704  arm ov009
 *   gGsAvailabilityGameName     0x021ACEFC  data
 *   gGsAvailableOverrideHost     0x021ACF3C  data
 *   gGsAvailableHostFmt     0x021A36E8  data
 *   func_020923F0  0x020923F0  arm
 *   gGsAvailableMagic     0x021A370C  data
 *   CanReceiveOnSocket  0x0217EF50  arm  ov009
 *   func_0217EC60  0x0217EC60  arm  ov009
 *   HandlePacket  0x0217C848  arm  ov009
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
extern int gsiSafeStrcpyA(char *dst, const char *src, unsigned int n);
extern void SocketStartUp(void);
extern int OS_SPrintf(char *dst, char *fmt, ...);
static int get_sockaddrin(char *hostname, int port, struct SOCSockAddrIn *saddr);
extern int socket(int pf, int type, int protocol);
extern int strlen(const u8 *s);
extern void *func_02092344(void *dst, const void *src, unsigned long n);
static void SendPacket(void);
extern int func_020923F0(const u8 *a, const u8 *b, int n);
extern int CanReceiveOnSocket(int sock);
extern int func_0217EC60(int sock, char *buf, int len, int flags, void *addr, int *fromlen);
extern int HandlePacket(char *packet, int len, struct SOCSockAddrIn *address, int *disabledservices);
extern int closesocket(int sock);
extern char gGsAvailabilityGameName[];
extern char gGsAvailableOverrideHost[];
extern char gGsAvailableHostFmt[];
extern char gGsAvailableMagic[];
extern int gGsAvailabilityState;
extern AvailableCheck gGsAvailableCheck;

/*
 * sdk:      get_sockaddrin (gsavailable.o)
 */
static int get_sockaddrin(char *hostname, int port, struct SOCSockAddrIn *saddr)
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
static void SendPacket(void)
{
    sendto(gGsAvailableCheck.sock, gGsAvailableCheck.packet, gGsAvailableCheck.packetLen, 0, (struct SOCSockAddr *)&gGsAvailableCheck.address, 8);
    gGsAvailableCheck.sendTime = current_time();
}

/*
 * sdk:      GSIStartAvailableCheckA (gsavailable.o)
 */
void GSIStartAvailableCheckA(char *gamename)
{
    int len;
    int override;
    char *host;
    char hostname[64];
    gsiSafeStrcpyA(gGsAvailabilityGameName, gamename, 64);
    gGsAvailableCheck.sock = -1;
    SocketStartUp();
    override = gGsAvailableOverrideHost[0];
    if (override == 0)
        OS_SPrintf(hostname, gGsAvailableHostFmt, gamename);
    host = gGsAvailableOverrideHost;
    if (override == 0)
        host = hostname;
    if (!get_sockaddrin(host, 27900, &gGsAvailableCheck.address))
        return;
    gGsAvailableCheck.sock = socket(2, 2, 0);
    if (gGsAvailableCheck.sock == -1)
        return;
    gGsAvailableCheck.packet[0] = 9;
    len = strlen((const u8 *)gamename);
    func_02092344(gGsAvailableCheck.packet + 5, gamename, len + 1);
    gGsAvailableCheck.packetLen = len + 6;
    SendPacket();
    gGsAvailableCheck.retryCount = 0;
}

/*
 * sdk:      HandlePacket (gsavailable.o)
 */
int HandlePacket(char *packet, int len, struct SOCSockAddrIn *address, int *disabledservices)
{
    int bitfield;
    if (len < 7)
        return 1;
    if (func_020923F0((const u8 *)(&address->addr), (const u8 *)&gGsAvailableCheck.address.addr, 4) != 0)
        return 1;
    if (address->port != gGsAvailableCheck.address.port)
        return 1;
    if (func_020923F0((const u8 *)packet, (const u8 *)gGsAvailableMagic, 3) != 0)
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
int GSIAvailableCheckThink(void)
{
    char packet[64];
    struct SOCSockAddrIn address;
    int len = sizeof(address);
    int rcode;
    int disabledservices;
    if (gGsAvailableCheck.sock == -1) {
        gGsAvailabilityState = 1;
        return 1;
    }
    if (CanReceiveOnSocket(gGsAvailableCheck.sock)) {
        rcode = func_0217EC60(gGsAvailableCheck.sock, packet, 64, 0, &address, &len);
        if (HandlePacket(packet, rcode, &address, &disabledservices) == 0) {
            closesocket(gGsAvailableCheck.sock);
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
    if (current_time() > gGsAvailableCheck.sendTime + 2000) {
        if (gGsAvailableCheck.retryCount == 1) {
            closesocket(gGsAvailableCheck.sock);
            gGsAvailabilityState = 1;
            return 1;
        }
        SendPacket();
        gGsAvailableCheck.retryCount++;
    }
    return 0;
}

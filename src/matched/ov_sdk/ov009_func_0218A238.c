/*
 * function: func_0218A238
 * address:  0x0218A238
 * packet:   pkt_ov009_0218A238
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiStartConnect (gpiconnect.o)
 *
 * symbols:
 *   func_02094860  0x02094860  arm
 *   func_02180E48  0x02180E48  arm   ov009
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_02180E58  0x02180E58  arm   ov009
 *   func_02193710  0x02193710  arm   ov009
 *   func_02189D78  0x02189D78  arm   ov009
 *   func_0218158C  0x0218158C  arm   ov009
 *   func_021815C8  0x021815C8  arm   ov009
 *   func_0217EB18  0x0217EB18  arm   ov009
 *   func_0217EE50  0x0217EE50  arm   ov009
 *   func_0217ED38  0x0217ED38  arm   ov009
 *   SOC_GetHostByName  0x0215F650  arm   ov009
 *   func_0217EC08  0x0217EC08  arm   ov009
 *   func_0217ED54  0x0217ED54  arm   ov009
 *   func_0218F5F4  0x0218F5F4  arm   ov009
 *   func_0218F880  0x0218F880  arm   ov009
 *   func_0218F65C  0x0218F65C  arm   ov009
 *   func_0218F7B8  0x0218F7B8  arm   ov009
 *   g_021A4658     0x021A4658  data
 *   g_021A4664     0x021A4664  data
 *   g_021A467C     0x021A467C  data
 *   g_021A46A0     0x021A46A0  data
 *   g_021A46D4     0x021A46D4  data
 *   g_021A46FC     0x021A46FC  data
 *   g_021A4734     0x021A4734  data
 *   g_021A4760     0x021A4760  data
 *   g_021A4788     0x021A4788  data
 *   g_021A45D8     0x021A45D8  data
 *   g_021A47BC     0x021A47BC  data
 *   g_021A47F0     0x021A47F0  data
 *
 * gpiPeerPingReplyCallback (func_0218F880) is its own 4-byte function since
 * 2026-09-29 (w4_nm: seeded start, catalog row, EXACT stub).
 * The port-retry loop sits under its own if (anError != 0): the object tests
 * the first gsUdpEngineInitialize result once and skips both the loop and the
 * failure test on success. The SOCSockAddrIn is zeroed with two word stores
 * through a pointer to the local (w2 ghiDoConnecting spelling).
 */

typedef struct GPIOperation_s {
    int type;
    void *data;
    int blocking;
    void *callback;
    void *param;
    int state;
    int id;
    int result;
    struct GPIOperation_s *pnext;
} GPIOperation;

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
} SOCSockAddrIn;

typedef struct SOCHostEnt {
    char *name;
    char **aliases;
    short addrType;
    short length;
    unsigned char **addrList;
} SOCHostEnt;

typedef struct GPIConnection {
    char pad0[0x10c];
    int firewall;
    char pad110[0x1f0 - 0x110];
    int cmSocket;
    int connectState;
    char pad1f8[0x220 - 0x1f8];
    char mHeader[16];
    unsigned short peerPort;
} GPIConnection;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 *func_02094860(u8 *dest, const u8 *src, u32 n);
extern int func_02180E48(void);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_02180E58(unsigned short thePort, int theIncomingBufSize, int theOutgoingBufSize, void (*theAppNetworkError)(int, void *), void (*theAppConnected)(unsigned int, unsigned short, int, int, void *), void (*theAppClosed)(unsigned int, unsigned short, int, void *), void (*theAppPing)(unsigned int, unsigned short, unsigned int, void *), void (*theAppReceive)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *), int (*theAppUnownMsg)(unsigned int, unsigned short, unsigned char *, unsigned int, void *), void (*theAppConnectAttempt)(unsigned int, unsigned short, int, unsigned char *, unsigned int, void *), void *theAppUserData);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern unsigned short func_0218158C(void);
extern int func_021815C8(char *theInitMsg, char *theHeader, void (*theMsgHandlerError)(int, void *), void (*theMsgHandlerConnected)(unsigned int, unsigned short, int, int, void *), void (*theMsgHandlerClosed)(unsigned int, unsigned short, int, void *), void (*theMsgHandlerPing)(unsigned int, unsigned short, unsigned int, void *), void (*theMsgHandlerRecv)(unsigned int, unsigned short, unsigned char *, unsigned int, int, void *), void *theUserData);
extern int func_0217EB18(int pf, int type, int protocol);
extern int func_0217EE50(int sock, int isblocking);
extern int func_0217ED38(int a);
extern SOCHostEnt *SOC_GetHostByName(char *name);
extern int func_0217EC08(int sock, void *addr, int len);
extern int func_0217ED54(int sock);
extern void func_0218F5F4(void);
extern void func_0218F880(void);
extern void func_0218F65C(unsigned int ip, unsigned short port, unsigned char *message, int messageLength, int unused, void *userData);
extern void func_0218F7B8(unsigned int ip, unsigned short port, int unused, int rejected, void *userData);
extern char g_021A4658[];
extern char g_021A4664[];
extern char g_021A467C[];
extern char g_021A46A0[];
extern char g_021A46D4[];
extern char g_021A46FC[];
extern char g_021A4734[];
extern char g_021A4760[];
extern char g_021A4788[];
extern char g_021A45D8[];
extern char g_021A47BC[];
extern char g_021A47F0[];

int func_0218A238(void **connection, GPIOperation *operation)
{
    SOCSockAddrIn address;
    int rcode;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    SOCHostEnt *host;
    int anError;
    unsigned short peerPort;
    int error;

    func_02094860((u8 *)iconnection->mHeader, (const u8 *)g_021A4658, 16);

    if (!func_02180E48()) {
        peerPort = 6500;
        func_0217D254(1, 0, 8, g_021A4664);
        anError = func_02180E58(peerPort, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        if (anError != 0) {
            while (anError != 0 && peerPort < 6500 + 100) {
                func_0217D254(1, 0, 16, g_021A467C, peerPort);
                peerPort++;
                anError = func_02180E58(peerPort, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            }
            if (anError != 0) {
                func_0217D254(1, 0, 1, g_021A46A0);
                func_02193710((int *)connection, 8, (int)g_021A46D4);
                func_02189D78((int *)connection, 3, 1);
                return 3;
            }
        }
        if (iconnection->firewall == 0)
            iconnection->peerPort = peerPort;
    } else {
        func_0217D254(1, 0, 8, g_021A46FC);
        iconnection->peerPort = func_0218158C();
    }

    anError = func_021815C8(iconnection->mHeader, iconnection->mHeader, 0,
                            (void *)func_0218F7B8, (void *)func_0218F5F4,
                            (void *)func_0218F880, (void *)func_0218F65C, connection);
    if (anError != 0) {
        func_02193710((int *)connection, 8, (int)g_021A4734);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }

    if (iconnection->firewall)
        iconnection->peerPort = 0;

    iconnection->cmSocket = func_0217EB18(2, 1, 0);
    if (iconnection->cmSocket == -1) {
        func_02193710((int *)connection, 5, (int)g_021A4760);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }

    rcode = func_0217EE50(iconnection->cmSocket, 0);
    if (!rcode) {
        func_02193710((int *)connection, 5, (int)g_021A4788);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }

    {
        unsigned int *p = (unsigned int *)&address;
        p[0] = 0;
        p[1] = 0;
    }
    address.family = 2;
    if (func_0217ED38((int)g_021A45D8) == 0xFFFFFFFF) {
        host = SOC_GetHostByName(g_021A45D8);
        if (host == 0) {
            func_02193710((int *)connection, 5, (int)g_021A47BC);
            func_02189D78((int *)connection, 3, 1);
            return 3;
        }
        address.addr = *(unsigned int *)host->addrList[0];
    } else {
        address.addr = func_0217ED38((int)g_021A45D8);
    }
    address.port = 0xcc74;

    rcode = func_0217EC08(iconnection->cmSocket, &address, sizeof(address));
    if (rcode == -1) {
        error = func_0217ED54(iconnection->cmSocket);
        if (error != -6 && error != -26 && error != -76) {
            func_02193710((int *)connection, 5, (int)g_021A47F0);
            func_02189D78((int *)connection, 3, 1);
            return 3;
        }
    }

    operation->state = 1;
    iconnection->connectState = 1;
    return 0;
}

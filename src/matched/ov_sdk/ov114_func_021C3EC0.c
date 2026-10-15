/*
 * function: ghiDoConnecting
 * address:  0x021C3EC0
 * packet:   pkt_ov114_021C3EC0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoConnecting (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0217EB18  0x0217EB18  arm  ov009
 *   GOAGetLastError  0x0217ED54  arm  ov009
 *   SetSockBlocking  0x0217EE50  arm  ov009
 *   func_0217EF00  0x0217EF00  arm  ov009
 *   func_0217EC08  0x0217EC08  arm  ov009
 *   GSISocketSelect  0x0217ED64  arm  ov009
 *   ghiCallProgressCallback  0x021C02C8  arm  ov114
 *   sGhttpConnecting     0x021CF12C  data
 *   gGhttpThrottleBufferSize     0x021CE5B0  data
 *   gGhttpProxyServer     0x021D3B2C  data
 *   gGhttpProxyPort     0x021D3B28  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define SOC_HTONS(x) ((u16)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))

typedef struct {
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
} SOCSockAddrIn;

typedef struct GHIConnection GHIConnection;

typedef struct GHIEncryptor {
    int pad00;
    int engine;                 /* 0x04 */
    char pad08[0x20];
    int (*initFunc)(GHIConnection *connection, struct GHIEncryptor *encryptor); /* 0x28 */
} GHIEncryptor;

struct GHIConnection {
    char pad000[0x10];
    int state;                  /* 0x010 */
    char pad014[0x08];
    u32 serverIP;               /* 0x01C */
    u16 serverPort;             /* 0x020 */
    char pad022[0x1E];
    int result;                 /* 0x040 */
    char pad044[0x0C];
    int socket;                 /* 0x050 */
    int socketError;            /* 0x054 */
    char pad058[0xCC];
    int completed;              /* 0x124 */
    char pad128[0x34];
    int throttle;               /* 0x15C */
    char pad160[0x2C];
    char *proxyOverrideServer;  /* 0x18C */
    u16 proxyOverridePort;      /* 0x190 */
    char pad192[0x02];
    GHIEncryptor encryptor;     /* 0x194 */
};

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_0217EB18(int pf, int type, int protocol);
extern int GOAGetLastError(int socket);
extern int SetSockBlocking(int sock, int isblocking);
extern int func_0217EF00(int sock, int size);
extern int func_0217EC08(int sock, void *addr, int len);
extern int GSISocketSelect(int theSocket, int *theReadFlag, int *theWriteFlag, int *theExceptFlag);
extern void ghiCallProgressCallback(struct GHIConnection *connection, char *buffer, int bufferLen);
extern char sGhttpConnecting[];
extern int gGhttpThrottleBufferSize;
extern char *gGhttpProxyServer;
extern u16 gGhttpProxyPort;

void ghiDoConnecting(GHIConnection *connection)
{
    int rcode;
    int socketError;
    SOCSockAddrIn address;
    int writeFlag;
    int exceptFlag;

    func_0217D254(8, (char *)3, 0x10, sGhttpConnecting);

    if (connection->socket == -1)
    {
        connection->socket = func_0217EB18(2, 1, 0);
        if (connection->socket == -1)
        {
            connection->completed = 1;
            connection->result = 5;
            connection->socketError = GOAGetLastError(connection->socket);
            return;
        }
        if (!SetSockBlocking(connection->socket, 0))
        {
            connection->completed = 1;
            connection->result = 5;
            connection->socketError = GOAGetLastError(connection->socket);
            return;
        }
        if (connection->throttle)
            func_0217EF00(connection->socket, gGhttpThrottleBufferSize);

        if (connection->encryptor.engine == 4)
        {
            if (connection->encryptor.initFunc(connection, &connection->encryptor) == 3)
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
            connection->encryptor.engine = 0;
        }

        {
            u32 *p = (u32 *)&address;
            p[0] = 0;
            p[1] = 0;
        }
        address.family = 2;
        if (connection->proxyOverrideServer)
            address.port = SOC_HTONS(connection->proxyOverridePort);
        else if (gGhttpProxyServer)
            address.port = SOC_HTONS(gGhttpProxyPort);
        else
            address.port = SOC_HTONS(connection->serverPort);
        address.addr = connection->serverIP;

        rcode = func_0217EC08(connection->socket, &address, sizeof(address));
        if (rcode == -1)
        {
            socketError = GOAGetLastError(connection->socket);
            if (socketError != -6 && socketError != -26 && socketError != -76)
            {
                connection->completed = 1;
                connection->result = 6;
                connection->socketError = socketError;
                return;
            }
        }
    }

    rcode = GSISocketSelect(connection->socket, 0, &writeFlag, &exceptFlag);
    if (rcode == -1 || (rcode == 1 && exceptFlag))
    {
        connection->completed = 1;
        connection->result = 6;
        if (rcode == -1)
            connection->socketError = GOAGetLastError(connection->socket);
        else
            connection->socketError = 0;
        return;
    }

    if (rcode == 1 && writeFlag)
    {
        if (connection->encryptor.engine == 0)
            connection->state = 5;
        else
            connection->state = 4;
        ghiCallProgressCallback(connection, 0, 0);
    }
}

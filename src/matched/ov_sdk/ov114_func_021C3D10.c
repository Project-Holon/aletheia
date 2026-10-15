/*
 * function: ghiDoHostLookup
 * address:  0x021C3D10
 * packet:   pkt_ov114_021C3D10
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoHostLookup (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   gsDebugFormat  0x0217D254  arm   ov009
 *   inet_addr  0x0217ED38  arm   ov009
 *   gsiStartResolvingHostname  0x0217F150  arm   ov009
 *   ghiCallProgressCallback  0x021C02C8  arm   ov114
 *   sGhttpHostLookup     0x021CF0D0  data  ov114
 *   sGhttpThreadCreationFailed     0x021CF0E0  data  ov114
 *   gGhttpProxyServer     0x021D3B2C  data  ov114
 */

typedef struct GHIConnection {
    unsigned char pad0[0x10];
    int f10;
    int f14;
    char *f18;
    unsigned int f1C;
    unsigned char pad1[0x40 - 0x20];
    int f40;
    unsigned char pad2[0x124 - 0x44];
    int f124;
    unsigned char pad3[0x18C - 0x128];
    char *f18C;
    unsigned char pad4[0x1CC - 0x190];
    void *f1CC;
} GHIConnection;

extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern int inet_addr(int a);
struct GSIResolveHostnameInfo;
extern int gsiStartResolvingHostname(char *hostname, struct GSIResolveHostnameInfo **handle);
extern void ghiCallProgressCallback(GHIConnection *, char *, int);
extern char sGhttpHostLookup[];
extern char sGhttpThreadCreationFailed[];
extern char *gGhttpProxyServer;

void ghiDoHostLookup(GHIConnection *connection)
{
    char *server;

    if (connection->f1CC != 0) {
        connection->f10 = 2;
        ghiCallProgressCallback(connection, 0, 0);
        return;
    }
    gsDebugFormat(8, (char *)3, 16, sGhttpHostLookup);
    server = connection->f18C;
    if (server == 0) {
        server = gGhttpProxyServer;
        if (server == 0)
            server = connection->f18;
    }
    connection->f1C = inet_addr((int)server);
    if (connection->f1C == (unsigned int)-1) {
        if (gsiStartResolvingHostname(server, (struct GSIResolveHostnameInfo **)(&connection->f1CC)) == -1) {
            gsDebugFormat(8, (char *)3, 1, sGhttpThreadCreationFailed);
            connection->f1CC = 0;
            connection->f124 = 1;
            connection->f40 = 4;
            return;
        }
    }
    if (connection->f1C == (unsigned int)-1) {
        connection->f10 = 2;
        ghiCallProgressCallback(connection, 0, 0);
        return;
    }
    connection->f10 = 3;
    ghiCallProgressCallback(connection, 0, 0);
}

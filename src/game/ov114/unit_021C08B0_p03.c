/*
 * file:     unit_021C08B0_p03.c
 * unit:     yes
 * function: func_021C0E58, func_021C0FB0, func_021C1020
 * address:  0x021C0E58
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217D254  0x0217d254  arm   ov009
 *   func_0217F1C0  0x0217f1c0  arm   ov009
 *   func_0217EB9C  0x0217eb9c  arm   ov009
 *   func_0217EB40  0x0217eb40  arm   ov009
 *   func_0217EAE0  0x0217eae0  arm   ov009
 *   func_021C00FC  0x021c00fc  arm   ov114
 *   func_020949F4  0x020949f4  arm
 *   g_021CE648     0x021ce648  data  ov114
 *   g_021CE620     0x021ce620  data  ov114
 *   g_021CE660     0x021ce660  data
 *   ghiEnumConnections      0x021C0DF8  arm
 *   gsifree                 0x0217EAE0  arm
 *   ghiFreeConnection       0x021C0D40  arm
 *   ghiConnectionsLen       0x021D3B30  data
 *   strncmp                 0x020949F4  arm
 *   strcspn                 0x02094A60  arm
 *   goastrdup               0x0217F1E0  arm
 *   g_021CE66C              0x021CE66C  data
 *   g_021CE674              0x021CE674  data
 */
struct GHIConnection_021C0E58;
typedef void (*GHICleanupFunc)(struct GHIConnection_021C0E58 *, void *);

typedef struct GHIBuffer {
    struct GHIConnection_021C0E58 *connection;
    char *data;
    int size;
    int len;
    int pos;
    int sizeIncrement;
    int fixed;
    int dontFree;
    int readOnly;
} GHIBuffer;

typedef struct GHIConnection_021C0E58 {
    char pad0[0x10];
    int f10;
    char *f14;
    char *f18;
    int f1c;
    unsigned short f20;
    char pad1[2];
    char *f24;
    char pad2[0x50 - 0x28];
    int f50;
    char pad3[0x58 - 0x54];
    GHIBuffer buf58;
    GHIBuffer buf7c;
    GHIBuffer bufa0;
    GHIBuffer bufc4;
    char pad4[0x110 - 0xe8];
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    char pad5[0x130 - 0x124];
    char *f130;
    int f134;
    char pad6[0x158 - 0x138];
    int f158;
    char pad7[0x194 - 0x15c];
    int f194;
    int f198;
    int f19c;
    char pad8[0x1b8 - 0x1a0];
    GHICleanupFunc f1b8;
    char pad9[0x1c8 - 0x1bc];
    int f1c8;
    void *f1cc;
} GHIConnection_021C0E58;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef struct GHIConnection_021C0FB0 {
    int inUse;
    int index;
} GHIConnection_021C0FB0;

typedef struct {
    int length;
    int numConnections;
    int nextUniqueID;
    GHIConnection_021C0FB0 **connections;
} GHIGlobals;

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0217F1C0(void *);
extern int func_0217EB9C(int, int);
extern int func_0217EB40(int, int *);
extern void func_0217EAE0(void *);
extern void func_021C00FC(GHIBuffer *);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern void ghiEnumConnections(int (*callback)(GHIConnection_021C0FB0 *));
extern void gsifree(void *ptr);
extern int ghiFreeConnection(GHIConnection_021C0FB0 *connection);
extern int strncmp(const char *s1, const char *s2, unsigned int n);
extern int strcspn(const char *s1, const char *s2);
extern char *goastrdup(char *src);
void func_021C0E58(GHIConnection_021C0E58 *connection);
void ghiCleanupConnections(void);
char *ghiGetServerAddressFromUrl(char *serverUrl);
extern char g_021CE648[];
extern char g_021CE620[];
extern char g_021CE660[];
extern GHIGlobals ghiConnectionsLen;
extern char g_021CE66C[];
extern char g_021CE674[];


/*
 * sdk:      ghiRedirectConnection (libdwcgsghttp.TWL.HYB.a ghttpconnection.o)
 */
void func_021C0E58(GHIConnection_021C0E58 *connection)
{
    func_0217D254(8, (char *)3, 0x10, g_021CE648);
    if (connection->f1cc != 0) {
        func_0217D254(8, (char *)3, 0x10, g_021CE620);
        func_0217F1C0(connection->f1cc);
        connection->f1cc = 0;
    }
    func_0217EB9C(connection->f50, 2);
    if (func_0217EB40(connection->f50, &connection->f1c8) == 0)
        return;
    func_0217EAE0(connection->f14);
    connection->f14 = connection->f130;
    connection->f130 = 0;
    func_0217EAE0(connection->f18);
    connection->f18 = 0;
    connection->f1c = 0;
    connection->f20 = 0;
    func_0217EAE0(connection->f24);
    connection->f24 = 0;
    connection->f10 = 0;
    connection->f50 = -1;
    func_021C00FC(&connection->buf58);
    func_021C00FC(&connection->buf7c);
    func_021C00FC(&connection->bufa0);
    func_021C00FC(&connection->bufc4);
    connection->f110 = 0;
    connection->f114 = 0;
    connection->f118 = 0;
    connection->f11c = 0;
    connection->f120 = 0;
    connection->f158 = 0;
    if (connection->f19c != 0) {
        if (connection->f1b8 != 0)
            connection->f1b8(connection, &connection->f194);
        connection->f19c = 0;
        if (func_020949F4((const u8 *)g_021CE660, (const u8 *)connection->f14, 8) != 0) {
            connection->f198 = 0;
            connection->f194 = 0;
        }
    }
    connection->f134++;
}


void ghiCleanupConnections(void)
{
    int i;

    if (ghiConnectionsLen.connections == 0)
        return;
    ghiEnumConnections(ghiFreeConnection);
    for (i = 0; i < ghiConnectionsLen.length; i++)
        gsifree(ghiConnectionsLen.connections[i]);
    gsifree(ghiConnectionsLen.connections);
    ghiConnectionsLen.connections = 0;
    ghiConnectionsLen.length = 0;
    ghiConnectionsLen.numConnections = 0;
}


char *ghiGetServerAddressFromUrl(char *serverUrl)
{
    int nIndex;
    char *url;
    char tempChar;
    char *serverAddress;

    if (strncmp(serverUrl, g_021CE66C, 7) == 0)
        url = serverUrl + 7;
    else if (strncmp(serverUrl, g_021CE660, 8) == 0)
        url = serverUrl + 8;
    else
        return 0;

    nIndex = strcspn(url, g_021CE674);
    tempChar = url[nIndex];
    url[nIndex] = 0;
    serverAddress = goastrdup(url);
    url[nIndex] = tempChar;
    return serverAddress;
}

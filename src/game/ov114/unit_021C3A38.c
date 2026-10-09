/*
 * file:     unit_021C3A38.c
 * unit:     yes
 * function: func_021C3A38, func_021C3BAC, func_021C3D10, func_021C3E10, func_021C3EC0, func_021C4150, func_021C4384, func_021C4684, func_021C4764, func_021C4830, func_021C492C, func_021C4B18, func_021C4BD8, func_021C4C00, func_021C4C50, func_021C4E68, func_021C4E7C, func_021C5430
 * address:  0x021C3A38
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020949F4  0x020949F4  arm
 *   func_02094A60  0x02094A60  arm
 *   func_02094A28  0x02094A28  arm
 *   func_020964E0  0x020964E0  arm
 *   func_0217F1E0  0x0217F1E0  arm   ov009
 *   g_021CEFDC     0x021CEFDC  data
 *   g_021CEFE4     0x021CEFE4  data
 *   g_021CEFF0     0x021CEFF0  data
 *   g_021CEFF4     0x021CEFF4  data
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_021C02C8  0x021C02C8  arm   ov114
 *   func_0217F25C  0x0217F25C  arm   ov009
 *   func_021C109C  0x021C109C  arm   ov114
 *   g_021CEFF8     0x021CEFF8  data
 *   g_021CF010     0x021CF010  data
 *   g_021CF050     0x021CF050  data
 *   g_021CF090     0x021CF090  data
 *   g_021CF0AC     0x021CF0AC  data
 *   func_0217ED38  0x0217ED38  arm   ov009
 *   func_0217F150  0x0217F150  arm   ov009
 *   g_021CF0D0     0x021CF0D0  data  ov114
 *   g_021CF0E0     0x021CF0E0  data  ov114
 *   g_021D3B2C     0x021D3B2C  data  ov114
 *   func_0217F1CC  0x0217F1CC  arm   ov009
 *   g_021CF0F8     0x021CF0F8  data  ov114
 *   g_021CF114     0x021CF114  data  ov114
 *   func_0217EB18  0x0217EB18  arm  ov009
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   func_0217EE50  0x0217EE50  arm  ov009
 *   func_0217EF00  0x0217EF00  arm  ov009
 *   func_0217EC08  0x0217EC08  arm  ov009
 *   func_0217ED64  0x0217ED64  arm  ov009
 *   g_021CF12C     0x021CF12C  data
 *   g_021CE5B0     0x021CE5B0  data
 *   g_021D3B28     0x021D3B28  data
 *   func_021C011C  0x021C011C  arm  ov114
 *   func_021C00FC  0x021C00FC  arm  ov114
 *   func_021C04D4  0x021C04D4  arm  ov114
 *   func_021BFCEC  0x021BFCEC  arm  ov114
 *   func_021C0378  0x021C0378  arm  ov114
 *   g_021CF138     0x021CF138  data
 *   func_021BFF7C  0x021BFF7C  arm  ov114
 *   func_021C0004  0x021C0004  arm  ov114
 *   func_021C00C0  0x021C00C0  arm  ov114
 *   func_02094B20  0x02094B20  arm
 *   func_02084F40  0x02084F40  arm
 *   func_021C25C8  0x021C25C8  arm  ov114
 *   func_021BFDEC  0x021BFDEC  arm  ov114
 *   g_021CF14C     0x021CF14C  data
 *   g_021CF160     0x021CF160  data
 *   g_021CF168     0x021CF168  data
 *   g_021CF170     0x021CF170  data
 *   g_021CF178     0x021CF178  data
 *   g_021CF184     0x021CF184  data
 *   g_021CF18C     0x021CF18C  data
 *   g_021CF194     0x021CF194  data
 *   g_021CF198     0x021CF198  data
 *   g_021CF1A4     0x021CF1A4  data
 *   g_021CF1B4     0x021CF1B4  data
 *   g_021CF1C0     0x021CF1C0  data
 *   g_021CF1CC     0x021CF1CC  data
 *   g_021CF1D4     0x021CF1D4  data
 *   g_021CF1D8     0x021CF1D8  data
 *   g_021CF1E8     0x021CF1E8  data
 *   func_021C3834  0x021C3834  arm   ov114
 *   func_021C2BB0  0x021C2BB0  arm   ov114
 *   func_021C0318  0x021C0318  arm   ov114
 *   g_021CF1F8     0x021CF1F8  data  ov114
 *   g_021CF204     0x021CF204  data  ov114
 *   STD_TSScanf  0x0208CF34  arm
 *   g_021CF210   0x021CF210  data
 *   g_020A61DC   0x020A61DC  data
 *   g_021CF220     0x021CF220  data
 *   g_021CF234     0x021CF234  data
 *   g_021CF248   0x021CF248  data
 *   memcpy  0x02092344  arm
 *   g_021CF24C     0x021CF24C  data
 *   g_021CF25C     0x021CF25C  data
 *   g_021CF274     0x021CF274  data
 *   g_021CF28C     0x021CF28C  data
 *   g_021CF2A0     0x021CF2A0  data
 *   gsimalloc                       0x0217eab0 arm
 *   ghiDoReceive                    0x021c04d4 arm  ov114
 *   ghiFreeTempBuffer               0x021c4e68 arm  ov114
 *   ghiAppendDataToBuffer           0x021bfcec arm  ov114
 *   ghiDecryptReceivedData          0x021c0378 arm  ov114
 *   strncmp                         0x020949f4 arm
 *   strstr                          0x02094b20 arm
 *   memmove                         0x02092364 arm
 *   ghiResetBuffer                  0x021c00fc arm  ov114
 *   ghiCallProgressCallback         0x021c02c8 arm  ov114
 *   strlen                          0x0209477c arm
 *   OS_SPrintf                      0x02084f40 arm
 *   goastrdup                       0x0217f1e0 arm
 *   atoi                            0x020964e0 arm
 *   ghiProcessIncomingFileData      0x021c4c50 arm  ov114
 *   GOAGetLastError                 0x0217ed54 arm
 *   g_021CF2BC                      0x021cf2bc data
 *   g_021CF2C0                      0x021cf2c0 data
 *   g_021CF2C8                      0x021cf2c8 data
 *   __ctype_mapC                    0x020a61dc data a2
 *   g_021CF2D4                      0x021cf2d4 data
 *   g_021CF2E4                      0x021cf2e4 data
 *   g_021CE0B8                      0x021ce0b8 data
 *   g_021CF2F4                      0x021cf2f4 data
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   g_021CF310     0x021CF310  data
 *   g_021CF320     0x021CF320  data
 *   @13998                          0x021ce0b8 data
 */
#include "ghttp_types.h"

#define SOC_HTONS(x) ((u16)((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00)))
#define ISSPACE(c) (((unsigned)(c) < 0x80u) ? (__ctype_mapC[c] & 0x100) : 0)
#define ISSPACE2(c) (((unsigned)(c) < 0x80u) ? (__ctype_mapC[c] & 0x100) : 0)
struct GSIResolveHostnameInfo;
struct Conn;
struct Ctx;
typedef enum { GHI_FALSE, GHI_TRUE } GHIBool;

typedef struct {
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
} SOCSockAddrIn;

extern int func_020949F4(const unsigned char *s1, const unsigned char *s2, unsigned int n);
extern int func_02094A60(const u8 *s, const u8 *reject);
extern char *func_02094A28(const char *, int);
extern int func_020964E0(u32 a0);
extern char *func_0217F1E0(char *);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_021C02C8(GHIConnection *, char *, int);
extern void func_0217F25C();
extern int func_021C109C(int, int);
extern int func_0217ED38(int a);
extern int func_0217F150(char *hostname, struct GSIResolveHostnameInfo **handle);
extern int func_0217F1CC(int *p);
extern int func_0217EB18(int pf, int type, int protocol);
extern int func_0217ED54(int socket);
extern int func_0217EE50(int sock, int isblocking);
extern int func_0217EF00(int sock, int size);
extern int func_0217EC08(int sock, void *addr, int len);
extern int func_0217ED64(int theSocket, int *theReadFlag, int *theWriteFlag, int *theExceptFlag);
extern int func_021C011C(struct GHIConnection *connection);
extern void func_021C00FC(GHIBuffer *buffer);
extern int func_021C04D4(struct GHIConnection *connection, char *buffer, int *bufferLen);
extern int func_021BFCEC(struct GHIBuffer *buffer, char *data, int dataLen);
extern int func_021C0378(struct GHIConnection *connection);
extern int func_021BFF7C(GHIBuffer *buffer, const char *name, const char *value);
extern int func_021C0004(struct Ctx *ctx, int ch);
extern int func_021C00C0(GHIBuffer *buffer, int i);
extern char *func_02094B20(const char *s, const char *find);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern char *func_021C25C8(struct Conn *connection);
extern int func_021BFDEC(struct GHIBuffer *buffer, const char *data, int dataLen);
extern int func_021C3834(GHIConnection *);
extern void func_021C2BB0(GHIConnection *);
extern void func_021C0318(GHIConnection *);
extern int STD_TSScanf(char *src, char *fmt, ...);
extern void *memcpy(void *dst, const void *src, unsigned int n);
extern void func_0217EAE0(int);
extern int strncmp(const char *p1, const char *p2, unsigned long n);
extern char *strstr(const char *haystack, const char *needle);
extern unsigned long strlen(const char *p);
extern void *gsimalloc(unsigned long size);
extern int ghiDoReceive(GHIConnection *connection, char *buffer, int *bufferLen);
extern void ghiFreeTempBuffer(char *buffer);
extern int ghiAppendDataToBuffer(GHIBuffer *buffer, char *data, int dataLen);
extern int ghiDecryptReceivedData(GHIConnection *connection);
extern void *memmove(void *dst, const void *src, unsigned long n);
extern void ghiResetBuffer(GHIBuffer *buffer);
extern void ghiCallProgressCallback(GHIConnection *connection, char *buffer, int bufferLen);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern char *goastrdup(char *src);
extern int atoi(const char *p);
extern int ghiProcessIncomingFileData(GHIConnection *connection, char *data, int len);
extern int GOAGetLastError(int socket);
extern unsigned int func_0217F264(void);
extern void *func_0217EAB0(unsigned long size);
GHIBool func_021C3A38(GHIConnection *connection);
void func_021C3BAC(GHIConnection *connection);
void func_021C3D10(GHIConnection *connection);
void func_021C3E10(GHIConnection *connection);
void func_021C3EC0(GHIConnection *connection);
void func_021C4150(GHIConnection *connection);
void func_021C4384(GHIConnection *connection);
void func_021C4684(GHIConnection *connection);
void func_021C4764(GHIConnection *connection);
int func_021C4830(GHIConnection *connection);
void func_021C492C(GHIConnection *connection);
int func_021C4B18(GHIConnection *connection, char *data, int len);
int func_021C4BD8(GHIConnection *connection);
void func_021C4C00(GHIConnection *connection, char *data, int len);
int func_021C4C50(GHIConnection *connection, char *data, int len);
void func_021C4E68(int a);
void func_021C4E7C(GHIConnection *connection);
void func_021C5430(GHIConnection *connection);
extern char g_021CEFDC[];
extern char g_021CEFE4[];
extern char g_021CEFF0[];
extern char g_021CEFF4[];
extern char g_021CEFF8[];
extern char g_021CF010[];
extern char g_021CF050[];
extern char g_021CF090[];
extern char g_021CF0AC[];
extern char g_021CF0D0[];
extern char g_021CF0E0[];
extern char *g_021D3B2C;
extern char g_021CF0F8[];
extern char g_021CF114[];
extern char g_021CF12C[];
extern int g_021CE5B0;
extern u16 g_021D3B28;
extern char g_021CF138[];
extern char g_021CF14C[];
extern char g_021CF160[];
extern char g_021CF168[];
extern char g_021CF170[];
extern char g_021CF178[];
extern char g_021CF184[];
extern char g_021CF18C[];
extern char g_021CF194[];
extern char g_021CF198[];
extern char g_021CF1A4[];
extern char g_021CF1B4[];
extern char g_021CF1C0[];
extern char g_021CF1CC[];
extern char g_021CF1D4[];
extern char g_021CF1D8[];
extern char g_021CF1E8[];
extern char g_021CF1F8[];
extern char g_021CF204[];
extern char g_021CF210[];
extern const unsigned short g_020A61DC[];
extern char g_021CF220[];
extern char g_021CF234[];
extern char g_021CF248[];
extern char g_021CF24C[];
extern char g_021CF25C[];
extern char g_021CF274[];
extern char g_021CF28C[];
extern char g_021CF2A0[];
extern char g_021CF2BC[];
extern char g_021CF2C0[];
extern char g_021CF2C8[];
extern u16 __ctype_mapC[];
extern char g_021CF2D4[];
extern char g_021CF2E4[];
extern char g_021CE0B8[];
extern char g_021CF2F4[];
extern char g_021CF310[];
extern char g_021CF320[];





/*
 * sdk:      ghiParseURL (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
GHIBool func_021C3A38(GHIConnection *connection)
{
    char *URL;
    int nIndex;
    char tempChar;
    char *p;
    char *path;

    if (connection == 0)
        return GHI_FALSE;
    URL = connection->URL;
    if (URL == 0)
        return GHI_FALSE;
    if (func_020949F4((const unsigned char *)URL, (const unsigned char *)g_021CEFDC, 7) == 0) {
        connection->protocol = 0;
        URL += 7;
    } else if (func_020949F4((const unsigned char *)URL, (const unsigned char *)g_021CEFE4, 8) == 0) {
        connection->protocol = 1;
        URL += 8;
    } else {
        return GHI_FALSE;
    }
    nIndex = func_02094A60((const u8 *)URL, (const u8 *)g_021CEFF0);
    tempChar = URL[nIndex];
    URL[nIndex] = 0;
    connection->serverAddress = func_0217F1E0(URL);
    if (connection->serverAddress == 0)
        return GHI_FALSE;
    URL[nIndex] = tempChar;
    URL += nIndex;
    if (*URL == ':') {
        URL++;
        connection->serverPort = (unsigned short)func_020964E0((u32)URL);
        if (connection->serverPort == 0)
            return GHI_FALSE;
        while (*++URL != 0 && *URL != '/')
            ;
    } else if (connection->protocol == 1) {
        connection->serverPort = 443;
    } else {
        connection->serverPort = 80;
    }
    if (*URL == 0)
        URL = g_021CEFF4;
    path = func_0217F1E0(URL);
    connection->requestPath = path;
    while ((p = func_02094A28(path, ' ')) != 0) {
        *p = '+';
        path = connection->requestPath;
    }
    if (path == 0)
        return GHI_FALSE;
    return GHI_TRUE;
}





/*
 * sdk:      ghiDoSocketInit (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void func_021C3BAC(GHIConnection *connection)
{
    int aResult;

    func_0217D254(8, (char *)3, 16, g_021CEFF8);
    func_021C02C8(connection, 0, 0);
    func_0217F25C();
    if (func_021C3A38(connection) == GHI_FALSE) {
        connection->completed = 1;
        connection->result = 3;
        return;
    }
    if (connection->protocol == 1 && connection->encryptor.engine == 0) {
        func_0217D254(8, 0, 2, g_021CF010);
        func_021C109C(connection->request, 5);
    } else if (connection->protocol != 1 && connection->encryptor.engine != 0) {
        func_021C109C(connection->request, 0);
        func_0217D254(8, 0, 2, g_021CF050);
    }
    if (connection->protocol == 1 && connection->encryptor.field_08 == 0) {
        func_0217D254(8, (char *)3, 15, g_021CF090);
        aResult = connection->encryptor.initFunc(connection, &connection->encryptor);
        if (aResult == 3) {
            func_0217D254(8, (char *)3, 2, g_021CF0AC);
            connection->completed = 1;
            connection->result = 17;
            return;
        }
    }
    connection->state = 1;
    func_021C02C8(connection, 0, 0);
}





/*
 * sdk:      ghiDoHostLookup (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void func_021C3D10(GHIConnection *connection)
{
    char *server;

    if (connection->handle != 0) {
        connection->state = 2;
        func_021C02C8((GHIConnection *)connection, 0, 0);
        return;
    }
    func_0217D254(8, (char *)3, 16, g_021CF0D0);
    server = connection->proxyOverrideServer;
    if (server == 0) {
        server = g_021D3B2C;
        if (server == 0)
            server = connection->serverAddress;
    }
    connection->serverIP = func_0217ED38((int)server);
    if (connection->serverIP == (unsigned int)-1) {
        if (func_0217F150(server, (struct GSIResolveHostnameInfo **)(&connection->handle)) == -1) {
            func_0217D254(8, (char *)3, 1, g_021CF0E0);
            connection->handle = 0;
            connection->completed = 1;
            connection->result = 4;
            return;
        }
    }
    if (connection->serverIP == (unsigned int)-1) {
        connection->state = 2;
        func_021C02C8((GHIConnection *)connection, 0, 0);
        return;
    }
    connection->state = 3;
    func_021C02C8((GHIConnection *)connection, 0, 0);
}





/*
 * sdk:      ghiDoLookupPending (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void func_021C3E10(GHIConnection *connection)
{
    connection->serverIP = func_0217F1CC(connection->handle);
    if (connection->serverIP == (unsigned int)-1) {
        func_0217D254(8, (char *)3, 1, g_021CF0F8);
        connection->handle = 0;
        connection->completed = 1;
        connection->result = 4;
        return;
    }
    if (connection->serverIP == 0) {
        connection->state = 2;
        func_021C02C8((GHIConnection *)connection, 0, 0);
        return;
    }
    connection->handle = 0;
    func_0217D254(8, (char *)3, 16, g_021CF114);
    connection->state = 3;
    func_021C02C8((GHIConnection *)connection, 0, 0);
}





/*
 * sdk:      ghiDoConnecting (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void func_021C3EC0(GHIConnection *connection)
{
    int rcode;
    int socketError;
    SOCSockAddrIn address;
    int writeFlag;
    int exceptFlag;

    func_0217D254(8, (char *)3, 0x10, g_021CF12C);

    if (connection->socket == -1)
    {
        connection->socket = func_0217EB18(2, 1, 0);
        if (connection->socket == -1)
        {
            connection->completed = 1;
            connection->result = 5;
            connection->socketError = func_0217ED54(connection->socket);
            return;
        }
        if (!func_0217EE50(connection->socket, 0))
        {
            connection->completed = 1;
            connection->result = 5;
            connection->socketError = func_0217ED54(connection->socket);
            return;
        }
        if (connection->throttle)
            func_0217EF00(connection->socket, g_021CE5B0);

        if (connection->encryptor.engine == 4)
        {
            if (connection->encryptor.startFunc(connection, &connection->encryptor) == 3)
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
        else if (g_021D3B2C)
            address.port = SOC_HTONS(g_021D3B28);
        else
            address.port = SOC_HTONS(connection->serverPort);
        address.addr = connection->serverIP;

        rcode = func_0217EC08(connection->socket, &address, sizeof(address));
        if (rcode == -1)
        {
            socketError = func_0217ED54(connection->socket);
            if (socketError != -6 && socketError != -26 && socketError != -76)
            {
                connection->completed = 1;
                connection->result = 6;
                connection->socketError = socketError;
                return;
            }
        }
    }

    rcode = func_0217ED64(connection->socket, 0, &writeFlag, &exceptFlag);
    if (rcode == -1 || (rcode == 1 && exceptFlag))
    {
        connection->completed = 1;
        connection->result = 6;
        if (rcode == -1)
            connection->socketError = func_0217ED54(connection->socket);
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
        func_021C02C8((GHIConnection *)connection, 0, 0);
    }
}




/*
 * sdk:      ghiDoSecuringSession (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void func_021C4150(GHIConnection *connection)
{
    int bufferLen;
    char buffer[1025];
    int result;

    if (!connection->encryptor.initialized)
    {
        func_0217D254(8, (char *)3, 0x10, g_021CF138);
        if (connection->encryptor.startFunc != 0)
        {
            if (connection->encryptor.startFunc(connection, &connection->encryptor) == 3)
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
        }
        if (connection->encryptor.sessionEstablished)
        {
            connection->state = 5;
            func_021C02C8((struct GHIConnection *)connection, 0, 0);
            return;
        }
    }

    if (connection->encryptor.handshaking)
    {
        if (connection->encryptor.startFunc != 0)
        {
            if (connection->encryptor.startFunc(connection, &connection->encryptor) == 3)
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
        }
        if (!connection->encryptor.sessionEstablished)
            return;
        connection->state = 5;
        func_021C02C8((struct GHIConnection *)connection, 0, 0);
        return;
    }

    if (connection->sendBuffer.pos < connection->sendBuffer.len)
    {
        if (!func_021C011C((struct GHIConnection *)connection))
            return;
        if (connection->sendBuffer.pos < connection->sendBuffer.len)
            return;
        func_021C00FC(&connection->sendBuffer);
    }

    bufferLen = sizeof(buffer);
    result = func_021C04D4((struct GHIConnection *)connection, buffer, &bufferLen);
    if (result == 2 || result == 3)
    {
        connection->completed = 1;
        connection->result = 0x11;
        return;
    }
    if (result != 0)
        return;
    if (!func_021BFCEC((struct GHIBuffer *)(&connection->decodeBuffer), buffer, bufferLen))
        return;
    if (!func_021C0378((struct GHIConnection *)connection))
    {
        connection->completed = 1;
        connection->result = 0x11;
        return;
    }
    if (!connection->encryptor.sessionEstablished)
        return;
    connection->state = 5;
    func_021C02C8((struct GHIConnection *)connection, 0, 0);
}




/*
 * sdk:      ghiDoSendingRequest (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void func_021C4384(GHIConnection *connection)
{
    char buf[16];
    GHIBuffer *writeBuffer;
    char *requestType;

    func_0217D254(8, (char *)3, 0x10, g_021CF14C);

    if (connection->sendBuffer.len == 0)
    {
        if (connection->encryptor.engine == 0 || !connection->encryptor.encryptOnBuffer)
            writeBuffer = &connection->sendBuffer;
        else
            writeBuffer = &connection->encodeBuffer;

        if (connection->post != 0 && !connection->postingState.field_1C)
            requestType = g_021CF160;
        else if (connection->type == 3)
            requestType = g_021CF168;
        else
            requestType = g_021CF170;
        func_021BFCEC((struct GHIBuffer *)writeBuffer, requestType, 0);

        if (connection->proxyOverrideServer != 0 || g_021D3B2C != 0)
            func_021BFCEC((struct GHIBuffer *)writeBuffer, connection->URL, 0);
        else
            func_021BFCEC((struct GHIBuffer *)writeBuffer, connection->requestPath, 0);
        func_021BFCEC((struct GHIBuffer *)writeBuffer, g_021CF178, 0);

        if (connection->serverPort == 80)
        {
            func_021BFF7C(writeBuffer, g_021CF184, connection->serverAddress);
        }
        else
        {
            func_021BFCEC((struct GHIBuffer *)writeBuffer, g_021CF18C, 0);
            func_021BFCEC((struct GHIBuffer *)writeBuffer, connection->serverAddress, 0);
            func_021C0004((struct Ctx *)writeBuffer, ':');
            func_021C00C0(writeBuffer, connection->serverPort);
            func_021BFCEC((struct GHIBuffer *)writeBuffer, g_021CF194, 2);
        }

        if (connection->sendHeaders == 0 || func_02094B20(connection->sendHeaders, g_021CF198) == 0)
            func_021BFF7C(writeBuffer, g_021CF198, g_021CF1A4);

        if (connection->persistConnection)
            func_021BFF7C(writeBuffer, g_021CF1B4, g_021CF1C0);
        else
            func_021BFF7C(writeBuffer, g_021CF1B4, g_021CF1CC);

        if (connection->post != 0 && !connection->postingState.field_1C)
        {
            func_02084F40(buf, g_021CF1D4, connection->postingState.totalBytes);
            func_021BFF7C(writeBuffer, g_021CF1D8, buf);
            func_021BFF7C(writeBuffer, g_021CF1E8, func_021C25C8((struct Conn *)connection));
        }

        if (connection->sendHeaders != 0)
            func_021BFCEC((struct GHIBuffer *)writeBuffer, connection->sendHeaders, 0);
        func_021BFCEC((struct GHIBuffer *)writeBuffer, g_021CF194, 2);

        if (connection->encryptor.engine != 0 && connection->encryptor.encryptOnBuffer == 1)
        {
            if (!func_021BFDEC((struct GHIBuffer *)(&connection->sendBuffer), writeBuffer->data, writeBuffer->len))
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
            func_021C00FC(writeBuffer);
        }
    }

    if (!func_021C011C(connection))
        return;
    if (connection->sendBuffer.pos < connection->sendBuffer.len)
        return;
    func_021C00FC(&connection->sendBuffer);

    if (connection->post != 0 && !connection->postingState.field_1C)
        connection->state = 6;
    else
        connection->state = 7;
    func_021C02C8(connection, 0, 0);
}




/*
 * sdk:      ghiDoPosting (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void func_021C4684(GHIConnection *connection)
{
    int result;
    int oldBytesPosted;
    int rcode;
    int readFlag;

    func_0217D254(8, (char *)3, 16, g_021CF1F8);
    oldBytesPosted = connection->postingState.bytesPosted;
    result = func_021C3834(connection);
    if (result == 0) {
        readFlag = 0;
        func_021C2BB0(connection);
        rcode = func_0217ED64(connection->socket, &readFlag, 0, 0);
        if (rcode != 1)
            return;
        if (readFlag == 0)
            return;
        connection->state = 8;
        func_021C02C8((struct GHIConnection *)connection, 0, 0);
        return;
    }
    if (result == 3) {
        connection->postingState.waitPostContinue = 0;
        return;
    }
    if (oldBytesPosted != connection->postingState.bytesPosted)
        func_021C0318(connection);
    if (result != 1)
        return;
    func_021C2BB0(connection);
    connection->postingState.field_1C = 1;
    connection->state = 7;
    func_021C02C8((struct GHIConnection *)connection, 0, 0);
}



/*
 * sdk:      ghiDoWaiting (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void func_021C4764(GHIConnection *connection)
{
    int rcode;
    int readFlag;
    int exceptFlag;

    func_0217D254(8, (char *)3, 16, g_021CF204);
    rcode = func_0217ED64(connection->socket, &readFlag, 0, &exceptFlag);
    if (rcode == -1 || (rcode == 1 && exceptFlag)) {
        connection->completed = 1;
        connection->result = 5;
        if (rcode == -1)
            connection->socketError = func_0217ED54(connection->socket);
        else
            connection->socketError = 0;
        return;
    }
    if (rcode != 1)
        return;
    if (readFlag == 0)
        return;
    connection->state = 8;
    func_021C02C8((GHIConnection *)connection, 0, 0);
}



static inline int isspace(int c) { return ((c < 0 || c >= 0x80) ? 0 : (g_020A61DC[c] & 0x100)); }



/*
 * sdk:      ghiParseStatus (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
int func_021C4830(GHIConnection *connection)
{
    int majorVersion;
    int minorVersion;
    int statusCode;
    int statusStringIndex;
    int rcode;
    char c;

    rcode = STD_TSScanf(connection->recvBuffer.data, g_021CF210, &majorVersion, &minorVersion,
                        &statusCode, &statusStringIndex);
    if (rcode != 3 || majorVersion < 1 || statusCode < 100 || statusCode >= 600) {
        connection->completed = 1;
        connection->result = 7;
        return 0;
    }
    while ((c = connection->recvBuffer.data[statusStringIndex]) != 0 && isspace(c))
        statusStringIndex++;
    connection->statusMajorVersion = majorVersion;
    connection->statusMinorVersion = minorVersion;
    connection->statusCode = statusCode;
    connection->statusStringIndex = statusStringIndex;
    return 1;
}



/*
 * sdk:      ghiDoReceivingStatus (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void func_021C492C(GHIConnection *connection)
{
    char buffer[1024];
    int bufferLen;
    int result;
    char *endOfStatus;
    int statusLength;

    func_0217D254(8, (char *)3, 0x10, g_021CF220);

    bufferLen = sizeof(buffer);
    result = func_021C04D4((struct GHIConnection *)connection, buffer, &bufferLen);
    if (result == 3 || result == 1)
        return;

    if (result == 0)
    {
        if (connection->encryptor.engine != 0 && connection->encryptor.encryptOnBuffer == 1)
        {
            if (!func_021BFCEC((struct GHIBuffer *)(&connection->decodeBuffer), buffer, bufferLen))
                return;
            if (!func_021C0378((struct GHIConnection *)connection))
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
        }
        else
        {
            if (!func_021BFCEC((struct GHIBuffer *)(&connection->recvBuffer), buffer, bufferLen))
                return;
        }
    }

    endOfStatus = func_02094B20(connection->recvBuffer.data, g_021CF194);
    if (endOfStatus != 0)
    {
        *endOfStatus = '\0';
        statusLength = endOfStatus - connection->recvBuffer.data;

        if (!func_021C4830(connection))
            return;

        connection->headerStringIndex = statusLength + 2;

        if (connection->statusCode == 100 && connection->postingState.waitPostContinue)
        {
            connection->postingState.waitPostContinue = 0;
            func_021C00FC((GHIBuffer *)(&connection->recvBuffer));
            connection->state = 6;
            func_021C02C8(connection, 0, 0);
            func_0217D254(8, 0, 0x10, g_021CF234);
        }
        else
        {
            connection->state = 9;
            func_021C02C8(connection, 0, 0);
        }
    }
    else if (result == 2)
    {
        connection->completed = 1;
        connection->result = 7;
        connection->socketError = func_0217ED54(connection->socket);
    }
}



/*
 * sdk:      ghiDeliverIncomingFileData (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
int func_021C4B18(GHIConnection *connection, char *data, int len)
{
    char *buffer = 0;
    int bufferLen = 0;

    connection->fileBytesReceived += len;
    if (connection->fileBytesReceived == connection->totalSize || connection->connectionClosed != 0)
        connection->completed = 1;

    if (connection->type == 0) {
        if (func_021BFCEC((struct GHIBuffer *)(&connection->getFileBuffer), data, len) == 0)
            return 0;
        buffer = connection->getFileBuffer.data;
        bufferLen = connection->getFileBuffer.len;
    } else if (connection->type == 1) {
        if (len != 0) {
            connection->completed = 1;
            connection->result = 13;
            return 0;
        }
        buffer = data;
        bufferLen = len;
    } else if (connection->type == 2) {
        buffer = data;
        bufferLen = len;
    }
    func_021C02C8((GHIConnection *)connection, buffer, bufferLen);
    return 1;
}



/*
 * sdk:      ghiParseChunkSize (ghttpprocess.o)
 */
int func_021C4BD8(GHIConnection *connection)
{
    int num;
    if (STD_TSScanf(connection->chunkHeader, g_021CF248, &num) != 1)
        return -1;
    return num;
}



/*
 * sdk:      ghiAppendToChunkHeaderBuffer (ghttpprocess.o)
 */
void func_021C4C00(GHIConnection *connection, char *data, int len)
{
    int n;
    if (len == 0 || connection->chunkHeaderLen >= 10)
        return;
    n = 10 - connection->chunkHeaderLen;
    if (n >= len)
        n = len;
    memcpy(connection->chunkHeader + connection->chunkHeaderLen, data, n);
    connection->chunkHeaderLen += n;
    connection->chunkHeader[connection->chunkHeaderLen] = 0;
}



int func_021C4C50(GHIConnection *connection, char *data, int len)
{
    char *endOfHeader;
    char *endOfFooter;
    int toWrite;

    if (connection->chunkedTransfer)
    {
        while (len > 0)
        {
            if (connection->chunkReadingState == 0)
            {
                endOfHeader = func_02094A28(data, '\n');
                if (endOfHeader != 0)
                {
                    func_021C4C00((GHIConnection *)connection, data, endOfHeader - data);
                    endOfHeader++;
                    len -= endOfHeader - data;
                    data = endOfHeader;
                    connection->chunkBytesLeft = func_021C4BD8(connection);
                    if (connection->chunkBytesLeft == -1)
                    {
                        connection->completed = 1;
                        connection->result = 7;
                        return 0;
                    }
                    if (connection->chunkBytesLeft == 0)
                    {
                        connection->chunkReadingState = 3;
                        func_0217D254(8, 0, 0x20, g_021CF24C);
                    }
                    else
                    {
                        connection->chunkReadingState = 1;
                        func_0217D254(8, 0, 0x20, g_021CF25C, connection->chunkBytesLeft);
                    }
                }
                else
                {
                    func_021C4C00((GHIConnection *)connection, data, len);
                    return 1;
                }
            }
            else if (connection->chunkReadingState == 1)
            {
                toWrite = connection->chunkBytesLeft;
                if (toWrite >= len)
                    toWrite = len;
                func_0217D254(8, 0, 0x20, g_021CF274, toWrite);
                if (!func_021C4B18(connection, data, toWrite))
                    return 0;
                data += toWrite;
                len -= toWrite;
                connection->chunkBytesLeft -= toWrite;
                if (connection->chunkBytesLeft == 0)
                    connection->chunkReadingState = 2;
            }
            else if (connection->chunkReadingState == 2)
            {
                endOfFooter = func_02094A28(data, '\n');
                if (endOfFooter == 0)
                    return 1;
                endOfFooter++;
                len -= endOfFooter - data;
                data = endOfFooter;
                connection->chunkHeader[0] = '\0';
                connection->chunkHeaderLen = 0;
                connection->chunkBytesLeft = 0;
                connection->chunkReadingState = 0;
                func_0217D254(8, 0, 0x20, g_021CF28C);
            }
            else if (connection->chunkReadingState == 3)
            {
                connection->completed = 1;
                func_0217D254(8, 0, 0x20, g_021CF2A0);
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    return func_021C4B18(connection, data, len);
}



/*
 * Null-guarded release through the ov009 helper at 0x0217EAE0.
 */
void func_021C4E68(int a)
{
    if (a == 0)
        return;
    func_0217EAE0(a);
}



/*
 * sdk:      ghiDoReceivingHeaders (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * notes:    every byte and all 48 relocations resolve (the last is the
 *           vendor template @13998, declared in symbols:).  The second isspace loop (after the header-value scan) is the
 *           short-circuit `(c < 0 || c >= 0x80) ? 0 : table` form, not the unsigned
 *           fold the first loop uses.
 */
void func_021C4E7C(GHIConnection *connection)
{
    int result;
    int hasHeaders;
    char *headers;
    char *endOfHeaders;
    int bufferLen;
    char *buffer;
    char *fileStart;
    int fileLength;
    char *contentLength;
    char *location;
    char *end;
    int nMaxLen;

    nMaxLen = 0x1000;
    hasHeaders = 1;
    buffer = gsimalloc(nMaxLen);
    if (buffer == 0) {
        connection->completed = 1;
        connection->result = 1;
        return;
    }
    bufferLen = nMaxLen;
    result = ghiDoReceive(connection, buffer, &bufferLen);
    if (result == 3) {
        ghiFreeTempBuffer(buffer);
        return;
    }
    if (result == 1) {
        ghiFreeTempBuffer(buffer);
        return;
    }
    if (result == 0) {
        if (connection->encryptor.engine != 0 && connection->encryptor.encryptOnBuffer == 1) {
            if (ghiAppendDataToBuffer(&connection->decodeBuffer, buffer, bufferLen) == 0) {
                ghiFreeTempBuffer(buffer);
                return;
            }
            if (ghiDecryptReceivedData(connection) == 0) {
                connection->completed = 1;
                connection->result = 0x11;
                ghiFreeTempBuffer(buffer);
                return;
            }
        } else {
            if (ghiAppendDataToBuffer(&connection->recvBuffer, buffer, bufferLen) == 0) {
                ghiFreeTempBuffer(buffer);
                return;
            }
        }
    }

    headers = connection->recvBuffer.data + connection->headerStringIndex;
    if (connection->statusCode / 100 == 1 &&
        (strncmp(headers, g_021CF194, 2) == 0 ||
         strncmp(headers, g_021CF2BC, 2) == 0)) {
        endOfHeaders = headers;
        hasHeaders = 0;
    } else {
        endOfHeaders = strstr(headers, g_021CF2C0);
    }
    if (endOfHeaders == 0)
        endOfHeaders = strstr(headers, g_021CF2BC);
    if (endOfHeaders != 0) {
        if (hasHeaders == 1)
            endOfHeaders += 2;
        *endOfHeaders = 0;

        fileStart = endOfHeaders + 2;
        fileLength = connection->recvBuffer.len - (fileStart - connection->recvBuffer.data);
        connection->recvBuffer.pos = connection->recvBuffer.len =
            endOfHeaders - connection->recvBuffer.data + 1;

        if (connection->statusCode / 100 == 1) {
            if (fileLength != 0) {
                memmove(connection->recvBuffer.data, fileStart, fileLength + 1);
                connection->recvBuffer.len = fileLength;
            } else {
                ghiResetBuffer(&connection->recvBuffer);
            }
            if (connection->postingState.waitPostContinue != 0) {
                connection->postingState.waitPostContinue = 0;
                connection->state = 6;
                ghiCallProgressCallback(connection, 0, 0);
            }
            connection->state = 8;
            ghiCallProgressCallback(connection, 0, 0);
            ghiFreeTempBuffer(buffer);
            return;
        }

        result = 0;
        if (connection->statusCode / 100 == 3) {
            if (connection->redirectCount > 10) {
                connection->completed = 1;
                connection->result = 0xb;
                ghiFreeTempBuffer(buffer);
                return;
            }
            location = strstr(headers, g_021CF2C8);
            if (location != 0) {
                location += 9;
                while (ISSPACE(*location))
                    location++;
                end = location;
                while (*end != 0 && !(((*end) < 0 || (*end) >= 0x80) ? 0 : (__ctype_mapC[*end] & 0x100)))
                    end++;
                *end = 0;
                if (*location == '/') {
                    connection->redirectURL = gsimalloc(strlen(connection->serverAddress) + 14 + strlen(location));
                    if (connection->redirectURL == 0) {
                        connection->completed = 1;
                        connection->result = 1;
                    }
                    OS_SPrintf(connection->redirectURL, g_021CF2D4,
                               connection->serverAddress, connection->serverPort, location);
                } else {
                    connection->redirectURL = goastrdup(location);
                    if (connection->redirectURL == 0) {
                        connection->completed = 1;
                        connection->result = 1;
                    }
                }
                ghiFreeTempBuffer(buffer);
                return;
            }
        }

        contentLength = strstr(headers, g_021CF2E4);
        if (contentLength != 0) {
            char *pEnd;
            char *pStart;
            char szMaxSize[11] = "2147483647";
            int len;

            pStart = contentLength + 0x10;
            pEnd = pStart;
            len = strlen(szMaxSize);
            while (pEnd && *pEnd && *pEnd != '\n' && *pEnd != '\r' && *pEnd != ' ')
                pEnd++;
            if (pEnd - pStart > len) {
                connection->completed = 1;
                connection->result = 0x10;
                ghiFreeTempBuffer(buffer);
                return;
            }
            if (len == pEnd - pStart && strncmp(pStart, szMaxSize, pEnd - pStart) >= 0) {
                connection->completed = 1;
                connection->result = 0x10;
                ghiFreeTempBuffer(buffer);
                return;
            }
            connection->totalSize = atoi(pStart);
        }

        connection->chunkedTransfer = (strstr(headers, g_021CF2F4) != 0) ? 1 : 0;
        if (connection->chunkedTransfer) {
            connection->chunkHeader[0] = 0;
            connection->chunkHeaderLen = 0;
            connection->chunkBytesLeft = 0;
            connection->chunkReadingState = 0;
        }
        if (connection->type == 3 || connection->type == 4) {
            connection->completed = 1;
            ghiFreeTempBuffer(buffer);
            return;
        }

        connection->state = 0xa;
        if (contentLength != 0 && connection->totalSize == 0) {
            connection->completed = 1;
            ghiFreeTempBuffer(buffer);
            return;
        }
        if (fileLength > 0)
            ghiProcessIncomingFileData(connection, fileStart, fileLength);
    } else if (result == 2) {
        connection->completed = 1;
        connection->result = 7;
        connection->socketError = GOAGetLastError(connection->socket);
    }
    ghiFreeTempBuffer(buffer);
}



/*
 * sdk:      ghiDoReceivingFile (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
void func_021C5430(GHIConnection *connection)
{
    int result;
    unsigned int start_time;
    unsigned int running_time;
    int bufferLen;
    char *buffer;
    int decryptedLen;

    start_time = func_0217F264();
    running_time = 0;
    bufferLen = 0;

    buffer = func_0217EAB0(0x2000);
    if (buffer == 0)
    {
        connection->completed = 1;
        connection->result = 1;
        return;
    }

    func_0217D254(8, (char *)3, 0x10, g_021CF310);

    while (!connection->completed && running_time < connection->maxRecvTime)
    {
        bufferLen = 0x2000;
        result = func_021C04D4(connection, buffer, &bufferLen);
        if (result == 1)
        {
            func_021C4E68((int)buffer);
            if (connection->receiveFileIdleTime == 0)
            {
                connection->receiveFileIdleTime = func_0217F264();
                return;
            }
            if (func_0217F264() - connection->receiveFileIdleTime < 30000)
                return;
            func_0217D254(8, 0, 1, g_021CF320, func_0217F264() - connection->receiveFileIdleTime);
            connection->receiveFileIdleTime = 0;
            connection->completed = 1;
            connection->result = 0x13;
            return;
        }
        connection->receiveFileIdleTime = 0;

        if (result == 3)
        {
            func_021C4E68((int)buffer);
            return;
        }
        if (result == 2)
        {
            connection->completed = 1;
            if (connection->totalSize > 0 && connection->fileBytesReceived < connection->totalSize)
                connection->result = 0xF;
            func_021C4E68((int)buffer);
            return;
        }

        if (connection->encryptor.engine != 0 && connection->encryptor.encryptOnBuffer == 1)
        {
            if (!func_021BFCEC((struct GHIBuffer *)((struct GHIBuffer *)(&connection->decodeBuffer)), buffer, bufferLen))
            {
                func_021C4E68((int)buffer);
                return;
            }
            connection->recvBuffer.len = connection->recvBuffer.pos;
            if (!func_021C0378(connection))
            {
                connection->completed = 1;
                connection->result = 0x11;
                func_021C4E68((int)buffer);
                return;
            }
            decryptedLen = connection->recvBuffer.len - connection->recvBuffer.pos;
            if (decryptedLen != 0)
            {
                if (!func_021C4C50(connection, connection->recvBuffer.data + connection->recvBuffer.pos, decryptedLen))
                {
                    func_021C4E68((int)buffer);
                    return;
                }
            }
        }
        else
        {
            if (!func_021C4C50(connection, buffer, bufferLen))
            {
                func_021C4E68((int)buffer);
                return;
            }
        }

        running_time = func_0217F264() - start_time;
    }

    func_021C4E68((int)buffer);
}

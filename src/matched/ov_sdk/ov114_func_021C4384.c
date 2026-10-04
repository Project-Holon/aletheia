/*
 * function: func_021C4384
 * address:  0x021C4384
 * packet:   pkt_ov114_021C4384
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoSendingRequest (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_021BFCEC  0x021BFCEC  arm  ov114
 *   func_021BFF7C  0x021BFF7C  arm  ov114
 *   func_021C0004  0x021C0004  arm  ov114
 *   func_021C00C0  0x021C00C0  arm  ov114
 *   func_02094B20  0x02094B20  arm
 *   func_02084F40  0x02084F40  arm
 *   func_021C25C8  0x021C25C8  arm  ov114
 *   func_021BFDEC  0x021BFDEC  arm  ov114
 *   func_021C00FC  0x021C00FC  arm  ov114
 *   func_021C011C  0x021C011C  arm  ov114
 *   func_021C02C8  0x021C02C8  arm  ov114
 *   g_021CF14C     0x021CF14C  data
 *   g_021CF160     0x021CF160  data
 *   g_021CF168     0x021CF168  data
 *   g_021CF170     0x021CF170  data
 *   g_021D3B2C     0x021D3B2C  data
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
 */

typedef unsigned short u16;

typedef struct {
    void *connection;
    char *data;
    int size;
    int len;
    int pos;
    char pad14[0x10];
} GHIBuffer;

typedef struct {
    char pad000[0x0C];
    int type;                   /* 0x00C */
    int state;                  /* 0x010 */
    char *URL;                  /* 0x014 */
    char *serverAddress;        /* 0x018 */
    char pad01C[0x04];
    u16 serverPort;             /* 0x020 */
    char pad022[0x02];
    char *requestPath;          /* 0x024 */
    char pad028[0x04];
    char *sendHeaders;          /* 0x02C */
    char pad030[0x0C];
    int persistConnection;      /* 0x03C */
    int result;                 /* 0x040 */
    char pad044[0x14];
    GHIBuffer sendBuffer;       /* 0x058 */
    GHIBuffer encodeBuffer;     /* 0x07C */
    char pad0A0[0x84];
    int completed;              /* 0x124 */
    char pad128[0x3C];
    void *post;                 /* 0x164 */
    char pad168[0x0C];
    int totalBytes;             /* 0x174 */
    char pad178[0x0C];
    int postCompleted;          /* 0x184 */
    char pad188[0x04];
    char *proxyOverrideServer;  /* 0x18C */
    char pad190[0x08];
    void *encryptEngine;        /* 0x198 */
    char pad19C[0x0C];
    int sessionEstablished;     /* 0x1A8 */
} GHIConnection;

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_021BFCEC(GHIBuffer *buffer, const char *data, int dataLen);
extern int func_021BFF7C(GHIBuffer *buffer, const char *name, const char *value);
extern int func_021C0004(GHIBuffer *buffer, int c);
extern int func_021C00C0(GHIBuffer *buffer, int i);
extern char *func_02094B20(const char *s, const char *find);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern char *func_021C25C8(GHIConnection *connection);
extern int func_021BFDEC(GHIBuffer *buffer, char *data, int dataLen);
extern void func_021C00FC(GHIBuffer *buffer);
extern int func_021C011C(GHIConnection *connection);
extern void func_021C02C8(GHIConnection *connection, char *buffer, int bufferLen);
extern char g_021CF14C[];
extern char g_021CF160[];
extern char g_021CF168[];
extern char g_021CF170[];
extern char *g_021D3B2C;
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

void func_021C4384(GHIConnection *connection)
{
    char buf[16];
    GHIBuffer *writeBuffer;
    char *requestType;

    func_0217D254(8, (char *)3, 0x10, g_021CF14C);

    if (connection->sendBuffer.len == 0)
    {
        if (connection->encryptEngine == 0 || !connection->sessionEstablished)
            writeBuffer = &connection->sendBuffer;
        else
            writeBuffer = &connection->encodeBuffer;

        if (connection->post != 0 && !connection->postCompleted)
            requestType = g_021CF160;
        else if (connection->type == 3)
            requestType = g_021CF168;
        else
            requestType = g_021CF170;
        func_021BFCEC(writeBuffer, requestType, 0);

        if (connection->proxyOverrideServer != 0 || g_021D3B2C != 0)
            func_021BFCEC(writeBuffer, connection->URL, 0);
        else
            func_021BFCEC(writeBuffer, connection->requestPath, 0);
        func_021BFCEC(writeBuffer, g_021CF178, 0);

        if (connection->serverPort == 80)
        {
            func_021BFF7C(writeBuffer, g_021CF184, connection->serverAddress);
        }
        else
        {
            func_021BFCEC(writeBuffer, g_021CF18C, 0);
            func_021BFCEC(writeBuffer, connection->serverAddress, 0);
            func_021C0004(writeBuffer, ':');
            func_021C00C0(writeBuffer, connection->serverPort);
            func_021BFCEC(writeBuffer, g_021CF194, 2);
        }

        if (connection->sendHeaders == 0 || func_02094B20(connection->sendHeaders, g_021CF198) == 0)
            func_021BFF7C(writeBuffer, g_021CF198, g_021CF1A4);

        if (connection->persistConnection)
            func_021BFF7C(writeBuffer, g_021CF1B4, g_021CF1C0);
        else
            func_021BFF7C(writeBuffer, g_021CF1B4, g_021CF1CC);

        if (connection->post != 0 && !connection->postCompleted)
        {
            func_02084F40(buf, g_021CF1D4, connection->totalBytes);
            func_021BFF7C(writeBuffer, g_021CF1D8, buf);
            func_021BFF7C(writeBuffer, g_021CF1E8, func_021C25C8(connection));
        }

        if (connection->sendHeaders != 0)
            func_021BFCEC(writeBuffer, connection->sendHeaders, 0);
        func_021BFCEC(writeBuffer, g_021CF194, 2);

        if (connection->encryptEngine != 0 && connection->sessionEstablished == 1)
        {
            if (!func_021BFDEC(&connection->sendBuffer, writeBuffer->data, writeBuffer->len))
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

    if (connection->post != 0 && !connection->postCompleted)
        connection->state = 6;
    else
        connection->state = 7;
    func_021C02C8(connection, 0, 0);
}

/*
 * function: ghiDoSecuringSession
 * address:  0x021C4150
 * packet:   pkt_ov114_021C4150
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoSecuringSession (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   ghiCallProgressCallback  0x021C02C8  arm  ov114
 *   ghiSendBufferedData  0x021C011C  arm  ov114
 *   ghiResetBuffer  0x021C00FC  arm  ov114
 *   ghiDoReceive  0x021C04D4  arm  ov114
 *   ghiAppendDataToBuffer  0x021BFCEC  arm  ov114
 *   ghiDecryptReceivedData  0x021C0378  arm  ov114
 *   sGhttpSecuringSession     0x021CF138  data
 */

typedef struct GHIConnection GHIConnection;

typedef struct {
    void *connection;
    char *data;
    int size;
    int len;
    int pos;
    char pad14[0x10];
} GHIBuffer;

typedef struct GHIEncryptor {
    char pad00[0x0C];
    int initialized;            /* 0x0C */
    int sessionEstablished;     /* 0x10 */
    char pad14[0x08];
    int handshaking;            /* 0x1C */
    char pad20[0x08];
    int (*processFunc)(GHIConnection *connection, struct GHIEncryptor *encryptor); /* 0x28 */
} GHIEncryptor;

struct GHIConnection {
    char pad000[0x10];
    int state;                  /* 0x010 */
    char pad014[0x2C];
    int result;                 /* 0x040 */
    char pad044[0x14];
    GHIBuffer sendBuffer;       /* 0x058 */
    char pad07C[0x48];
    GHIBuffer decodeBuffer;     /* 0x0C4 */
    char pad0E8[0x3C];
    int completed;              /* 0x124 */
    char pad128[0x6C];
    GHIEncryptor encryptor;     /* 0x194 */
};

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void ghiCallProgressCallback(struct GHIConnection *connection, char *buffer, int bufferLen);
extern int ghiSendBufferedData(struct GHIConnection *connection);
extern void ghiResetBuffer(GHIBuffer *buffer);
extern int ghiDoReceive(struct GHIConnection *connection, char *buffer, int *bufferLen);
struct GHIBuffer;
extern int ghiAppendDataToBuffer(struct GHIBuffer *buffer, char *data, int dataLen);
extern int ghiDecryptReceivedData(struct GHIConnection *connection);
extern char sGhttpSecuringSession[];

void ghiDoSecuringSession(GHIConnection *connection)
{
    int bufferLen;
    char buffer[1025];
    int result;

    if (!connection->encryptor.initialized)
    {
        func_0217D254(8, (char *)3, 0x10, sGhttpSecuringSession);
        if (connection->encryptor.processFunc != 0)
        {
            if (connection->encryptor.processFunc(connection, &connection->encryptor) == 3)
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
        }
        if (connection->encryptor.sessionEstablished)
        {
            connection->state = 5;
            ghiCallProgressCallback(connection, 0, 0);
            return;
        }
    }

    if (connection->encryptor.handshaking)
    {
        if (connection->encryptor.processFunc != 0)
        {
            if (connection->encryptor.processFunc(connection, &connection->encryptor) == 3)
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
        }
        if (!connection->encryptor.sessionEstablished)
            return;
        connection->state = 5;
        ghiCallProgressCallback(connection, 0, 0);
        return;
    }

    if (connection->sendBuffer.pos < connection->sendBuffer.len)
    {
        if (!ghiSendBufferedData(connection))
            return;
        if (connection->sendBuffer.pos < connection->sendBuffer.len)
            return;
        ghiResetBuffer(&connection->sendBuffer);
    }

    bufferLen = sizeof(buffer);
    result = ghiDoReceive(connection, buffer, &bufferLen);
    if (result == 2 || result == 3)
    {
        connection->completed = 1;
        connection->result = 0x11;
        return;
    }
    if (result != 0)
        return;
    if (!ghiAppendDataToBuffer((struct GHIBuffer *)(&connection->decodeBuffer), buffer, bufferLen))
        return;
    if (!ghiDecryptReceivedData(connection))
    {
        connection->completed = 1;
        connection->result = 0x11;
        return;
    }
    if (!connection->encryptor.sessionEstablished)
        return;
    connection->state = 5;
    ghiCallProgressCallback(connection, 0, 0);
}

/*
 * function: func_021C5430
 * address:  0x021C5430
 * packet:   pkt_ov114_021C5430
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoReceivingFile (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_021C04D4  0x021C04D4  arm  ov114
 *   func_021C4E68  0x021C4E68  arm  ov114
 *   func_021BFCEC  0x021BFCEC  arm  ov114
 *   func_021C0378  0x021C0378  arm  ov114
 *   func_021C4C50  0x021C4C50  arm  ov114
 *   g_021CF310     0x021CF310  data
 *   g_021CF320     0x021CF320  data
 */

typedef struct {
    void *connection;
    char *data;
    int size;
    int len;
    int pos;
    char pad14[0x10];
} GHIBuffer;

typedef struct {
    char pad000[0x40];
    int result;                 /* 0x040 */
    char pad044[0x5C];
    GHIBuffer recvBuffer;       /* 0x0A0 */
    GHIBuffer decodeBuffer;     /* 0x0C4 */
    char pad0E8[0x3C];
    int completed;              /* 0x124 */
    int fileBytesReceived;      /* 0x128 */
    int totalSize;              /* 0x12C */
    char pad130[0x58];
    unsigned int maxRecvTime;   /* 0x188 */
    char pad18C[0x0C];
    void *encryptEngine;        /* 0x198 */
    char pad19C[0x0C];
    int sessionEstablished;     /* 0x1A8 */
    char pad1AC[0x24];
    unsigned int lastReceiveTime; /* 0x1D0 */
} GHIConnection;

extern unsigned int func_0217F264(void);
extern void *func_0217EAB0(unsigned long size);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_021C04D4(GHIConnection *connection, char *buffer, int *bufferLen);
extern void func_021C4E68(int a);
extern int func_021BFCEC(GHIBuffer *buffer, char *data, int dataLen);
extern int func_021C0378(GHIConnection *connection);
extern int func_021C4C50(GHIConnection *connection, char *data, int len);
extern char g_021CF310[];
extern char g_021CF320[];

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
            if (connection->lastReceiveTime == 0)
            {
                connection->lastReceiveTime = func_0217F264();
                return;
            }
            if (func_0217F264() - connection->lastReceiveTime < 30000)
                return;
            func_0217D254(8, 0, 1, g_021CF320, func_0217F264() - connection->lastReceiveTime);
            connection->lastReceiveTime = 0;
            connection->completed = 1;
            connection->result = 0x13;
            return;
        }
        connection->lastReceiveTime = 0;

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

        if (connection->encryptEngine != 0 && connection->sessionEstablished == 1)
        {
            if (!func_021BFCEC(&connection->decodeBuffer, buffer, bufferLen))
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

/*
 * function: ghiDoReceivingFile
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
 *   current_time  0x0217F264  arm  ov009
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   ghiDoReceive  0x021C04D4  arm  ov114
 *   ghiFreeTempBuffer  0x021C4E68  arm  ov114
 *   ghiAppendDataToBuffer  0x021BFCEC  arm  ov114
 *   ghiDecryptReceivedData  0x021C0378  arm  ov114
 *   ghiProcessIncomingFileData  0x021C4C50  arm  ov114
 *   sGhttpReceivingFile     0x021CF310  data
 *   sGhttpReceiveFileIdleTimeout     0x021CF320  data
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

extern unsigned int current_time(void);
extern void *gsimalloc(unsigned long size);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
struct GHIBuffer;
struct GHIConnection;
extern int ghiDoReceive(struct GHIConnection *connection, char *buffer, int *bufferLen);
extern void ghiFreeTempBuffer(int a);
extern int ghiAppendDataToBuffer(struct GHIBuffer *buffer, char *data, int dataLen);
extern int ghiDecryptReceivedData(struct GHIConnection *connection);
extern int ghiProcessIncomingFileData(struct GHIConnection *connection, char *data, int len);
extern char sGhttpReceivingFile[];
extern char sGhttpReceiveFileIdleTimeout[];

void ghiDoReceivingFile(GHIConnection *connection)
{
    int result;
    unsigned int start_time;
    unsigned int running_time;
    int bufferLen;
    char *buffer;
    int decryptedLen;

    start_time = current_time();
    running_time = 0;
    bufferLen = 0;

    buffer = gsimalloc(0x2000);
    if (buffer == 0)
    {
        connection->completed = 1;
        connection->result = 1;
        return;
    }

    gsDebugFormat(8, (char *)3, 0x10, sGhttpReceivingFile);

    while (!connection->completed && running_time < connection->maxRecvTime)
    {
        bufferLen = 0x2000;
        result = ghiDoReceive((struct GHIConnection *)connection, buffer, &bufferLen);
        if (result == 1)
        {
            ghiFreeTempBuffer((int)buffer);
            if (connection->lastReceiveTime == 0)
            {
                connection->lastReceiveTime = current_time();
                return;
            }
            if (current_time() - connection->lastReceiveTime < 30000)
                return;
            gsDebugFormat(8, 0, 1, sGhttpReceiveFileIdleTimeout, current_time() - connection->lastReceiveTime);
            connection->lastReceiveTime = 0;
            connection->completed = 1;
            connection->result = 0x13;
            return;
        }
        connection->lastReceiveTime = 0;

        if (result == 3)
        {
            ghiFreeTempBuffer((int)buffer);
            return;
        }
        if (result == 2)
        {
            connection->completed = 1;
            if (connection->totalSize > 0 && connection->fileBytesReceived < connection->totalSize)
                connection->result = 0xF;
            ghiFreeTempBuffer((int)buffer);
            return;
        }

        if (connection->encryptEngine != 0 && connection->sessionEstablished == 1)
        {
            if (!ghiAppendDataToBuffer((struct GHIBuffer *)(&connection->decodeBuffer), buffer, bufferLen))
            {
                ghiFreeTempBuffer((int)buffer);
                return;
            }
            connection->recvBuffer.len = connection->recvBuffer.pos;
            if (!ghiDecryptReceivedData((struct GHIConnection *)connection))
            {
                connection->completed = 1;
                connection->result = 0x11;
                ghiFreeTempBuffer((int)buffer);
                return;
            }
            decryptedLen = connection->recvBuffer.len - connection->recvBuffer.pos;
            if (decryptedLen != 0)
            {
                if (!ghiProcessIncomingFileData((struct GHIConnection *)connection, connection->recvBuffer.data + connection->recvBuffer.pos, decryptedLen))
                {
                    ghiFreeTempBuffer((int)buffer);
                    return;
                }
            }
        }
        else
        {
            if (!ghiProcessIncomingFileData((struct GHIConnection *)connection, buffer, bufferLen))
            {
                ghiFreeTempBuffer((int)buffer);
                return;
            }
        }

        running_time = current_time() - start_time;
    }

    ghiFreeTempBuffer((int)buffer);
}

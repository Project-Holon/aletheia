/*
 * function: ghiDoReceivingStatus
 * address:  0x021C492C
 * packet:   pkt_ov114_021C492C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoReceivingStatus (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   ghiDoReceive  0x021C04D4  arm  ov114
 *   ghiAppendDataToBuffer  0x021BFCEC  arm  ov114
 *   ghiDecryptReceivedData  0x021C0378  arm  ov114
 *   func_02094B20  0x02094B20  arm
 *   ghiParseStatus  0x021C4830  arm  ov114
 *   ghiResetBuffer  0x021C00FC  arm  ov114
 *   ghiCallProgressCallback  0x021C02C8  arm  ov114
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   sGhttpReceivingStatus     0x021CF220  data
 *   sGhttpLineEndProcess     0x021CF194  data
 *   sGhttpGotHttpContinue     0x021CF234  data
 */

typedef struct {
    int size;
    char *data;
    char pad08[0x1C];
} GHIBuffer;

typedef struct {
    char pad000[0x10];
    int state;                  /* 0x010 */
    char pad014[0x2C];
    int result;                 /* 0x040 */
    char pad044[0x0C];
    int socket;                 /* 0x050 */
    int socketError;            /* 0x054 */
    char pad058[0x48];
    GHIBuffer recvBuffer;       /* 0x0A0 */
    GHIBuffer decodeBuffer;     /* 0x0C4 */
    char pad0E8[0x30];
    int statusCode;             /* 0x118 */
    char pad11C[0x04];
    int headerStringIndex;      /* 0x120 */
    int completed;              /* 0x124 */
    char pad128[0x58];
    int waitingForContinue;     /* 0x180 */
    char pad184[0x14];
    void *encryptEngine;        /* 0x198 */
    char pad19C[0x0C];
    int sessionEstablished;     /* 0x1A8 */
} GHIConnection;

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
struct GHIBuffer;
struct GHIConnection;
extern int ghiDoReceive(struct GHIConnection *connection, char *buffer, int *bufferLen);
extern int ghiAppendDataToBuffer(struct GHIBuffer *buffer, char *data, int dataLen);
extern int ghiDecryptReceivedData(struct GHIConnection *connection);
extern char *func_02094B20(const char *s, const char *find);
extern int ghiParseStatus(struct GHIConnection *connection);
extern void ghiResetBuffer(GHIBuffer *buffer);
extern void ghiCallProgressCallback(struct GHIConnection *connection, char *buffer, int bufferLen);
extern int func_0217ED54(int socket);
extern char sGhttpReceivingStatus[];
extern char sGhttpLineEndProcess[];
extern char sGhttpGotHttpContinue[];

void ghiDoReceivingStatus(GHIConnection *connection)
{
    char buffer[1024];
    int bufferLen;
    int result;
    char *endOfStatus;
    int statusLength;

    func_0217D254(8, (char *)3, 0x10, sGhttpReceivingStatus);

    bufferLen = sizeof(buffer);
    result = ghiDoReceive((struct GHIConnection *)connection, buffer, &bufferLen);
    if (result == 3 || result == 1)
        return;

    if (result == 0)
    {
        if (connection->encryptEngine != 0 && connection->sessionEstablished == 1)
        {
            if (!ghiAppendDataToBuffer((struct GHIBuffer *)(&connection->decodeBuffer), buffer, bufferLen))
                return;
            if (!ghiDecryptReceivedData((struct GHIConnection *)connection))
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
        }
        else
        {
            if (!ghiAppendDataToBuffer((struct GHIBuffer *)(&connection->recvBuffer), buffer, bufferLen))
                return;
        }
    }

    endOfStatus = func_02094B20(connection->recvBuffer.data, sGhttpLineEndProcess);
    if (endOfStatus != 0)
    {
        *endOfStatus = '\0';
        statusLength = endOfStatus - connection->recvBuffer.data;

        if (!ghiParseStatus((struct GHIConnection *)connection))
            return;

        connection->headerStringIndex = statusLength + 2;

        if (connection->statusCode == 100 && connection->waitingForContinue)
        {
            connection->waitingForContinue = 0;
            ghiResetBuffer(&connection->recvBuffer);
            connection->state = 6;
            ghiCallProgressCallback((struct GHIConnection *)connection, 0, 0);
            func_0217D254(8, 0, 0x10, sGhttpGotHttpContinue);
        }
        else
        {
            connection->state = 9;
            ghiCallProgressCallback((struct GHIConnection *)connection, 0, 0);
        }
    }
    else if (result == 2)
    {
        connection->completed = 1;
        connection->result = 7;
        connection->socketError = func_0217ED54(connection->socket);
    }
}

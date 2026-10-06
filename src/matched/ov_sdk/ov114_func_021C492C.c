/*
 * function: func_021C492C
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
 *   func_021C04D4  0x021C04D4  arm  ov114
 *   func_021BFCEC  0x021BFCEC  arm  ov114
 *   func_021C0378  0x021C0378  arm  ov114
 *   func_02094B20  0x02094B20  arm
 *   func_021C4830  0x021C4830  arm  ov114
 *   func_021C00FC  0x021C00FC  arm  ov114
 *   func_021C02C8  0x021C02C8  arm  ov114
 *   func_0217ED54  0x0217ED54  arm  ov009
 *   g_021CF220     0x021CF220  data
 *   g_021CF194     0x021CF194  data
 *   g_021CF234     0x021CF234  data
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
extern int func_021C04D4(struct GHIConnection *connection, char *buffer, int *bufferLen);
extern int func_021BFCEC(struct GHIBuffer *buffer, char *data, int dataLen);
extern int func_021C0378(struct GHIConnection *connection);
extern char *func_02094B20(const char *s, const char *find);
extern int func_021C4830(struct GHIConnection *connection);
extern void func_021C00FC(GHIBuffer *buffer);
extern void func_021C02C8(struct GHIConnection *connection, char *buffer, int bufferLen);
extern int func_0217ED54(int socket);
extern char g_021CF220[];
extern char g_021CF194[];
extern char g_021CF234[];

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
        if (connection->encryptEngine != 0 && connection->sessionEstablished == 1)
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

        if (!func_021C4830((struct GHIConnection *)connection))
            return;

        connection->headerStringIndex = statusLength + 2;

        if (connection->statusCode == 100 && connection->waitingForContinue)
        {
            connection->waitingForContinue = 0;
            func_021C00FC(&connection->recvBuffer);
            connection->state = 6;
            func_021C02C8((struct GHIConnection *)connection, 0, 0);
            func_0217D254(8, 0, 0x10, g_021CF234);
        }
        else
        {
            connection->state = 9;
            func_021C02C8((struct GHIConnection *)connection, 0, 0);
        }
    }
    else if (result == 2)
    {
        connection->completed = 1;
        connection->result = 7;
        connection->socketError = func_0217ED54(connection->socket);
    }
}

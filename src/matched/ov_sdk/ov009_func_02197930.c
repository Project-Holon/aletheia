/*
 * function: func_02197930
 * address:  0x02197930
 * packet:   pkt_ov009_02197930
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SendAppUnreliable (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   memcmp                    0x020923F0  arm
 *   gti2ConnectionSendData    0x02195750  arm  ov009
 *   gti2GetBufferFreeSpace    0x02194DD4  arm  ov009
 *   gti2BufferWriteData       0x02194E2C  arm  ov009
 *   gti2BufferShorten         0x02194E80  arm  ov009
 *   g_021A5948                0x021A5948  data
 */

typedef unsigned char u8;

typedef struct GTI2Socket
{
    char pad0[0x40];
    int magicType;
    int magicOffset;
} GTI2Socket;

typedef struct GTI2Connection
{
    char pad0[8];
    GTI2Socket *socket;
    char pad1[0x44];
    u8 *outData;
    int outSize;
    int outPos;
} GTI2Connection;

extern int memcmp();
extern int gti2ConnectionSendData();
extern int gti2GetBufferFreeSpace();
extern void gti2BufferWriteData();
extern void gti2BufferShorten();
extern u8 g_021A5948[];

int func_02197930(GTI2Connection *connection, u8 *message, int len)
{
    u8 *start;
    int totalLen;
    int freeSpace;

    if (len < 2 || memcmp(message + connection->socket->magicOffset, g_021A5948, 2) != 0)
    {
        if (!gti2ConnectionSendData(connection, message, len))
            return 0;
        return 1;
    }
    totalLen = len + 2;
    freeSpace = gti2GetBufferFreeSpace(&connection->outData);
    if (freeSpace < totalLen)
        return 1;
    start = connection->outData + connection->outPos;
    if (connection->socket->magicType == 2)
        gti2BufferWriteData(&connection->outData, message, 2);
    gti2BufferWriteData(&connection->outData, g_021A5948, 2);
    gti2BufferWriteData(&connection->outData, message + connection->socket->magicOffset, len - connection->socket->magicOffset);
    if (!gti2ConnectionSendData(connection, start, totalLen))
        return 0;
    gti2BufferShorten(&connection->outData, -1, totalLen);
    return 1;
}

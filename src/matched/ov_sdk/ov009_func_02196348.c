/*
 * function: func_02196348
 * address:  0x02196348
 * packet:   pkt_ov009_02196348
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleClientResponse (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   gti2ConnectionCommunicationError  0x02195F5C  arm  ov009
 *   gti2CheckResponse                 0x02194D74  arm  ov009
 *   gti2SendClosed                    0x02197BB8  arm  ov009
 *   gti2ConnectionClosed              0x021959D0  arm  ov009
 *   current_time                      0x0217F264  arm  ov009
 *   gti2ConnectAttemptCallback        0x02194F2C  arm  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct GTI2Socket
{
    char pad0[0x20];
    int flag;
} GTI2Socket;

typedef struct GTI2Connection
{
    u32 ip;
    u16 port;
    GTI2Socket *socket;
    int state;
    char pad0[0x58];
    u8 response[0x24];
    u32 startTime;
} GTI2Connection;

extern int gti2ConnectionCommunicationError();
extern int gti2CheckResponse();
extern int gti2SendClosed();
extern void gti2ConnectionClosed();
extern u32 current_time(void);
extern int gti2ConnectAttemptCallback();

int func_02196348(GTI2Connection *connection, u8 *message, int len)
{
    int latency;

    if (connection->state != 3)
        return gti2ConnectionCommunicationError(connection) != 0;
    if (len < 32)
        return gti2ConnectionCommunicationError(connection) != 0;
    if (!gti2CheckResponse(message, connection->response))
        return gti2ConnectionCommunicationError(connection) != 0;
    if (connection->socket->flag == 0)
    {
        if (!gti2SendClosed(connection))
            return 0;
        gti2ConnectionClosed(connection);
        return 1;
    }
    connection->state = 4;
    latency = current_time() - connection->startTime;
    return gti2ConnectAttemptCallback(connection->socket, connection, connection->ip, connection->port, latency, message + 32, len - 32) != 0;
}

/*
 * function: gti2HandleConnectionReset
 * address:  0x021970BC
 * packet:   pkt_ov009_021970BC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleConnectionReset (libdwcgsgt2.TWL.HYB.a(gt2message.o))
 *
 * symbols:
 *   gti2SocketFindConnection  0x02197D5C  arm  ov009
 *   gti2DumpCallback          0x02195408  arm  ov009
 *   current_time              0x0217F264  arm  ov009
 *   gti2ConnectionError       0x02195EC4  arm  ov009
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct GTI2Connection
{
    char pad0[0xC];
    int state;
    char pad1[0xC];
    u32 startTime;
    u32 timeout;
} GTI2Connection;

typedef struct GTI2Socket
{
    char pad0[0x2C];
    void *callback;
} GTI2Socket;

extern GTI2Connection *gti2SocketFindConnection();
extern int gti2DumpCallback();
extern u32 current_time(void);
extern int gti2ConnectionError();

int gti2HandleConnectionReset(GTI2Socket *socket, u32 ip, u16 port)
{
    GTI2Connection *connection;

    connection = gti2SocketFindConnection(socket, ip, port);
    if (socket->callback)
    {
        if (!gti2DumpCallback(socket, connection, ip, port, 1, 0, 0, 0))
            return 0;
    }
    if (!connection)
        return 1;
    if (connection->state == 0)
    {
        if (!connection->timeout || current_time() - connection->startTime < connection->timeout)
            return 1;
        if (!gti2ConnectionError(connection, 6, 1))
            return 0;
    }
    else
    {
        if (!gti2ConnectionError(connection, 2, 1))
            return 0;
    }
    return 1;
}

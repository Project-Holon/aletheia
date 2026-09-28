/*
 * function: gti2ConnectionSendData
 * address:  0x02195750
 * packet:   pkt_ov009_02195750
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2ConnectionSendData (gt2connection.o)
 *
 * symbols:
 *   gti2SocketSend  0x02198328 arm
 *   current_time    0x0217F264 arm
 */

struct GTI2Socket;
struct GTI2Connection;

extern int gti2SocketSend(struct GTI2Socket *socket, unsigned int ip,
                          unsigned short port, unsigned char *message, int len);
extern unsigned int current_time(void);

struct GTI2Connection {
    unsigned int ip;
    unsigned short port;
    char pad06[2];
    struct GTI2Socket *socket;
    int state;
    int field_10;
    int field_14;
    char pad18[0x10];
    char callbacks[0x10];
    char pad38[0x28];
    void *outgoingBuffers;
    char pad64[0x24];
    unsigned int lastSend;
};

int gti2ConnectionSendData(struct GTI2Connection *connection,
                           unsigned char *message, int len)
{
    if (gti2SocketSend(connection->socket, connection->ip, connection->port,
                       message, len) == 0)
        return 0;
    connection->lastSend = current_time();
    return 1;
}

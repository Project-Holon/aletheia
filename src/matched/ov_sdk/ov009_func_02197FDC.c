/*
 * function: gti2CloseSocket
 * address:  0x02197FDC
 * packet:   pkt_ov009_02197FDC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2CloseSocket (gt2socket.o)
 *
 * symbols:
 *   closesocket     0x0217EB2C  arm  ov009
 *   TableFree       0x021846B4  arm  ov009
 *   ArrayFree       0x021841B0  arm  ov009
 *   gsifree         0x0217EAE0  arm  ov009
 *   SocketShutDown  0x0217F260  arm  ov009
 */

struct DArrayImplementation;
struct HashImplementation;

struct GTI2Socket {
    int socket;
    unsigned int ip;
    unsigned short port;
    struct HashImplementation *connections;
    struct DArrayImplementation *closedConnections;
    int close;
    int error;
    int callbackLevel;
};

extern int closesocket(int sock);
extern void TableFree(struct HashImplementation *table);
extern void ArrayFree(struct DArrayImplementation *array);
extern void gsifree(void *ptr);
extern void SocketShutDown(void);

void gti2CloseSocket(struct GTI2Socket *socket)
{
    if (socket->callbackLevel != 0)
    {
        socket->close = 1;
        return;
    }
    closesocket(socket->socket);
    TableFree(socket->connections);
    ArrayFree(socket->closedConnections);
    gsifree(socket);
    SocketShutDown();
}

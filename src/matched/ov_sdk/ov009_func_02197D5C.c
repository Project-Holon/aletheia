/*
 * function: gti2SocketFindConnection
 * address:  0x02197D5C
 * packet:   pkt_ov009_02197D5C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SocketFindConnection (gt2socket.o)
 *
 * symbols:
 *   TableLookup  0x0218482C  arm  ov009
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct GTI2Connection {
    u32 ip;
    u16 port;
    char _pad[0xa0 - 6];
};

struct GTI2Socket {
    char _pad0[0xc];
    struct HashImplementation *connections;
};

extern void *TableLookup(struct HashImplementation *table, void *elemKey);

struct GTI2Connection *gti2SocketFindConnection(struct GTI2Socket *socket,
                                                u32 ip, u16 port)
{
    struct GTI2Connection connection;
    struct GTI2Connection *connectionPtr;
    struct GTI2Connection **result;

    connection.ip = ip;
    connection.port = port;
    connectionPtr = &connection;
    result = (struct GTI2Connection **)TableLookup(socket->connections,
                                                   &connectionPtr);
    if (result != 0)
        return *result;
    return 0;
}
